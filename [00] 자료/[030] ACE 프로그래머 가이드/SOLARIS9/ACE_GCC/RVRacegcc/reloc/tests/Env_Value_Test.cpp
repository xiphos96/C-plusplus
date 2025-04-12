// Env_Value_Test.cpp,v 4.37 2002/03/06 21:48:03 nanbor Exp

// ============================================================================
//
// = LIBRARY
//    tests
//
// = DESCRIPTION
//      This is a simple test to make sure the Env_Value template is
//      working correctly.
//
// = AUTHOR
//    Chris Cleeland <cleeland@cs.wustl.edu>
//
// ============================================================================

#include "test_config.h"
#include "ace/OS.h"
#include "ace/Process.h"
#include "ace/Env_Value_T.h"

ACE_RCSID(tests, Env_Value_Test, "Env_Value_Test.cpp,v 4.37 2002/03/06 21:48:03 nanbor Exp")

#define TEST_THIS(type, varname, defval, expval) \
do { \
  ACE_Env_Value<type> val (varname, (defval)); \
  if (val != (expval)) { \
    ACE_ERROR ((LM_ERROR, \
               ACE_TEXT ("val %d does not match expected value of %d\n"), \
               (int) (type) val, (int) (expval))); \
  } \
} while (0)

int
#if defined (ACE_HAS_NONSTATIC_OBJECT_MANAGER) || \
    defined (ACE_USES_WCHAR) || \
    defined (ACE_LACKS_FORK)
// Redefining main() only allows main to have two arguments.
// Using wide characters means translation and conditional passing of
// command line args and environment array.
// And on platforms that lack fork (), we can't use spawn.

ACE_TMAIN (int argc, ACE_TCHAR* [])
{
  ACE_UNUSED_ARG (argc);

  // Only Win32 can set wide-char environment strings. So, for all
  // others, use char string literals regardless of ACE_USES_WCHAR.
#  if defined (ACE_WIN32)
  ACE_OS::putenv (ACE_TEXT ("TEST_VALUE_POSITIVE=10.2"));
  ACE_OS::putenv (ACE_TEXT ("TEST_VALUE_NEGATIVE=-10.2"));
#  else
  ACE_OS::putenv ("TEST_VALUE_POSITIVE=10.2");
  ACE_OS::putenv ("TEST_VALUE_NEGATIVE=-10.2");
#  endif /* ACE_WIN32 */

#else  /* ! ACE_HAS_NONSTATIC_OBJECT_MANAGER  &&  ! ACE_LACKS_FORK */
ACE_TMAIN (int argc, ACE_TCHAR * [], ACE_TCHAR *envp[])
{
  if (argc == 1)
    {
      int status;

      // No arguments means we're the initial test.
      ACE_Process_Options options (1);
      status = options.setenv (envp);
      ACE_ASSERT (status == 0);

      options.command_line (ACE_TEXT (".") ACE_DIRECTORY_SEPARATOR_STR
                            ACE_TEXT ("Env_Value_Test run_as_test"));

      status = options.setenv (ACE_TEXT ("TEST_VALUE_POSITIVE"),
                               ACE_TEXT ("%s"),
                               ACE_TEXT ("10.2"));
      ACE_ASSERT (status == 0);
      status = options.setenv (ACE_TEXT ("TEST_VALUE_NEGATIVE"),
                               ACE_TEXT ("%s"),
                               ACE_TEXT ("-10.2"));
      ACE_ASSERT (status == 0);

      ACE_Process p;
      pid_t result = p.spawn (options);
      ACE_ASSERT (result != -1);
      p.wait ();
    }
  else
#endif /* ! ACE_HAS_NONSTATIC_OBJECT_MANAGER  &&  ! ACE_LACKS_FORK */
    {
      // In this case we're the child

    ACE_START_TEST (ACE_TEXT ("Env_Value_Test"));

      TEST_THIS (int, ACE_TEXT ("TEST_VALUE_POSITIVE"), 4, 10);
#if !defined (ACE_LACKS_FLOATING_POINT)
      TEST_THIS (double, ACE_TEXT ("TEST_VALUE_POSITIVE"), -1.0, 10.2);
#endif /* ! ACE_LACKS_FLOATING_POINT */
      TEST_THIS (long, ACE_TEXT ("TEST_VALUE_POSITIVE"), 0, 10);
      TEST_THIS (unsigned long, ACE_TEXT ("TEST_VALUE_POSITIVE"), 0, 10);
      TEST_THIS (short, ACE_TEXT ("TEST_VALUE_POSITIVE"), 0, 10);
      TEST_THIS (unsigned short, ACE_TEXT ("TEST_VALUE_POSITIVE"), 0, 10);

      TEST_THIS (int, ACE_TEXT ("TEST_VALUE_NEGATIVE"), 4, -10);
#if !defined (ACE_LACKS_FLOATING_POINT)
      TEST_THIS (double, ACE_TEXT ("TEST_VALUE_NEGATIVE"), -1.0, -10.2);
#endif /* ! ACE_LACKS_FLOATING_POINT */
      TEST_THIS (long, ACE_TEXT ("TEST_VALUE_NEGATIVE"), 0, -10L);
      TEST_THIS (unsigned long, ACE_TEXT ("TEST_VALUE_NEGATIVE"), 0, (unsigned long) -10);
      TEST_THIS (short, ACE_TEXT ("TEST_VALUE_NEGATIVE"), 0, -10);
      TEST_THIS (unsigned short, ACE_TEXT ("TEST_VALUE_NEGATIVE"), 0, (unsigned short) -10);

      const ACE_TCHAR *defstr = ACE_TEXT ("Sarah Cleeland is Two!");
      ACE_Env_Value<const ACE_TCHAR *> sval (ACE_TEXT ("This_Shouldnt_Be_Set_Hopefully"),
                                  defstr);
      ACE_ASSERT (ACE_OS::strcmp (sval, defstr) == 0);
      ACE_END_TEST;
    }
  return 0;
}
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class ACE_Env_Value<const char*>;
# if !defined (ACE_LACKS_FLOATING_POINT)
    template class ACE_Env_Value<double>;
# endif /* ! ACE_LACKS_FLOATING_POINT */
  template class ACE_Env_Value<int>;
  template class ACE_Env_Value<long>;
  template class ACE_Env_Value<short>;
  template class ACE_Env_Value<unsigned short>;
  template class ACE_Env_Value<unsigned long>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate  ACE_Env_Value<const char*>
# if !defined (ACE_LACKS_FLOATING_POINT)
#   pragma instantiate  ACE_Env_Value<double>
# endif /* ! ACE_LACKS_FLOATING_POINT */
# pragma instantiate  ACE_Env_Value<int>
# pragma instantiate  ACE_Env_Value<long>
# pragma instantiate  ACE_Env_Value<short>
# pragma instantiate  ACE_Env_Value<unsigned short>
# pragma instantiate  ACE_Env_Value<unsigned long>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
