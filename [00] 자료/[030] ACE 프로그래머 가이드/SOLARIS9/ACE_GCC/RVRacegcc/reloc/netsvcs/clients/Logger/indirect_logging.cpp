// indirect_logging.cpp,v 1.2 2003/03/31 22:02:29 shuston Exp
// indirect_logging.cpp,v 4.13 2000/05/26 18:08:47 othman Exp

// This is a simple test that sends logging records to the Client
// Logging Daemon running on the localhost.  This daemon then forwards
// them to the Server Logging Daemon.  If there is no Server Logging
// Daemon, the logging records will be written to stderr.

#include "ace/OS.h"
#include "ace/Log_Msg.h"

ACE_RCSID(Logger, indirect_logging, "indirect_logging.cpp,v 1.2 2003/03/31 22:02:29 shuston Exp")

int 
main (int argc, char *argv[])
{
  const char *prog_name  = argv[0];
  int iterations  = argc < 2 ? 10 : ACE_OS::atoi (argv[1]);

  ACE_OS::srand ((u_int) ACE_OS::time (0));

  ACE_LOG_MSG->open (ACE_TEXT_CHAR_TO_TCHAR (prog_name),
                     ACE_Log_Msg::LOGGER,
                     argc < 3 ? ACE_DEFAULT_LOGGER_KEY
                              : ACE_TEXT_CHAR_TO_TCHAR (argv[2]));

  ACE_DEBUG ((LM_STARTUP, ACE_TEXT ("starting up the test\n")));

  for (int i = 0; i < iterations; i++)
    {
      size_t priority = ACE_OS::rand () % int (LM_MAX);
      ACE_POW (priority);
      ACE_DEBUG ((ACE_Log_Priority (priority), 
		  ACE_TEXT ("random message %d...\n"),
		  priority));
    }

  ACE_DEBUG ((LM_SHUTDOWN, ACE_TEXT ("closing down the test\n")));

#if defined (ACE_WIN32)
  // !!Important, Winsock is broken in that if you don't close
  // down the connection before exiting main, you'll lose data.
  // More over, your server might get "Access Violation" from
  // within Winsock functions.

  // Here we close down the connection to Logger by redirecting
  // the logging destination back to stderr.
  ACE_LOG_MSG->open (0, ACE_Log_Msg::STDERR, 0);
#endif /* ACE_WIN32 */

  return 0;
}
