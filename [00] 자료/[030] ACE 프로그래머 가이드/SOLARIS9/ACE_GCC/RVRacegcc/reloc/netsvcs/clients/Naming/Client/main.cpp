// main.cpp,v 1.2 2003/03/31 22:02:30 shuston Exp
// main.cpp,v 4.12 2002/08/29 03:13:23 shuston Exp

// Test the client-side of the ACE Name Server...

#include "ace/Service_Config.h"
#include "ace/Naming_Context.h"
#include "ace/ARGV.h"
#include "ace/Argv_Type_Converter.h"
#include "ace/Log_Msg.h"

#include "Client_Test.h"

ACE_RCSID(Client, main, "main.cpp,v 4.12 2002/08/29 03:13:23 shuston Exp")

int
main (int argc, char *argv[])
{
  ACE_Service_Config daemon;
  ACE_ARGV new_args;

  // Load the existing <argv> into our new one, unifying the character size.
  ACE_Argv_Type_Converter conv_argv (argc, argv);
  new_args.add (conv_argv.get_TCHAR_argv ());
  // Enable loading of static services.
  new_args.add (ACE_TEXT ("-y")); 
  // Enable debugging within dynamically linked services.
  new_args.add (ACE_TEXT ("-d")); 

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("argc = %d\n"),
              new_args.argc ()));

  // Print the contents of the combined <ACE_ARGV>.
  for (int i = 0; i < new_args.argc (); i++)
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%d) %s\n"),
                i,
                new_args.argv ()[i]));

  if (daemon.open (new_args.argc (),
                   new_args.argv ()) == -1)
    {
      if (errno != ENOENT)
	ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("%p\n%a"),
                    ACE_TEXT ("open"),
                    1));
      else // Use static binding.
	{
          ACE_ARGV args;

          args.add (conv_argv.get_TCHAR_argv ()[0]);
	  args.add (ACE_TEXT ("-p10011")); // Port number.
	  ACE_Service_Object *so =
            ACE_SVC_INVOKE (ACE_Naming_Context);

	  if (so->init (args.argc (),
                        args.argv ()) == -1)
	    ACE_ERROR ((LM_ERROR,
                        ACE_TEXT ("%p\n%a"),
                        ACE_TEXT ("ACE_Naming_Context"),
                        1));

	  so = ACE_SVC_INVOKE (Client_Test);

	  if (so->init (0,
                        args.argv ()) == -1)
	    ACE_ERROR ((LM_ERROR,
                        ACE_TEXT ("%p\n%a"),
                        ACE_TEXT ("Client_Test"),
                        1));
	}
    }

  // Run forever, performing the configured services until we are shut
  // down by a SIGINT/SIGQUIT signal.

  ACE_Reactor::run_event_loop ();

  return 0;
}
