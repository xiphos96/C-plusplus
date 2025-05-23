// test_multiple_loops.cpp,v 1.11 2001/12/27 15:38:05 bala Exp

// ============================================================================
//
// = LIBRARY
//    examples
// 
// = FILENAME
//    test_multiple_loops.cpp
//
// = DESCRIPTION
//
//    This example application shows how to write programs that
//    combine the Proactor and Reactor event loops. This is possible
//    only on WIN32 platform.
//
// = AUTHOR
//    Irfan Pyarali
// 
// ============================================================================

#include "ace/Synch.h"
#include "ace/Task.h"
#include "ace/Proactor.h"
#include "ace/WIn32_Proactor.h"
#include "ace/Atomic_Op.h"

ACE_RCSID(Proactor, test_multiple_loops, "test_multiple_loops.cpp,v 1.11 2001/12/27 15:38:05 bala Exp")

#if (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE))

class Timeout_Handler : public ACE_Handler, public ACE_Event_Handler
{
  // = TITLE
  //     Generic timeout handler.
  
public:
  Timeout_Handler (void) 
    { 
    }
  
  // This is called by the Proactor. This is declared in ACE_Handler.
  virtual void handle_time_out (const ACE_Time_Value &tv,
                                const void *arg)
    {
      // Print out when timeouts occur.
      ACE_DEBUG ((LM_DEBUG, "(%t) %d timeout occurred for %s @ %d.\n", 
		  ++count_,
		  (char *) arg,
		  tv.sec ()));

      // Since there is only one thread that can do the timeouts in
      // Reactor, lets keep the handle_timeout short for that
      // thread.
      if (ACE_OS::strcmp ((char *) arg, "Proactor") == 0)
	// Sleep for a while
	ACE_OS::sleep (1);
    }

  // This method is declared in ACE_Event_Handler.
  virtual int handle_timeout (const ACE_Time_Value &tv,
			      const void *arg)
    {
      this->handle_time_out (tv, arg);
      return 0;
    }
  
private:
  ACE_Atomic_Op <ACE_Thread_Mutex, int> count_;
};

class Worker : public ACE_Task <ACE_NULL_SYNCH>
{
public:
  
  // Thread fuction.
  int svc (void)
    {
      ACE_DEBUG ((LM_DEBUG, "(%t) Worker started\n"));
      
      // Handle events for 13 seconds.
      ACE_Time_Value run_time (13);
      
      // Try to become the owner
      ACE_Reactor::instance ()->owner (ACE_Thread::self ());
      
      if (ACE_Reactor::run_event_loop (run_time) == -1)
        ACE_ERROR_RETURN ((LM_ERROR, "%p.\n", "Worker::svc"), -1);
      else
        ACE_DEBUG ((LM_DEBUG, "(%t) work complete\n"));
      
      return 0;
    }
};

int
main (int, char *[])
{
  Timeout_Handler handler;
  ACE_WIN32_Proactor win32_proactor (0, 1);
  ACE_Proactor proactor (&win32_proactor, 0, 0);
  
  ACE_Reactor::instance ()->register_handler (proactor.implementation ());
  
  // Register a 2 second timer.
  ACE_Time_Value foo_tv (2);
  if (proactor.schedule_timer (handler,
			       (void *) "Proactor",
			       ACE_Time_Value::zero,
			       foo_tv) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "schedule_timer"), -1);

  // Register a 3 second timer.
  ACE_Time_Value bar_tv (3);
  if (ACE_Reactor::instance ()->schedule_timer (&handler,
						(void *) "Reactor",
						ACE_Time_Value::zero,
						bar_tv) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "schedule_timer"), -1);

  Worker worker;

  if (worker.activate (THR_NEW_LWP, 10) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p.\n", "main"), -1);
  
  ACE_Thread_Manager::instance ()->wait ();

  // Remove from reactor
  ACE_Reactor::instance ()->remove_handler (&proactor, 
                                            ACE_Event_Handler::DONT_CALL);

  return 0;
}

#endif /* ACE_WIN32 && !ACE_HAS_WINCE */
