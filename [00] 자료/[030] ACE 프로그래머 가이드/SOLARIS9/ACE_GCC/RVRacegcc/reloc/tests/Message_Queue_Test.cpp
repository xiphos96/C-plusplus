// Message_Queue_Test.cpp,v 4.52 2002/03/06 21:48:03 nanbor Exp

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Message_Queue_Test.cpp
//
// = DESCRIPTION
//      This is:
//      1) a simple test of the ACE_Message_Queue that illustrates how to
//         use the forward and reverse iterators;
//      2) a simple performance measurement test for both single-threaded
//         (null synch) and thread-safe ACE_Message_Queues, and
//         ACE_Message_Queue_Vx, which wraps VxWorks message queues; and
//      3) a test/usage example of ACE_Message_Queue_Vx.
//
// = AUTHORS
//    Irfan Pyarali <irfan@cs.wustl.edu> and David L. Levine <levine@cs.wustl.edu>
//
// ============================================================================

#include "test_config.h"
#include "ace/Thread_Manager.h"
#include "ace/Message_Queue.h"
#include "ace/Synch.h"
#include "ace/High_Res_Timer.h"

ACE_RCSID(tests, Message_Queue_Test, "Message_Queue_Test.cpp,v 4.52 2002/03/06 21:48:03 nanbor Exp")

const ACE_TCHAR usage[] = ACE_TEXT ("usage: Message_Queue_Test <number of messages>\n");

typedef ACE_Message_Queue<ACE_NULL_SYNCH> QUEUE;
typedef ACE_Message_Queue_Iterator<ACE_NULL_SYNCH> ITERATOR;
typedef ACE_Message_Queue_Reverse_Iterator<ACE_NULL_SYNCH> REVERSE_ITERATOR;

static const int MAX_MESSAGES = 10000;
static const int MAX_MESSAGE_SIZE = 32;
static const char test_message[] = "ACE_Message_Queue Test Message";

static int max_messages = MAX_MESSAGES;

// Dynamically allocate to avoid a static.
static ACE_High_Res_Timer *timer = 0;

#if defined (ACE_HAS_THREADS)
typedef ACE_Message_Queue<ACE_MT_SYNCH> SYNCH_QUEUE;

struct Queue_Wrapper
{
  // = TITLE
  //     Container for data passed to sender and receiver in
  //     performance test.
  //
  // = DESCRIPTION
  //     For use in multithreaded performance test.

  ACE_Message_Queue_Base *q_;
  // The message queue.

  ACE_Message_Block **send_block_;
  // Pointer to messages blocks for sender to send to reciever.

  Queue_Wrapper (void)
    : q_ (0), send_block_ (0)
  {
  }
  // Default constructor.
};

#endif /* ACE_HAS_THREADS */

#if !defined (VXWORKS)
static int
iterator_test (void)
{
  const int ITERATIONS = 5;
  ACE_TCHAR buffer[ITERATIONS][BUFSIZ];
  // Use queue size from of 32 Kb, instead of the default of 16 Kb
  // (defined by ACE_Message_Queue_Base::DEFAULT_HWM), so that the
  // test runs on machines with 8Kb pagesizes.
#if !defined(_UNICOS)
  QUEUE queue (32 * 1024 * sizeof (ACE_TCHAR));
#else
  // this works on the Cray, where BUFSIZ is defined as 32Kb
  QUEUE queue (ITERATIONS * BUFSIZ - 1);
#endif

  int i;

  for (i = 0; i < ITERATIONS; i++)
    {
      ACE_OS::sprintf (buffer[i],
                       ACE_TEXT ("%d"),
                       i + 1);

      ACE_Message_Block *entry;
      ACE_NEW_RETURN (entry,
                      ACE_Message_Block ((char *) buffer[i],
                                         sizeof buffer[i]),
                      -1);

      if (queue.is_full ())
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("QUEUE:: the message queue is full on iteration %u!\n"),
                           i + 1),
                          -1);

      if (queue.enqueue (entry) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("QUEUE::enqueue\n")),
                          -1);
    }

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("\nForward Iterations\n")));
  {
    ITERATOR iterator (queue);

    for (ACE_Message_Block *entry = 0;
         iterator.next (entry) != 0;
         iterator.advance ())
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("%s\n"),
                  entry->base ()));
  }

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("\nReverse Iterations\n")));
  {
    REVERSE_ITERATOR iterator (queue);

    for (ACE_Message_Block *entry = 0;
         iterator.next (entry) != 0;
         iterator.advance ())
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("%s\n"),
                  entry->base ()));
  }

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("\nForward Iterations\n")));
  {
    QUEUE::ITERATOR iterator (queue);

    for (ACE_Message_Block *entry = 0;
         iterator.next (entry) != 0;
         iterator.advance ())
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("%s\n"),
                  entry->base ()));
  }

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("\nReverse Iterations\n")));
  {
    QUEUE::REVERSE_ITERATOR iterator (queue);

    for (ACE_Message_Block *entry = 0;
         iterator.next (entry) != 0;
         iterator.advance ())
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("%s\n"),
                  entry->base ()));
  }

  return 0;
}
#endif /* ! VXWORKS */

#if defined (ACE_HAS_THREADS)

static int
single_thread_performance_test (int queue_type = 0)
{
  const char test_message[] =
    "ACE_Message_Queue Test Message";
  const ACE_TCHAR *message =
    ACE_TEXT ("ACE_Message_Queue<ACE_NULL_SYNCH>, single thread");
  int i;

  // Create a message queue.
  ACE_Message_Queue_Base *msgq = 0;

  if (queue_type == 0)
    ACE_NEW_RETURN (msgq,
                    QUEUE,
                    -1);
#if defined (VXWORKS)
  else
    {
      ACE_NEW_RETURN (msgq,
                      ACE_Message_Queue_Vx (max_messages,
                                            MAX_MESSAGE_SIZE),
                      -1);
      message = "ACE_Message_Queue_Vx, single thread test";
    }
#elif defined (ACE_WIN32) && (ACE_HAS_WINNT4 != 0)
  else
    {
      ACE_NEW_RETURN (msgq,
                      ACE_Message_Queue_NT,
                      -1);
      message = ACE_TEXT ("ACE_Message_Queue_NT, single thread test");
    }
#endif /* VXWORKS */

  // Create the messages.  Allocate off the heap in case messages
  // is large relative to the amount of stack space available.
  ACE_Message_Block **send_block = 0;
  ACE_NEW_RETURN (send_block,
                  ACE_Message_Block *[max_messages],
                  -1);

  for (i = 0; i < max_messages; ++i)
    ACE_NEW_RETURN (send_block[i],
                    ACE_Message_Block (test_message,
                                       MAX_MESSAGE_SIZE),
                    -1);

  ACE_Message_Block **receive_block_p = 0;
  ACE_NEW_RETURN (receive_block_p,
                  ACE_Message_Block *[max_messages],
                  -1);

#if defined (VXWORKS)
  // Set up blocks to receive the messages.  Allocate these off the
  // heap in case messages is large relative to the amount of
  // stack space available.
  ACE_Message_Block *receive_block;
  ACE_NEW_RETURN (receive_block,
                  ACE_Message_Block[max_messages],
                  -1);

  for (i = 0; i < max_messages; ++i)
    {
      receive_block[i].init (MAX_MESSAGE_SIZE);

      // For VxWorks Message Queues, the receive block pointer must be
      // assigned.  It will be used by dequeue_head ().
      receive_block_p[i] = &receive_block[i];
    }
#endif /* VXWORKS */

  timer->start ();

  // Send/receive the messages.
  for (i = 0; i < max_messages; ++i)
    {
      if (msgq->enqueue_tail (send_block[i]) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("enqueue")),
                          -1);

      if (msgq->dequeue_head (receive_block_p[i]) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("dequeue_head")),
                          -1);
    }

  timer->stop ();

  ACE_Time_Value tv;
  timer->elapsed_time (tv);
  ACE_DEBUG ((LM_INFO,
              ACE_TEXT ("%s: %u messages took %u msec (%f msec/message)\n"),
              message,
              max_messages,
              tv.msec (),
              (double) tv.msec () / max_messages));
  timer->reset ();

  delete [] receive_block_p;
#if defined (VXWORKS)
  delete [] receive_block;
#endif /* VXWORKS */

  for (i = 0; i < max_messages; ++i)
    delete send_block[i];
  delete [] send_block;
  delete msgq;

  return 0;
}

static void *
receiver (void *arg)
{
  Queue_Wrapper *queue_wrapper =
    ACE_reinterpret_cast (Queue_Wrapper *,
                          arg);
  int i;

  ACE_Message_Block **receive_block_p = 0;
  ACE_NEW_RETURN (receive_block_p,
                  ACE_Message_Block *[max_messages],
                  (void *) -1);

#if defined (VXWORKS)
  // Set up blocks to receive the messages.  Allocate these off the
  // heap in case messages is large relative to the amount of stack
  // space available.
  ACE_Message_Block *receive_block;
  ACE_NEW_RETURN (receive_block,
                  ACE_Message_Block[max_messages],
                  (void *) -1);

  for (i = 0; i < max_messages; ++i)
    {
      receive_block[i].init (MAX_MESSAGE_SIZE);

      // For VxWorks Message Queues, the receive block pointer must be
      // assigned.  It will be used by <dequeue_head>.
      receive_block_p[i] = &receive_block[i];
    }
#endif /* VXWORKS */

  for (i = 0; i < max_messages; ++i)
    if (queue_wrapper->q_->dequeue_head (receive_block_p[i]) == -1)
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("dequeue_head")),
                        0);
  timer->stop ();

  delete [] receive_block_p;
#if defined (VXWORKS)
  delete [] receive_block;
#endif /* VXWORKS */

  return 0;
}

static void *
sender (void *arg)
{
  Queue_Wrapper *queue_wrapper =
    ACE_reinterpret_cast (Queue_Wrapper *, arg);
  int i;

  timer->start ();

  // Send the messages.
  for (i = 0; i < max_messages; ++i)
    if (queue_wrapper->q_->
        enqueue_tail (queue_wrapper->send_block_[i]) == -1)
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("enqueue")),
                        0);
  return 0;
}

static
int
performance_test (int queue_type = 0)
{
  Queue_Wrapper queue_wrapper;
  const ACE_TCHAR *message =
    ACE_TEXT ("ACE_Message_Queue<ACE_SYNCH>");
  int i;

  // Create the messages.  Allocate off the heap in case messages is
  // large relative to the amount of stack space available.  Allocate
  // it here instead of in the sender, so that we can delete it after
  // the _receiver_ is done.
  ACE_Message_Block **send_block = 0;
  ACE_NEW_RETURN (send_block,
                  ACE_Message_Block *[max_messages],
                  -1);

  for (i = 0; i < max_messages; ++i)
    ACE_NEW_RETURN (send_block[i],
                    ACE_Message_Block (test_message,
                                       MAX_MESSAGE_SIZE),
                    -1);

  queue_wrapper.send_block_ = send_block;

  if (queue_type == 0)
    ACE_NEW_RETURN (queue_wrapper.q_,
                    SYNCH_QUEUE,
                    -1);
#if defined (VXWORKS)
  else
    {
      ACE_NEW_RETURN (queue_wrapper.q_,
                      ACE_Message_Queue_Vx (max_messages,
                                            MAX_MESSAGE_SIZE),
                      -1);
      message = "ACE_Message_Queue_Vx";
    }
#elif defined (ACE_WIN32) && (ACE_HAS_WINNT4 != 0)
  else
    {
      ACE_NEW_RETURN (queue_wrapper.q_,
                      ACE_Message_Queue_NT,
                      -1);
      message = ACE_TEXT ("ACE_Message_Queue_NT");
    }
#endif /* VXWORKS */

  if (ACE_Thread_Manager::instance ()->spawn ((ACE_THR_FUNC) sender,
                                              &queue_wrapper,
                                              THR_BOUND) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("spawning sender thread")),
                      -1);

  if (ACE_Thread_Manager::instance ()->spawn ((ACE_THR_FUNC) receiver,
                                              &queue_wrapper,
                                              THR_BOUND) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("spawning receiver thread")),
                      -1);

  ACE_Thread_Manager::instance ()->wait ();
  ACE_Time_Value tv;
  timer->elapsed_time (tv);
  ACE_DEBUG ((LM_INFO, ACE_TEXT ("%s: %u messages took %u msec (%f msec/message)\n"),
              message,
              max_messages,
              tv.msec (),
              (double) tv.msec () / max_messages));
  timer->reset ();

  delete queue_wrapper.q_;
  queue_wrapper.q_ = 0;

  for (i = 0; i < max_messages; ++i)
    delete send_block[i];
  delete [] send_block;

  return 0;
}
#endif /* ACE_HAS_THREADS */

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_START_TEST (ACE_TEXT ("Message_Queue_Test"));

  int status = 0;

  if (argc == 2)
    if (! ACE_OS::strcmp (argv[1], ACE_TEXT ("-?")))
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%s/n"),
                  usage));
    else
      max_messages = ACE_OS::atoi (argv[1]);

  // Be sure that the a timed out get sets the error code properly.
  ACE_Message_Queue<ACE_SYNCH> q1;
  if (!q1.is_empty ()) {
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("New queue is not empty!\n")));
    status = 1;
  }
  else {
    ACE_Message_Block *b;
    ACE_Time_Value tv (ACE_OS::gettimeofday ());   // Now
    if (q1.dequeue_head (b, &tv) != -1) {
      ACE_ERROR ((LM_ERROR, ACE_TEXT ("Dequeued from empty queue!\n")));
      status = 1;
    }
    else if (errno != EWOULDBLOCK) {
      ACE_ERROR ((LM_ERROR, ACE_TEXT ("%p\n"),
                  ACE_TEXT ("Dequeue timeout should be EWOULDBLOCK, got")));
      status = 1;
    }
    else {
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Timed dequeue test: OK\n")));
      status = 0;     // All is well
    }
  }

#if !defined (VXWORKS)
  // The iterator test occasionally causes a page fault or a hang on
  // VxWorks.
  if (status == 0)
    status = iterator_test ();
#endif /* ! VXWORKS */

  ACE_NEW_RETURN (timer,
                  ACE_High_Res_Timer,
                  -1);

#if defined (ACE_HAS_THREADS)
  if (status == 0)
    single_thread_performance_test ();

# if defined (VXWORKS) || (defined (ACE_WIN32) && (ACE_HAS_WINNT4 != 0))
  // Test ACE_Message_Queue_Vx. or ACE_Message_Queue_NT
  if (status == 0)
    single_thread_performance_test (1);
# endif /* VXWORKS */

  if (status == 0)
    performance_test ();

# if defined (VXWORKS) || (defined (ACE_WIN32) && (ACE_HAS_WINNT4 != 0))
  // Test ACE_Message_Queue_Vx or ACE_Message_Queue_NT
  if (status == 0)
    performance_test (1);
# endif /* VXWORKS */
#endif /* ACE_HAS_THREADS */

  if (status != 0)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("test failed")));
  delete timer;
  timer = 0;

  ACE_END_TEST;
  return status;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
