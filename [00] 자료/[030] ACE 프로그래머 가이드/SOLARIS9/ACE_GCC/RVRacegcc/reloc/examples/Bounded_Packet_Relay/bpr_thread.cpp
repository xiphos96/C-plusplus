// bpr_thread.cpp,v 1.13 2002/04/19 19:07:21 ossama Exp

// ============================================================================
//
// = LIBRARY
//    examples
//
// = FILENAME
//    bpr_thread.cpp
//
// = DESCRIPTION
//    Exercises drivers for a bounded packet relay, based on threaded timer queues.  
//
// = AUTHORS
//    Chris Gill           <cdgill@cs.wustl.edu>  and
//    Douglas C. Schmidt   <schmidt@cs.wustl.edu>
//
//    Based on the Timer Queue Test example written by
//
//    Carlos O'Ryan        <coryan@cs.wustl.edu>  and
//    Douglas C. Schmidt   <schmidt@cs.wustl.edu> and
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
#include "Thread_Bounded_Packet_Relay.h"

ACE_RCSID (Bounded_Packet_Relay,
           bpr_thread,
           "bpr_thread.cpp,v 1.13 2002/04/19 19:07:21 ossama Exp")

typedef Bounded_Packet_Relay_Driver<Thread_Timer_Queue>
	THREAD_BOUNDED_PACKET_RELAY_DRIVER;

typedef ACE_Command_Callback<Bounded_Packet_Relay,Bounded_Packet_Relay::ACTION>
	INPUT_CALLBACK;

// A snippet from Andrew Marvell (Oliver Cromwell's poet laureate)
static const char input_text [] =
"But ever at my back I hear\n"
" Time's winged chariot hurrying near.";

int
main (int, char *[])
{
  // Construct a new thread manager for the input device task.  Auto
  // ptr ensures memory is freed when we exit this scope.
  ACE_Thread_Manager *input_task_mgr;
  ACE_NEW_RETURN (input_task_mgr,
                  ACE_Thread_Manager,
                  -1);
  auto_ptr <ACE_Thread_Manager> mgr (input_task_mgr);

  // Construct a new input device wrapper.  Auto ptr ensures memory is
  // freed when we exit this scope.
  Text_Input_Device_Wrapper *input_device;
  ACE_NEW_RETURN (input_device,
                  Text_Input_Device_Wrapper (input_task_mgr,
                                             sizeof (input_text), 
                                             input_text),
                  -1);
  auto_ptr <Text_Input_Device_Wrapper> input (input_device);

  // Construct a new output device wrapper.  Auto ptr ensures memory
  // is freed when we exit this scope.
  Text_Output_Device_Wrapper *output_device;
  ACE_NEW_RETURN (output_device,
                  Text_Output_Device_Wrapper,
                  -1);
  auto_ptr <Text_Output_Device_Wrapper> output (output_device);

  // Construct a new bounded packet relay.  Auto ptr ensures memory is
  // freed when we exit this scope.
  Bounded_Packet_Relay *packet_relay;
  ACE_NEW_RETURN (packet_relay,
                  Bounded_Packet_Relay (input_task_mgr,
                                        input_device,
                                        output_device),
                  -1);
  auto_ptr <Bounded_Packet_Relay> relay (packet_relay);

  // Construct a receive input callback command for the relay, and register 
  // it with the input device.  Auto ptr ensures memory is freed when we exit 
  // this scope.
  INPUT_CALLBACK *input_callback;
  ACE_NEW_RETURN (input_callback,
                  INPUT_CALLBACK (*packet_relay,
                                  &Bounded_Packet_Relay::receive_input),
                  -1);
  auto_ptr <INPUT_CALLBACK> callback (input_callback);
  if (input_device->set_send_input_msg_cmd (input_callback) < 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "failed to register input callback"), 
                        -1);
    }

  // Construct a new bounded packet relay driver.  Auto ptr ensures
  // memory is freed when we exit this scope.
  THREAD_BOUNDED_PACKET_RELAY_DRIVER *tbprd;

  ACE_NEW_RETURN (tbprd,
                  Thread_Bounded_Packet_Relay_Driver (packet_relay),
                  -1);

  auto_ptr <THREAD_BOUNDED_PACKET_RELAY_DRIVER> driver (tbprd);

  return driver->run ();
  // All dynamically allocated memory is released when main() returns.
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class auto_ptr <THREAD_BOUNDED_PACKET_RELAY_DRIVER>;
template class ACE_Auto_Basic_Ptr <THREAD_BOUNDED_PACKET_RELAY_DRIVER>;
template class ACE_Command_Callback <Bounded_Packet_Relay, Bounded_Packet_Relay::ACTION>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate auto_ptr <THREAD_BOUNDED_PACKET_RELAY_DRIVER>
#pragma instantiate ACE_Auto_Basic_Ptr <THREAD_BOUNDED_PACKET_RELAY_DRIVER>
#pragma instantiate ACE_Command_Callback <Bounded_Packet_Relay, Bounded_Packet_Relay::ACTION>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
