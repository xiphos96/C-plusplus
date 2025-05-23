// main_reactor.cpp,v 4.5 2002/04/19 19:07:21 ossama Exp

// ============================================================================
//
// = LIBRARY
//    examples
//
// = FILENAME
//    main_reactor.cpp
//
// = DESCRIPTION
//      Implements an reactive timer queue.
//      This code exercises the Timer_Queue_Test_Driver class using
//      a reactor.
//
// = AUTHORS
//    Douglas Schmidt      <schmidt@cs.wustl.edu> &&
//    Sergio Flores-Gaitan <sergio@cs.wustl.edu>
//
// ============================================================================

// The following #pragma is needed to disable a warning that occurs
// in MSVC 6 due to the overly long debugging symbols generated for
// the std::auto_ptr<Timer_Queue_Test_Driver<...> > template
// instance used by some of the methods in this file.
#ifdef _MSC_VER
#  pragma warning(disable: 4786)  /* identifier was truncated to '255'
                                     characters in the browser
                                     information */
#endif  /* _MSC_VER */

#include "ace/Auto_Ptr.h"
#include "Reactor_Timer_Queue_Test.h"
#include "Driver.h"

ACE_RCSID (Timer_Queue,
           main_reactor,
           "main_reactor.cpp,v 4.5 2002/04/19 19:07:21 ossama Exp")

typedef Timer_Queue_Test_Driver <ACE_Timer_Heap,
                                 Input_Handler,
                                 Input_Handler::ACTION>
        REACTOR_TIMER_QUEUE_TEST_DRIVER;

int
ACE_TMAIN (int, ACE_TCHAR *[])
{
  REACTOR_TIMER_QUEUE_TEST_DRIVER *tqtd;
  ACE_NEW_RETURN (tqtd, Reactor_Timer_Queue_Test_Driver, -1);
  // Auto ptr ensures that the driver memory is released
  // automatically.
  auto_ptr <REACTOR_TIMER_QUEUE_TEST_DRIVER> driver (tqtd);

  return driver->run_test ();
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class auto_ptr <REACTOR_TIMER_QUEUE_TEST_DRIVER>;
template class ACE_Auto_Basic_Ptr <REACTOR_TIMER_QUEUE_TEST_DRIVER>;
template class Timer_Queue_Test_Driver<ACE_Timer_Heap *,
                                       Input_Handler,
                                       Input_Handler::ACTION>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate auto_ptr <REACTOR_TIMER_QUEUE_TEST_DRIVER>
#pragma instantiate ACE_Auto_Basic_Ptr <REACTOR_TIMER_QUEUE_TEST_DRIVER>
#pragma instantiate Timer_Queue_Test_Driver<ACE_Timer_Heap *, \
                                       Input_Handler, \
                                       Input_Handler::ACTION>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
