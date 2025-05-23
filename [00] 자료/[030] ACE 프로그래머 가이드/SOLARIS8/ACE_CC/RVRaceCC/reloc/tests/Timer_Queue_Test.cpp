// Timer_Queue_Test.cpp,v 4.62 2002/12/18 14:27:27 seibel_r Exp

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Timer_Queue_Test.cpp
//
// = DESCRIPTION
//      This is a simple test of <ACE_Timer_Queue> and four of its
//      subclasses (<ACE_Timer_List>, <ACE_Timer_Heap>,
//      <ACE_Timer_Wheel>, and <ACE_Timer_Hash>).  The test sets up a
//      bunch of timers and then adds them to a timer queue. The
//      functionality of the timer queue is then tested. No command
//      line arguments are needed to run the test.
//
// = AUTHORS
//    Douglas C. Schmidt <schmidt@cs.wustl.edu>,
//    Prashant Jain <pjain@cs.wustl.edu>, and
//    Darrell Brunsch <brunsch@cs.wustl.edu>
//
// ============================================================================

#include "test_config.h"
#include "ace/Profile_Timer.h"
#include "ace/Timer_Queue.h"
#include "ace/Timer_List.h"
#include "ace/Timer_Heap.h"
#include "ace/Timer_Wheel.h"
#include "ace/Timer_Hash.h"
#include "ace/Timer_Queue.h"

ACE_RCSID(tests, Timer_Queue_Test, "Timer_Queue_Test.cpp,v 4.62 2002/12/18 14:27:27 seibel_r Exp")

static void
randomize_array (ACE_Time_Value array[], int size)
{
  for (int i = 0; i < size; ++i)
    {
      int index = ACE_OS::rand() % size--;
      ACE_Time_Value temp = array [index];
      array [index] = array [size];
      array [size] = temp;
    }
}

// Number of iterations for the performance tests.  Some platforms
// have a very high ACE_DEFAULT_TIMERS (HP-UX is 400), so limit this
// to a reasonable run time.
#if (ACE_DEFAULT_TIMERS > 20)
static int max_iterations = 2000;
#else
static int max_iterations = ACE_DEFAULT_TIMERS * 100;
#endif

// Amount of time between each timer. 
// (0 schedules all the timers to expire at exactly the same time.)
// in milliseconds
static int TIMER_DISTANCE = 50;

// Array of timer ids assigned to us that we need to keep track of.
static long *timer_ids = 0;

class Example_Handler : public ACE_Event_Handler
{
public:
  Example_Handler (void): close_count_ (0) {}

  virtual int handle_close (ACE_HANDLE, ACE_Reactor_Mask mask)
  {
    ACE_ASSERT (mask == ACE_Event_Handler::TIMER_MASK);
    this->close_count_++;
    return 0;
  }

  virtual int handle_timeout (const ACE_Time_Value &, 
                              const void *arg)
  {
    int *act = (int *) arg;
    ACE_ASSERT (*act == 42 || *act == 007);
    int result = 0;

    if (*act == 007)
      result = -1; // This is the special value to trigger a handle_close

    delete act;
    return result;
  }

  int close_count_;
  // Keeps track of the number of times that <handle_close> is called.
};

static void
test_functionality (ACE_Timer_Queue *tq)
{
  Example_Handler eh;

  ACE_ASSERT (tq->is_empty () != 0);
  ACE_ASSERT (ACE_Time_Value::zero == ACE_Time_Value (0));
  long timer_id;
  long timer_id2;

  // Do a test on earliest_time.
  ACE_Time_Value earliest_time = tq->gettimeofday ();

  const void *timer_act = 0;
  ACE_NEW (timer_act, int (1));
  timer_id = tq->schedule (&eh, timer_act, earliest_time);

  ACE_OS::sleep (ACE_Time_Value (0, 10));

  ACE_NEW (timer_act, int (1));
  timer_id2 = tq->schedule (&eh, timer_act, tq->gettimeofday ());

  long result = tq->earliest_time () == earliest_time;
  ACE_ASSERT (result != 0);

  tq->cancel (timer_id, &timer_act);
  delete (int *) timer_act;
  tq->cancel (timer_id2, &timer_act);
  delete (int *) timer_act;

  ACE_ASSERT (tq->is_empty () == 1);
  ACE_ASSERT (eh.close_count_ == 0);

  ACE_NEW (timer_act, int (1));
  timer_id = tq->schedule (&eh,
                           timer_act,
                           tq->gettimeofday ());
  ACE_ASSERT (timer_id != -1);
  ACE_ASSERT (tq->is_empty () == 0); //==

  ACE_NEW (timer_act, int (42));
  result = tq->schedule (&eh,
                         timer_act,
                         tq->gettimeofday ());
  ACE_ASSERT (result != -1);
  ACE_ASSERT (tq->is_empty () == 0); //==

  ACE_NEW (timer_act, int (42));
  result = tq->schedule (&eh,
                         timer_act,
                         tq->gettimeofday ());
  ACE_ASSERT (result != -1);
  ACE_ASSERT (tq->is_empty () == 0); //==

  // The following method will trigger a call to <handle_close>.
  ACE_ASSERT (eh.close_count_ == 0);
  result = tq->cancel (timer_id, &timer_act, 0);
  ACE_ASSERT (result == 1);
  delete (int *) timer_act;

  ACE_ASSERT (tq->is_empty () == 0);
  ACE_ASSERT (eh.close_count_ == 1);

  result = tq->expire ();
  ACE_ASSERT (result == 2);

  ACE_NEW (timer_act, int (007));
  result = tq->schedule (&eh,
                         timer_act,
                         tq->gettimeofday ());
  ACE_ASSERT (result != -1);

  ACE_NEW (timer_act, int (42));
  result = tq->schedule (&eh,
                         timer_act,
                         tq->gettimeofday () + ACE_Time_Value (100));
  ACE_ASSERT (result != -1);

  ACE_NEW (timer_act, int (42));
  result = tq->schedule (&eh,
                         timer_act,
                         tq->gettimeofday () + ACE_Time_Value (100));
  ACE_ASSERT (result != -1);

  // The following will trigger a call to <handle_close> when it
  // cancels the second timer.  This happens because the first timer
  // has an <act> of 007, which causes eh.handle_timeout () to return
  // -1.  Since -1 is returned, all timers that use <eh> will be
  // cancelled (and <handle_close> will only be called on the first
  // timer that is cancelled).
  ACE_ASSERT (eh.close_count_ == 1);

  result = tq->expire ();
  ACE_ASSERT (result == 1);
  ACE_ASSERT (eh.close_count_ == 2);

  ACE_ASSERT (tq->is_empty () != 0);

  ACE_NEW (timer_act, int (4));
  timer_id = tq->schedule (&eh,
                           timer_act,
                           tq->gettimeofday ());
  ACE_ASSERT (timer_id != -1);

  ACE_NEW (timer_act, int (4));
  timer_id2 = tq->schedule (&eh,
                            timer_act,
                            tq->gettimeofday ());
  ACE_ASSERT (timer_id2 != -1);

  // The following method will trigger a call to <handle_close>.
  ACE_ASSERT (eh.close_count_ == 2);
  result = tq->cancel (timer_id, &timer_act);
  ACE_ASSERT (result != -1);
  delete (int *) timer_act;

  result = tq->cancel (timer_id2, &timer_act);
  ACE_ASSERT (result != -1);
  delete (int *) timer_act;

  ACE_ASSERT (eh.close_count_ == 2); // Only one call to handle_close() even though two timers
  ACE_ASSERT (tq->is_empty () != 0);

  result = tq->expire ();
  ACE_ASSERT (result == 0);

  // This tests to make sure that <handle_close> is called when there
  // is only one timer of the type in the queue
  ACE_ASSERT (eh.close_count_ == 2);

  ACE_NEW (timer_act, int (007));
  result = tq->schedule (&eh,
                         timer_act,
                         tq->gettimeofday ());
  ACE_ASSERT (result != -1);

  result = tq->expire ();
  ACE_ASSERT (result == 1);
  ACE_ASSERT (eh.close_count_ == 3);

  ACE_NEW (timer_act, int (6));
  timer_id = tq->schedule (&eh,
                           timer_act,
                           tq->gettimeofday ());
  ACE_ASSERT (timer_id != -1);

  ACE_NEW (timer_act, int (7));
  timer_id2 = tq->schedule (&eh,
                            timer_act,
                            tq->gettimeofday ());
  ACE_ASSERT (timer_id2 != -1);

  ACE_ASSERT (eh.close_count_ == 3);

  result = tq->cancel (timer_id, &timer_act);
  delete (int *) timer_act;
  ACE_ASSERT (result == 1);
  ACE_ASSERT (eh.close_count_ == 3);

  result = tq->cancel (timer_id2, &timer_act);
  delete (int *) timer_act;
  ACE_ASSERT (result == 1);
  ACE_ASSERT (eh.close_count_ == 3);

  result = tq->expire ();
  ACE_ASSERT (result == 0);
  ACE_ASSERT (eh.close_count_ == 3);
}

static void
test_performance (ACE_Timer_Queue *tq,
                  const ACE_TCHAR *test_name)
{
  Example_Handler eh;
  ACE_Profile_Timer timer;
  int i;
  const void *timer_act = 0;

  ACE_ASSERT (tq->is_empty () != 0);
  ACE_ASSERT (ACE_Time_Value::zero == ACE_Time_Value (0));

  // Test the amount of time required to schedule all the timers.

  ACE_Time_Value *times = 0;
  ACE_NEW (times, ACE_Time_Value[max_iterations]);

  // Set up a bunch of times TIMER_DISTANCE ms apart.
  for (i = 0; i < max_iterations; i++)
    times[i] = tq->gettimeofday() + ACE_Time_Value(0, i * TIMER_DISTANCE * 1000);

  ACE_Time_Value last_time = times[max_iterations-1];

  timer.start ();

  for (i = 0; i < max_iterations; i++)
    {
      ACE_NEW (timer_act, int (42));
      timer_ids[i] = tq->schedule (&eh,
                                   timer_act,
                                   times[i]);
      ACE_ASSERT (timer_ids[i] != -1);
    }

  ACE_ASSERT (tq->is_empty () == 0);

  timer.stop ();

  ACE_Profile_Timer::ACE_Elapsed_Time et;

  timer.elapsed_time (et);

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time to schedule %d timers for %s\n"),
              max_iterations, test_name));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("real time = %f secs, user time = %f secs, system time = %f secs\n"),
              et.real_time, et.user_time, et.system_time));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time per call = %f usecs\n"),
              (et.user_time / ACE_timer_t (max_iterations)) * 1000000));

  // Test the amount of time required to cancel all the timers.

  timer.start ();

  for (i = max_iterations - 1; i >= 0; i--)
    {
      tq->cancel (timer_ids[i], &timer_act);
      delete (int *) timer_act;
    }

  timer.stop ();

  ACE_ASSERT (tq->is_empty () != 0);

  timer.elapsed_time (et);

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time to cancel %d timers for %s\n"),
              max_iterations, test_name));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("real time = %f secs, user time = %f secs, system time = %f secs\n"),
              et.real_time, et.user_time, et.system_time));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time per call = %f usecs\n"),
              (et.user_time / ACE_timer_t (max_iterations)) * 1000000));

  // Test the amount of time required to schedule and expire all the
  // timers.

  timer.start ();

  for (i = 0; i < max_iterations; i++)
    {
      ACE_NEW (timer_act, int (42));
      long result = tq->schedule (&eh, timer_act, times[i]);
      ACE_ASSERT (result != -1);
    }

  ACE_ASSERT (tq->is_empty () == 0);

  // Expire all the timers.
  tq->expire (last_time + ACE_Time_Value(1));

  timer.stop ();

  ACE_ASSERT (tq->is_empty () != 0);

  timer.elapsed_time (et);

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time to schedule and expire %d timers for %s\n"),
              max_iterations, test_name));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("real time = %f secs, user time = %f secs, system time = %f secs\n"),
              et.real_time, et.user_time, et.system_time));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time per call = %f usecs\n"),
              (et.user_time / ACE_timer_t (max_iterations)) * 1000000));

  randomize_array (times, max_iterations);

  // Test the amount of time required to randomly cancel all the
  // timers.

  for (i = 0; i < max_iterations; i++)
    {
      ACE_NEW (timer_act, int (42));
      timer_ids[i] = tq->schedule (&eh,
                                   timer_act,
                                   times[i]);
      ACE_ASSERT (timer_ids[i] != -1);
    }

  ACE_ASSERT (tq->is_empty () == 0);

  timer.start ();

  for (i = max_iterations - 1; i >= 0; i--)
    {
      tq->cancel (timer_ids[i], &timer_act);
      delete (int *) timer_act;
    }

  ACE_ASSERT (tq->is_empty () != 0);

  timer.stop ();

  timer.elapsed_time (et);

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time to randomly cancel %d timers for %s\n"),
              max_iterations,
              test_name));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("real time = %f secs, user time = %f secs, system time = %f secs\n"),
              et.real_time,
              et.user_time,
              et.system_time));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time per call = %f usecs\n"),
              (et.user_time / ACE_timer_t (max_iterations)) * 1000000));

  // Test the amount of time required to randomly schedule all the timers.

  timer.start ();

  for (i = 0; i < max_iterations; i++)
    {
      ACE_NEW (timer_act, int (42));
      timer_ids[i] = tq->schedule (&eh,
                                   timer_act,
                                   times[i]);
      ACE_ASSERT (timer_ids[i] != -1);
    }

  timer.stop ();

  ACE_ASSERT (tq->is_empty () == 0);

  timer.elapsed_time (et);

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time to randomly schedule %d timers for %s\n"),
              max_iterations, test_name));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("real time = %f secs, user time = %f secs, system time = %f secs\n"),
              et.real_time,
              et.user_time,
              et.system_time));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time per call = %f usecs\n"),
              (et.user_time / ACE_timer_t (max_iterations)) * 1000000));

  // Test the amount of time required to expire all the timers.

  timer.start ();

  tq->expire (last_time + ACE_Time_Value(1));

  ACE_ASSERT (tq->is_empty ());

  timer.stop ();

  timer.elapsed_time (et);

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time to expire %d randomly scheduled timers for %s\n"),
              max_iterations, test_name));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("real time = %f secs, user time = %f secs, system time = %f secs\n"),
              et.real_time, et.user_time, et.system_time));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("time per call = %f usecs\n"),
              (et.user_time / ACE_timer_t (max_iterations)) * 1000000));

  delete [] times;
}

class Timer_Queue_Stack
{
  // = TITLE
  //   Keeps track of the <Timer_Queue>s that we're going to test.
  //
  // = DESCRIPTION
  //   This data structure is organized as a stack to make it easy to implement.
public:
  // = Initialization method
  Timer_Queue_Stack (ACE_Timer_Queue *queue,
    const ACE_TCHAR *name,
    Timer_Queue_Stack *next = NULL)
    : queue_ (queue),
    name_ (name),
    next_ (next)
  {}
  // "Push" a new <queue> on the stack of <queue>s.

  ACE_Timer_Queue *queue_;
  // Pointer to the subclass of <ACE_Timer_Queue> that we're testing.

  const ACE_TCHAR *name_;
  // Name of the Queue that we're testing.

  Timer_Queue_Stack *next_;
  // Pointer to the next <Timer_Queue>.
};

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_START_TEST (ACE_TEXT ("Timer_Queue_Test"));

  ACE_OS::srand (ACE_OS::time (0L));

  if (argc > 1)
    max_iterations = ACE_OS::atoi (argv[1]);

  // = Perform initializations.

  Timer_Queue_Stack *tq_stack = NULL;

  // Add new Timer_Queue implementations here.  Note that these will
  // be executed in "reverse order".

  // Timer_Hash (Heap)
  ACE_NEW_RETURN (tq_stack,
                  Timer_Queue_Stack (new ACE_Timer_Hash_Heap,
                                     ACE_TEXT ("ACE_Timer_Hash (Heap)"),
                                     tq_stack),
                  -1);

  // Timer_Hash
  ACE_NEW_RETURN (tq_stack,
                  Timer_Queue_Stack (new ACE_Timer_Hash,
                                     ACE_TEXT ("ACE_Timer_Hash"),
                                     tq_stack),
                  -1);

  // Timer_stack
  ACE_NEW_RETURN (tq_stack,
                  Timer_Queue_Stack (new ACE_Timer_List,
                                     ACE_TEXT ("ACE_Timer_List"),
                                     tq_stack),
                  -1);

  // Timer_Wheel without preallocated memory
  ACE_NEW_RETURN (tq_stack,
                  Timer_Queue_Stack (new ACE_Timer_Wheel,
                                     ACE_TEXT ("ACE_Timer_Wheel (non-preallocated)"),
                                     tq_stack),
                  -1);

  // Timer_Wheel with preallocated memory.
  ACE_NEW_RETURN (tq_stack,
                  Timer_Queue_Stack (new ACE_Timer_Wheel (ACE_DEFAULT_TIMER_WHEEL_SIZE,
                                                          ACE_DEFAULT_TIMER_WHEEL_RESOLUTION,
                                                          max_iterations),
                                     ACE_TEXT ("ACE_Timer_Wheel (preallocated)"),
                                     tq_stack),
                  -1);
  // Timer_Heap without preallocated memory.
  ACE_NEW_RETURN (tq_stack,
                  Timer_Queue_Stack (new ACE_Timer_Heap,
                                     ACE_TEXT ("ACE_Timer_Heap (non-preallocated)"),
                                     tq_stack),
                  -1);

  // Timer_Heap with preallocate memory.
  ACE_NEW_RETURN (tq_stack,
                  Timer_Queue_Stack (new ACE_Timer_Heap (max_iterations, 1),
                                     ACE_TEXT ("ACE_Timer_Heap (preallocated)"),
                                     tq_stack),
                  -1);

  // Timer_Heap without preallocated memory, using high-res time.
  (void) ACE_High_Res_Timer::global_scale_factor ();
  ACE_Timer_Heap *tq_heap = new ACE_Timer_Heap;
  tq_heap->gettimeofday (&ACE_High_Res_Timer::gettimeofday_hr);
  ACE_NEW_RETURN (tq_stack,
                  Timer_Queue_Stack (tq_heap,
                                     ACE_TEXT ("ACE_Timer_Heap (high-res timer)"),
                                     tq_stack),
                  -1);

  // Create the Timer ID array
  ACE_NEW_RETURN (timer_ids,
		  long[max_iterations],
                  -1);

  Timer_Queue_Stack *tq_ptr = tq_stack;

  while (tq_ptr != NULL)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("**** starting test of %s\n"),
                  tq_ptr->name_));
      test_functionality (tq_ptr->queue_);
      test_performance (tq_ptr->queue_,
                        tq_ptr->name_);
      delete tq_ptr->queue_;
      Timer_Queue_Stack *temp = tq_ptr;
      tq_ptr = tq_ptr->next_;
      delete temp;
    }

  delete [] timer_ids;

  ACE_END_TEST;
  return 0;
}
