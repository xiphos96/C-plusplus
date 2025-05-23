// FIFO-Msg-client.cpp,v 4.5 2002/03/06 21:48:02 nanbor Exp

#include "ace/FIFO_Send_Msg.h"

ACE_RCSID(FIFO_SAP, FIFO_Msg_client, "FIFO-Msg-client.cpp,v 4.5 2002/03/06 21:48:02 nanbor Exp")

#if defined (ACE_HAS_STREAM_PIPES)

int
ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE_FIFO_Send_Msg client (ACE_DEFAULT_RENDEZVOUS);

  char buf[BUFSIZ];
  ACE_Str_Buf msg (buf);

  ACE_OS::srand (unsigned (ACE_OS::time (0)));

  while (ACE_OS::fgets (buf, sizeof buf, stdin) != 0)
    {
      msg.len = strlen (buf) + 1;
      if (client.send (ACE_OS::rand () % 11, &msg) == -1)
	::perror ("send");
    }

  if (client.close () == -1)
    ACE_OS::perror ("close"), ACE_OS::exit (1);

  return 0;
}
#else
#include <stdio.h>
int ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE_OS::fprintf (stderr, "This feature is not supported\n");
  return 0;
}
#endif /* ACE_HAS_STREAM_PIPES */
