// main.cpp,v 1.2 2003/03/31 22:02:30 shuston Exp
// main.cpp,v 4.5 2000/05/29 00:31:52 othman Exp

// Test the client-side of the ACE Name Server...

#include "ace/Argv_Type_Converter.h"
#include "ace/Reactor.h"
#include "ace/Service_Config.h"
#include "ace/Log_Msg.h"
#include "Dump_Restore.h"

ACE_RCSID(Dump_Restore, main, "main.cpp,v 1.2 2003/03/31 22:02:30 shuston Exp")

int 
main (int argc, char *argv[])
{
  ACE_Argv_Type_Converter conv_argv (argc, argv);
  ACE_Service_Config daemon (conv_argv.get_TCHAR_argv ()[0]);

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("entering main\n")));

  // Get a handler.
  Dump_Restore client_handler (argc, conv_argv.get_TCHAR_argv ());

  ACE_Reactor::instance ()->run_reactor_event_loop ();
  
  /* NOTREACHED */
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("leaving main\n")));
  return 0;
}
