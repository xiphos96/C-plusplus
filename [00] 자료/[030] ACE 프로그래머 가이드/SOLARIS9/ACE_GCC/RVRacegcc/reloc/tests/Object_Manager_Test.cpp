// Object_Manager_Test.cpp,v 4.5 2002/03/06 21:48:03 nanbor Exp

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Object_Manager_Test.cpp
//
// = DESCRIPTION
//    Tests the basic functions of the ACE_Object_Manager.
//
// = AUTHOR
//    David L. Levine <levine@cs.wustl.edu>
//
// ============================================================================

#include "test_config.h"
#include "ace/Object_Manager.h"

ACE_RCSID(tests, Object_Manager_Test, "Object_Manager_Test.cpp,v 4.5 2002/03/06 21:48:03 nanbor Exp")

static u_int *ip;

extern "C"
void
hook1 (void)
{
  delete ip;
  ip = 0;
}

extern "C"
void
hook2 (void * /* object */, void *param)
{
  u_int *paramp = ACE_reinterpret_cast (u_int *, param);

  // We can use ACE_Log_Msg in an ACE_Object_Manager cleanup hook.
  // But NOT in an ACE_OS::atexit () hook!  However, the ACE_END_TEST
  // invocation in main () will prevent this from being output to the
  // log stream.
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("hook2: %d\n"),
              *paramp));
  delete paramp;
}

int
ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE::init ();

  ACE_START_TEST (ACE_TEXT ("Object_Manager_Test"));

  u_int errors = 0;

  // If hook1 never gets called, this will show up as a memory leak.
  ACE_NEW_RETURN (ip,
                  u_int,
                  -1);

  const int starting_up =
    ACE_Object_Manager::instance ()->starting_up ();
  const int shutting_down =
    ACE_Object_Manager::instance ()->shutting_down ();

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("starting_up: %d, shutting_down: %d\n"),
              starting_up,
              shutting_down));

  if (starting_up || shutting_down)
    {
      ++errors;
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%p\n"),
                  ACE_TEXT ("starting_up and shutting_down are supposed to ")
                  ACE_TEXT (" be 0!!!!")));
    }

  if (ACE_OS::atexit (hook1) != 0)
    {
      ++errors;
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%p\n"),
                  ACE_TEXT ("ACE_OS::atexit () returned non-zero!!!!")));
    }

  for (u_int i = 0; i < 10; ++i)
    {
      u_int *paramp;
      ACE_NEW_RETURN (paramp,
                      u_int,
                      -1);
      *paramp = i;

      // The first paramp argument is only used to distinguish the
      // at_exit entries.  The ACE_Object_Manager only allows one
      // at_exit per object.  It's not used in the hook.
      if (ACE_Object_Manager::instance ()->at_exit (paramp,
                                                    hook2,
                                                    paramp))
        {
          ++errors;
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%p\n"),
                      ACE_TEXT ("ACE_Object_Manager::at_exit () ")
                      ACE_TEXT ("returned non-zero!!!!")));
        }
    }

  ACE_END_TEST;
  ACE::fini ();
  return errors == 0 ? 0 : 1;
}
