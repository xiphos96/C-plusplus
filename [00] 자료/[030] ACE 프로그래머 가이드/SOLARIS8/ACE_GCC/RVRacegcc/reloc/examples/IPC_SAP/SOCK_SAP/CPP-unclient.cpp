// CPP-unclient.cpp,v 4.11 2002/04/15 05:37:34 jwillemsen Exp

// ACE_LSOCK Client.

#include "ace/LSOCK_Connector.h"
#include "ace/UNIX_Addr.h"
#include "ace/Log_Msg.h"
#include "ace/OS.h"

ACE_RCSID(SOCK_SAP, CPP_unclient, "CPP-unclient.cpp,v 4.11 2002/04/15 05:37:34 jwillemsen Exp")

#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)

int
main (int argc, char *argv[])
{
  const char *rendezvous = argc > 1 ? argv[1] : ACE_DEFAULT_RENDEZVOUS;
  char buf[BUFSIZ];

  ACE_LSOCK_Stream cli_stream;
  ACE_LSOCK_Connector con;
  ACE_UNIX_Addr remote_addr (rendezvous);

  // Establish the connection with server.
  if (con.connect (cli_stream, remote_addr) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "connect"),
                      1);

  // Send data to server (correctly handles "incomplete writes").

  for (int r_bytes;
       (r_bytes = ACE_OS::read (ACE_STDIN, buf, sizeof buf)) > 0;
       )
    if (cli_stream.send_n (buf, r_bytes) == -1)
      ACE_ERROR_RETURN ((LM_ERROR,
                         "%p\n",
                         "send_n"),
                        1);

  // Explicitly close the writer-side of the connection.
  if (cli_stream.close_writer () == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "close_writer"),
                      1);

  // Wait for handshake with server.
  if (cli_stream.recv_n (buf, 1) != 1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "recv_n"),
                      1);

  // Close the connection completely.
  if (cli_stream.close () == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "close"),
                      1);
  return 0;
}
#else
int ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE_ERROR_RETURN ((LM_ERROR,
		     "this platform does not support UNIX-domain sockets\n"), -1);
}
#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */
