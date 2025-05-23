// remote_thr_stream_client_test.cpp,v 4.10 2002/03/06 21:48:02 nanbor Exp

// Test program for the INET ACE_TLI-SAPs...

#include "ace/Mem_Map.h"
#include "ace/TLI_Connector.h"
#include "ace/INET_Addr.h"
#include "ace/Get_Opt.h"
#include "ace/Log_Msg.h"

ACE_RCSID(client, remote_thr_stream_client_test, "remote_thr_stream_client_test.cpp,v 4.10 2002/03/06 21:48:02 nanbor Exp")

#if defined (ACE_HAS_TLI)

// Name of the program.
static const char *program_name;

// Port number to use.
static u_short port_number = ACE_DEFAULT_THR_PORT;

// Name of remote host.
static const char *host_name = ACE_DEFAULT_SERVER_HOST;

// Name of file to send.
static const char *file_name = "./remote_data";

static void print_usage_and_die (void)
{
  ACE_ERROR ((LM_ERROR,
              "usage: %s [-p portnum] [-h host_name] [-f file]\n",
              program_name));
  ACE_OS::exit (1);
}

void
parse_args (int argc, char *argv[])
{
  program_name = argv[0];
  ACE_Get_Opt get_opt (argc, argv, "f:h:p:");

  for (int c; (c = get_opt ()) != -1; )
    switch (c)
      {
      case 'f':
	file_name = get_opt.opt_arg ();
	break;
      case 'h':
	host_name = get_opt.opt_arg ();
	break;
      case 'p':
	port_number = ACE_OS::atoi (get_opt.opt_arg ());
	break;
      default:
	print_usage_and_die ();
	break;
      }
}

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  parse_args (argc, argv);
  void *cp;
  char buf[BUFSIZ];
  ACE_TLI_Stream sc;
  ACE_TLI_Connector con;

  if (con.connect (sc,
                   ACE_INET_Addr (port_number,
                                  host_name)) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "open"),
                      -1);

  ACE_Mem_Map mmap (file_name, PROT_READ);

  if (mmap (cp) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",

                       "mmap"), -1);

  // Next, send the file's contents.

  if (sc.send_n (cp, mmap.size ()) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",

                       "send_n"), -1);

  if (sc.sndrel () == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "close_writer"),
                      -1);

  for (int n; (n = sc.recv (buf, sizeof buf)) > 0; )
    if (ACE_OS::write (ACE_STDOUT, buf, n) != n)
      ACE_ERROR_RETURN ((LM_ERROR,
                         "%p\n",
                         "write"),
                        -1);

  if (sc.close () == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "close"),
                      -1);
  return 0;
}
#else
int
ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE_ERROR_RETURN ((LM_ERROR,
                     "you must have TLI to run this test\n"),
                    1);
}
#endif /* ACE_HAS_TLI */
