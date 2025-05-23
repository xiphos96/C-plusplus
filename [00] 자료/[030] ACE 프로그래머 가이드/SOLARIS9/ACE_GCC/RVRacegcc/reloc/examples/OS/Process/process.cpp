// process.cpp,v 4.18 2001/12/26 15:45:57 schmidt Exp

// ============================================================================
//
// = LIBRARY
//    examples
//
// = FILENAME
//    process.cpp
//
// = DESCRIPTION
//    This example tests the <ACE_Process>.  For more info, check the
//    README file in this directory.
//
// = AUTHOR
//    Tim Harrison <harrison@cs.wustl.edu>.
//
// ============================================================================

#include "ace/OS.h"
#include "ace/Get_Opt.h"
#include "ace/Process.h"
#include "ace/Log_Msg.h"

ACE_RCSID(Process, process, "process.cpp,v 4.18 2001/12/26 15:45:57 schmidt Exp")

#if defined (ACE_WIN32)
#define EXEC_NAME "MORE.COM"
const char *DATE_PATH = "date.exe";
const char *LS_PATH = "ls.exe";
const char *SLEEP_PATH = "sleep.exe";
#else
#define EXEC_NAME "less"
const char *DATE_PATH = "date";
const char *LS_PATH = "ls";
const char *SLEEP_PATH = "sleep";
#endif /* ACE_WIN32 */

static char *executable = EXEC_NAME;
static char *print_file = 0;
static char *environment_string = 0;
static int get_env = 0;
static int run_date = 0;
static int run_ls = 0;
static int run_all = 0;
static int run_setenv = 0;
static int run_tokenizer = 0;
static int run_wait = 0;

// Parse the command-line arguments and set options.
static int
parse_args (int argc, char **argv)
{
  ACE_Get_Opt get_opt (argc, argv, "dlx:p:e:gastuw");
  int c;

  while ((c = get_opt ()) != -1)
    {
    switch (c)
      {
      case 't':
        run_tokenizer = 1;
        break;
      case 's':
        run_setenv = 1;
        break;
      case 'a':
        run_all = 1;
        break;
      case 'd':
        run_date = 1;
        break;
      case 'l':
        run_ls = 1;
        break;
      case 'x':
        executable = get_opt.opt_arg ();
        break;
      case 'p':
        print_file = get_opt.opt_arg ();
        break;
      case 'e':
        environment_string = get_opt.opt_arg ();
        break;
      case 'g':
        get_env = 1;
        break;
      case 'w':
        run_wait = 1;
        break;
      case 'u':
      default:
        ACE_ERROR_RETURN ((LM_ERROR, "Usage:\n"
                           "-d print date\n"
                           "-l run ls\n"
                           "-x <executable=more.com>\n"
                           "-p print <file_name>\n"
                           "-e <env variable message>\n"
                           "-s setenv ACE_PROCESS_ENV and spawn -g\n"
                           "-g get_env ACE_PROCESS_ENV\n"
                           "-t test tokenizer\n"
                           "-w test wait functions\n"
                           "-a run all (d,l,e \"running\")\n"), -1);
        break;
      }
    }

  return 0;
}

// This shows how to set handles.
static void
test_more (void)
{
  ACE_HANDLE infile = ACE_OS::open (print_file, O_RDONLY);

  if (infile == ACE_INVALID_HANDLE)
    {
      ACE_ERROR ((LM_DEBUG, "%p\n", print_file));
      return;
    }

  ACE_Process new_process;
  ACE_Process_Options options;
  options.command_line (executable);
  options.set_handles (infile);

  if (new_process.spawn (options) == -1)
    {
      int error = ACE_OS::last_error ();
      ACE_ERROR ((LM_ERROR,
                  "%p errno = %d.\n",
                  "test_more",
                  error));
    }

  ACE_exitcode status;
  new_process.wait (&status);
  ACE_DEBUG ((LM_DEBUG,
              "Process exit with status %d\n",
              status));
  ACE_OS::close (infile);

  ACE_DEBUG ((LM_DEBUG,
              "More succeeded.\n"));
}

// This is a simple usage of ACE_Process.

static void
test_date (void)
{
  ACE_Process_Options options;
  options.command_line (DATE_PATH);

  // Try to create a new process running date.
  ACE_Process new_process;
  if (new_process.spawn (options) == -1)
    {
      int error = ACE_OS::last_error ();
      ACE_ERROR ((LM_ERROR,
                  "%p errno = %d.\n",
                  "test_date",
                  error));
      return;
    }

  ACE_exitcode status;
  new_process.wait (&status);
  ACE_DEBUG ((LM_DEBUG,
              "Process exit with status %d\n",
              status));
  ACE_DEBUG ((LM_DEBUG,
              "date succeeded.\n"));
}

static void
test_ls (void)
{
  ACE_Process_Options options;
  options.command_line ("%s -al", LS_PATH);

  ACE_Process new_process;
  if (new_process.spawn (options) == -1)
    {
      int error = ACE_OS::last_error ();
      ACE_ERROR ((LM_ERROR,
                  "%p errno = %d.\n",
                  "test_ls",
                  error));
    }

  ACE_exitcode status;
  new_process.wait (&status);
  ACE_DEBUG ((LM_DEBUG,
              "Process exit with status %d\n",
              status));
}

static void
test_wait (void)
{
  ACE_Process_Options options;
  options.command_line ("%s 10", SLEEP_PATH);

  ACE_Process process1;
  if (process1.spawn (options) == -1)
    {
      int error = ACE_OS::last_error ();
      ACE_ERROR ((LM_ERROR,
                  "%p errno = %d.\n",
                  "test_ls",
                  error));
    }

  int result;
  ACE_exitcode status;

  ACE_DEBUG ((LM_DEBUG,
              "[%T] New process sleeping 10; try wait(2)\n"));

  result = process1.wait (ACE_Time_Value (2),
                          &status);

  ACE_DEBUG ((LM_DEBUG,
              "[%T] wait(2) returns %d(%d)...now try regular wait\n",
              result,
              status));

  result = process1.wait (&status);
  ACE_DEBUG ((LM_DEBUG,
              "[%T] wait() returns %d(%d)\n",
              result,
              status));

  ACE_Process process2;
  if (process2.spawn (options) == -1)
    {
      int error = ACE_OS::last_error ();
      ACE_ERROR ((LM_ERROR,
                  "%p errno = %d.\n",
                  "test_ls",
                  error));
    }

  ACE_DEBUG ((LM_DEBUG,
              "[%T] New process sleeping 10; try wait(12)\n",
              status));

  result = process2.wait (ACE_Time_Value (12),
                          &status);

  ACE_DEBUG ((LM_DEBUG,
              "[%T] wait(12) returns %d(%d)...now try regular wait\n",
              result,
              status));

  result = process2.wait (&status);
  ACE_DEBUG ((LM_DEBUG,
              "[%T] wait returns %d(%d)\n",
              result,
              status));
}

#if defined (ACE_WIN32)
// This is just to test the direct usage of CreateProcess.  I use this
// occasionally as a sanity check when ACE_Process breaks.
static void
win32_test_ls (void)
{
  PROCESS_INFORMATION process_info;
  ACE_TEXT_STARTUPINFO startup_info;
  ACE_OS::memset ((void *) &startup_info,
                  0,
                  sizeof startup_info);
  ACE_OS::memset ((void *) &process_info,
                  0,
                  sizeof process_info);
  startup_info.cb = sizeof startup_info;
  startup_info.dwFlags = STARTF_USESTDHANDLES;

  ACE_HANDLE std_out = ACE_STDOUT;

  if (!::DuplicateHandle (::GetCurrentProcess (),
                          std_out,
                          ::GetCurrentProcess (),
                          &startup_info.hStdOutput,
                          NULL,
                          TRUE,
                          DUPLICATE_SAME_ACCESS))
    {
      ACE_ERROR ((LM_ERROR,
                  "%p duplicate failed.\n",
                  "test_ls"));
      return;
    }

  BOOL fork_result =
    ACE_TEXT_CreateProcess ("c:\\Utils\\bin\\ls.exe",
                                   "-a",
                            NULL, // No process attributes.
                            NULL, // No thread attributes.
                            TRUE, // Allow handle inheritance.
                            NULL, // CREATE_NEW_CONSOLE, // Create a new console window.
                            NULL,
                            0, // Current directory to start in.
                            &startup_info,
                            &process_info);

  ::CloseHandle (startup_info.hStdOutput);

  if (fork_result == 0)
    ACE_ERROR ((LM_ERROR,
                "%p CreateProcess failed.\n",
                "test_ls"));
  else
    {
      ::WaitForSingleObject (process_info.hProcess,
                             INFINITE);
      ACE_DEBUG ((LM_ERROR,
                  "ls succeeded.\n"));
    }
}

// This code spawns a new process.  The new process inherits our
// existing environment, plus one more.  This has to be done by hand
// since CreateProcess does not allow us to inherit AND add
// environment variables.

static void
win32_spawn_environment_process (void)
{
  PROCESS_INFORMATION process_info;
  ACE_TEXT_STARTUPINFO startup_info;
  ACE_OS::memset ((void *) &startup_info,
                  0,
                  sizeof startup_info);
  ACE_OS::memset ((void *) &process_info,
                  0,
                  sizeof process_info);
  startup_info.cb = sizeof (startup_info);
  startup_info.dwFlags = STARTF_USESTDHANDLES;

  ACE_HANDLE std_in = ACE_STDIN;
  ACE_HANDLE std_out = ACE_STDOUT;
  ACE_HANDLE std_err = ACE_STDERR;

  if (!::DuplicateHandle (::GetCurrentProcess(),
                          std_out,
                          ::GetCurrentProcess(),
                          &startup_info.hStdOutput,
                          NULL,
                          TRUE,
                          DUPLICATE_SAME_ACCESS))
    {
      ACE_ERROR ((LM_ERROR,
                  "%p duplicate failed.\n", "spawn_environment_process"));
      return;
    }

  if (!::DuplicateHandle (::GetCurrentProcess(),
                          std_err,
                          ::GetCurrentProcess(),
                          &startup_info.hStdError,
                          NULL,
                          TRUE,
                          DUPLICATE_SAME_ACCESS))
    {
      ACE_ERROR ((LM_ERROR,
                  "%p duplicate failed.\n",
                  "spawn_environment_process"));
      return;
    }

  if (!::DuplicateHandle (::GetCurrentProcess(),
                          std_in,
                          ::GetCurrentProcess(),
                          &startup_info.hStdInput,
                          NULL,
                          TRUE,
                          DUPLICATE_SAME_ACCESS))
    {
      ACE_ERROR ((LM_ERROR,
                  "%p duplicate failed.\n",
                  "spawn_environment_process"));
      return;
    }

  // Normally, this would be just GetEnvironmentStrings, but it
  // doesn't follow the same rules as the rest of the Win32 API
  char *existing_environment = ACE_OS::getenvstrings ();
  char environment[10240];
  ACE_OS::sprintf (environment,
                   "ACE_PROCESS_TEST=%s",
                   environment_string);

  int size = 0;
  while (existing_environment[size] != '\0')
    size += ACE_OS::strlen (existing_environment + size) + 1;

  ACE_OS::memcpy (environment + (ACE_OS::strlen (environment) + 1),
                  existing_environment,
                  size);

  ACE_TEXT_FreeEnvironmentStrings (existing_environment);

  BOOL fork_result =
    ACE_TEXT_CreateProcess ("d:\\harrison\\ACE_wrappers\\examples\\OS\\Process\\process.exe",
                            "process -g",
                            NULL, // No process attributes.
                            NULL, // No thread attributes.
                            TRUE, // Allow handle inheritance.
                            NULL, // CREATE_NEW_CONSOLE, // Create a new console window.
                            environment, // Environment.
                            //"d:\\harrison\\ACE_wrappers\\examples\\OS\\Process\\",
                            0,
                            &startup_info,
                            &process_info);

  ::CloseHandle (startup_info.hStdOutput);
  ::CloseHandle (startup_info.hStdError);

  if (fork_result == 0)
    ACE_ERROR ((LM_ERROR,
                "%p.\n",
                "spawn_environment_process"));
  else
    {
      ::WaitForSingleObject (process_info.hProcess,
                             INFINITE);
      ACE_DEBUG ((LM_ERROR, 
                  "spawn_environment_process succeeded.\n"));
    }
}
#endif

static void
test_setenv (const char *argv0)
{
  ACE_Process_Options options;
  //  options.setenv ("ACE_PROCESS_TEST", "here's a really large number: %u", 0 - 1);
  options.setenv ("ACE_PROCESS_TEST= here's a large number %u", 0 - 1);
  options.setenv ("ACE_PROCESS_TEST2", "ophilli");
  options.command_line ("%s -g", argv0);
  ACE_Process process;
  if (process.spawn (options) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "%p.\n",
                  "test_setenv"));
      return;
    }

  ACE_exitcode status;
  process.wait (&status);
  ACE_DEBUG ((LM_DEBUG,
              "Process exit with status %d\n",
              status));
}

// Tests the ACE_Tokenizer.
static void
tokenize (char *buffer)
{
  // This tokenizer will replace all spaces with end-of-string
  // characters and will preserve text between "" and '' pairs.
  ACE_Tokenizer parser (buffer);
  parser.delimiter_replace (' ', '\0');
  parser.preserve_designators ('\"', '\"'); // "  This quote is for emacs
  parser.preserve_designators ('\'', '\'');

  for (const char *temp; ;)
    {
      temp = parser.next ();
      if (temp == 0)
        break;
      ACE_DEBUG ((LM_DEBUG,
                  temp));
      ACE_DEBUG ((LM_DEBUG,
                  "\n"));
    }
}

int
main (int argc, char *argv[])
{
  if (ACE_LOG_MSG->open (argv[0]) == -1)
    ACE_ERROR ((LM_ERROR,
                "cannot open logger!!!\n"));

  ACE_DEBUG ((LM_DEBUG,
              "starting...\n"));

  if (::parse_args (argc, argv) == -1)
    return -1;

  if (run_all)
    {
      ACE_Process_Options options;
      options.command_line ("%s -d -l -s -w",
                            argv[0]);
      ACE_Process process;
      if (process.spawn (options) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "%p.\n",
                           "main"),
                          -1);
      ACE_exitcode status;
      process.wait (&status);
      ACE_DEBUG ((LM_DEBUG,
                  "Process exit with status %d\n",
                  status));
    }

  if (run_date)
    ::test_date ();

  if (run_setenv)
    ::test_setenv (argv[0]);

  if (get_env)
    {
      ACE_DEBUG ((LM_DEBUG, "checking ACE_PROCESS_TEST\n"));
      char *value = ACE_OS::getenv ("ACE_PROCESS_TEST");
      char *value2 = ACE_OS::getenv ("ACE_PROCESS_TEST2");
      ACE_DEBUG ((LM_DEBUG,
                  "ACE_PROCESS_TEST = %s.\n"
                  "ACE_PROCESS_TEST2 = %s.\n",
                  value == 0 ? "no value" : value,
                  value2 == 0 ? "no value" : value2));
    }

  if (run_ls)
    ::test_ls ();

  if (run_wait)
    ::test_wait ();

#if defined (ACE_WIN32)
  if (environment_string != 0)
    win32_spawn_environment_process ();
#endif /* ACE_WIN32 */

  if (print_file != 0)
    test_more ();

  char buf1[30];
  char buf2[30];
  ACE_OS::strcpy(buf1, " -f hi honey -g \"I\'m home\"");
  ACE_OS::strcpy(buf2, "\"token 1\"\'token 2\'\"token 3\" ");

  if (run_tokenizer)
    {
      tokenize ( buf1 );
      tokenize ( buf2 );
    }

  return 0;
}
