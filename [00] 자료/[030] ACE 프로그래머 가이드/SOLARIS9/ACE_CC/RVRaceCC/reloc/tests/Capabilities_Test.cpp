// Capabilities_Test.cpp,v 4.13 2002/03/06 21:48:03 nanbor Exp

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Capabilities_Test.cpp
//
// = DESCRIPTION
//      This is a test that makes sure the <ACE_Capabililties> class
//      works correctly.
//
// = AUTHOR
//    Arturo Montes <mitosys@colomsat.net.co>
//
// ============================================================================

#include "ace/Capabilities.h"
#include "test_config.h"

ACE_RCSID(tests, Capabilities_Test, "Capabilities_Test.cpp,v 4.13 2002/03/06 21:48:03 nanbor Exp")

static const ACE_TCHAR config[] = ACE_TEXT ("Capabilities_Test.cfg");

static int
load_config (void)
{
  ACE_Capabilities caps;
  if (caps.getent (config, ACE_TEXT ("Config")) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("Can't read %s\n"),
                       config),
                      1);

  int b = 0;
  caps.getval (ACE_TEXT ("bool"), b);
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("bool = %d\n"),
              b));

  int n = 0;
  caps.getval (ACE_TEXT ("integer"), n);

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("integer = %d\n"),
              n));

  ACE_TString s;
  caps.getval (ACE_TEXT ("string"), s);

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("string = %s\n"),
              s.c_str ()));
  return 0;
}

int
ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE_START_TEST (ACE_TEXT ("Capabilities_Test"));


  // --------------------------------------------------------
  // Create config file
  // --------------------------------------------------------

  // A config file is created within the test so that the test is
  // completely self contained.

  const char file_contents[] =
    "Config|Esta entrada reservada para la configuracion,\n"
    "   bool,\n"
    "   integer#2,\n"
    "   string=000030,\n\n";

  ACE_HANDLE fd = ACE_OS::open (config,
                                O_RDWR | O_CREAT | O_TRUNC,
                                ACE_DEFAULT_FILE_PERMS);

  if (fd == ACE_INVALID_HANDLE)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("ACE_OS::open")),
                      -1);


  if (ACE_OS::write (fd, file_contents, sizeof(file_contents)) !=
      sizeof(file_contents))
    {
      ACE_OS::unlink (config);
      ACE_OS::close (fd);
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("ACE_OS::write")),
                        -1);
    }

  if (ACE_OS::close (fd) != 0)
    {
      ACE_OS::unlink (config);
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("ACE_OS::close")),
                        -1);
    }
  // --------------------------------------------------------


  int result = load_config ();

  ACE_OS::unlink (config);

  ACE_END_TEST;
  return result;
}
