// Prerun_State_Changes.cpp,v 4.1 2002/04/25 04:40:42 irfan Exp
//
// ============================================================================
//
// = LIBRARY
//    examples
//
// = FILENAME
//    Prerun_State_Changes.cpp
//
// = DESCRIPTION
//
//    Tests the Reactor's ability to handle state changes before
//    getting a chance to run.
//
// = AUTHOR
//
//    Irfan Pyarali
//
// ============================================================================

#include "ace/Reactor.h"

ACE_RCSID(WFMO_Reactor, Prerun_State_Changes, "Prerun_State_Changes.cpp,v 4.1 2002/04/25 04:40:42 irfan Exp")

class Event_Handler : public ACE_Event_Handler
// = TITLE
//    Generic Event Handler.
//
{
public:
  virtual int handle_close (ACE_HANDLE handle, ACE_Reactor_Mask mask)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "event handler %d closed.\n",
                  (int) handle));
      delete this;
      return 0;
    }
};

int
ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE_HANDLE handle = (ACE_HANDLE) ::socket (PF_INET, SOCK_STREAM, 0);

  Event_Handler *event_handler = new Event_Handler;

  int result = ACE_Reactor::instance ()->register_handler (handle,
                                                           event_handler,
                                                           ACE_Event_Handler::READ_MASK);
  ACE_ASSERT (result == 0);

  result = ACE_Reactor::instance ()->register_handler (handle,
                                                       event_handler,
                                                       ACE_Event_Handler::WRITE_MASK | ACE_Event_Handler::QOS_MASK);
  ACE_ASSERT (result == 0);

  result = ACE_Reactor::instance ()->remove_handler (handle,
                                                     ACE_Event_Handler::READ_MASK | ACE_Event_Handler::DONT_CALL);
  ACE_ASSERT (result == 0);

  return 0;
}
