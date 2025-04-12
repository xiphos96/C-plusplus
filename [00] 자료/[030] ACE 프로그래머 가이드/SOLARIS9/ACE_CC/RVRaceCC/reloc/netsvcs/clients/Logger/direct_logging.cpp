// direct_logging.cpp,v 1.2 2003/03/31 22:02:29 shuston Exp
// direct_logging.cpp,v 4.6 2001/12/31 14:21:24 jwillemsen Exp

// This program sends logging records directly to the server, rather
// than going through the client logging daemon.

#include "ace/SOCK_Connector.h"
#include "ace/Log_Record.h"
#include "ace/Log_Msg.h"

ACE_RCSID(Logger, direct_logging, "direct_logging.cpp,v 1.2 2003/03/31 22:02:29 shuston Exp")

static u_short LOGGER_PORT = ACE_DEFAULT_SERVER_PORT;
static const ACE_TCHAR *const LOGGER_HOST = ACE_DEFAULT_SERVER_HOST;
static const ACE_TCHAR *const DATA = ACE_TEXT ("hello world\n");

int
main (int argc, char *argv[])
{
  u_short logger_port  = argc > 1 ? ACE_OS::atoi (argv[1]) : LOGGER_PORT;

  ACE_SOCK_Stream logger;
  ACE_SOCK_Connector connector;
  ACE_INET_Addr addr
    (logger_port, argc > 2 ? ACE_TEXT_CHAR_TO_TCHAR (argv[2]) : LOGGER_HOST);
  ACE_Log_Record log_record (LM_DEBUG,
			     ACE_OS::time ((time_t *) 0),
			     ACE_OS::getpid ());

  if (connector.connect (logger, addr) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("%p\n"), ACE_TEXT ("open")), -1);

  log_record.msg_data (DATA);
  size_t len = log_record.length ();
  log_record.encode ();

  if (logger.send ((char *) &log_record, len) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("%p\n"), ACE_TEXT ("send")), -1);
  else if (logger.close () == -1)
    ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("%p\n"), ACE_TEXT ("close")), -1);
  return 0;
}
