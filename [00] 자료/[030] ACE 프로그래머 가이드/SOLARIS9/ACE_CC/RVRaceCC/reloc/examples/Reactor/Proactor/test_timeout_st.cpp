// test_timeout_st.cpp,v 1.2 2002/04/23 11:29:05 jwillemsen Exp

// ============================================================================
//
// = LIBRARY
//    examples
//
// = FILENAME
//    test_timeout_st.cpp
//
// = DESCRIPTION
//
//    This example application shows how to write event loops that
//    handle events for some fixed amount of time. This is the single
//    threaded version of the test_timeout.cpp application.
//
// = AUTHOR
//    Irfan Pyarali and Alexander Babu Arulanthu
//
// ============================================================================

#include "ace/Proactor.h"

ACE_RCSID(Proactor, test_timeout, "test_timeout_st.cpp,v 1.2 2002/04/23 11:29:05 jwillemsen Exp")

#if ((defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) || (defined (ACE_HAS_AIO_CALLS)))
// This only works on Win32 platforms and on Unix platforms supporting
// POSIX aio calls.

class Timeout_Handler : public ACE_Handler
{
  // = TITLE
  //     Generic timeout handler.

public:
  Timeout_Handler (void)
    : count_ (0),
      start_time_ (ACE_OS::gettimeofday ())
    {
    }

  virtual void handle_time_out (const ACE_Time_Value &tv,
				const void *arg)
    {
      // Print out when timeouts occur.
      ACE_DEBUG ((LM_DEBUG, "(%t) %d timeout occurred for %s @ %d.\n",
		  ++count_,
		  (char *) arg,
		  (tv - this->start_time_).sec ()));
    }

private:
  int count_;
  // Sequence number for the timeouts.

  ACE_Time_Value start_time_;
  // Starting time of the test.
};


int
ACE_TMAIN (int, ACE_TCHAR *[])
{
  Timeout_Handler handler;

  // Register a 2 second timer.
  ACE_Time_Value foo_tv (2);
  if (ACE_Proactor::instance ()->schedule_timer (handler,
                                                 (void *) "Foo",
                                                 ACE_Time_Value::zero,
                                                 foo_tv) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "schedule_timer"), -1);

  // Register a 3 second timer.
  ACE_Time_Value bar_tv (3);
  if (ACE_Proactor::instance ()->schedule_timer (handler,
                                                 (void *) "Bar",
                                                 ACE_Time_Value::zero,
                                                 bar_tv) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "schedule_timer"), -1);

  // Handle events for 13 seconds.
  ACE_Time_Value run_time (13);

  ACE_DEBUG ((LM_DEBUG, "Starting event loop\n"));

  // Run the event loop.
  if (ACE_Proactor::run_event_loop(run_time) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "(%t):%p.\n", "Worker::svc"),
                      1);

  ACE_DEBUG ((LM_DEBUG, "Ending event loop\n"));

  return 0;
}

#endif /* ACE_WIN32 && !ACE_HAS_WINCE || ACE_HAS_AIO_CALLS*/
