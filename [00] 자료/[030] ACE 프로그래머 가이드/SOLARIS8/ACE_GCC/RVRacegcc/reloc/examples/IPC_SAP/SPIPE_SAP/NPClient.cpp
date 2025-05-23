// NPClient.cpp,v 4.9 2002/03/06 21:48:02 nanbor Exp

#include "ace/SPIPE_Addr.h"
#include "ace/SPIPE_Connector.h"
#include "ace/Log_Msg.h"

ACE_RCSID(SPIPE_SAP, NPClient, "NPClient.cpp,v 4.9 2002/03/06 21:48:02 nanbor Exp")

#if defined (ACE_WIN32)
#define MAKE_PIPE_NAME(X) "\\\\.\\pipe\\"#X
#else
#define MAKE_PIPE_NAME(X) X
#endif

const int DEFAULT_SIZE = 8;
const int DEFAULT_COUNT = 10000;

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  int  size = argc > 1 ? ACE_OS::atoi (argv[1]) : DEFAULT_SIZE;
  int  iterations = argc > 2 ? ACE_OS::atoi (argv[2]) : DEFAULT_COUNT;
  char *buf;

  ACE_NEW_RETURN (buf,
                  char[size],
                  1);

  const char *pipe_name = "acepipe";
  const char *rendezvous = MAKE_PIPE_NAME (pipe_name);

  ACE_SPIPE_Stream cli_stream;
  ACE_SPIPE_Connector con;
  int i;

  if (con.connect (cli_stream,
                   ACE_SPIPE_Addr (rendezvous)) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       rendezvous),
                      -1);

  ACE_OS::strcpy (buf, "hello");
  size = ACE_OS::strlen (buf) + 1;

  for (i = 0; i < iterations; i++)
    if (cli_stream.send (buf, size) != size)
      ACE_ERROR_RETURN ((LM_ERROR,
                         "%p\n",
                         "putmsg"),
                        -1);

  if (cli_stream.close () == -1)
      ACE_ERROR_RETURN ((LM_ERROR,
                         "%p\n",
                         "close"),
                        -1);
  return 0;
}
