// Dirent_Test.cpp,v 1.5 2003/08/08 20:14:37 boris Exp
// Dirent_Test.cpp,v 4.8 2002/03/12 17:59:10 elliott_c Exp

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Dirent_Test.cpp
//
// = DESCRIPTION
//     This is a test of the opendir and readdir emulation provided by the
//     class ACE_OS_Dirent.  It is used to ensure that the emulation code
//     works properly on platforms that don't support this capability
//     natively.  As the emulation code is not compiled in other
//     platforms, this test also ensures that there is no impact to
//     platforms that natively support directory scanning operations.
//
//     Note that dirent is not always native - ACE_LACKS_STRUCT_DIR determines
//     if dirent is defined internally in ace/OS_Dirent.h. If it is, the
//     name strings are ACE_TCHAR*, else they're char*. This is reflected in
//     logging operations using those names herein.
//
// = AUTHOR
//    Phil Mesnier <mesnier_p@ociweb.com>,
//    Rich Newman <RNewman@directv.com>, and
//    Douglas C. Schmidt <schmidt@uci.edu>
//
// ============================================================================

#include "test_config.h"
#include "ace/OS.h"
#include "ace/OS_String.h"
#include "ace/Dirent.h"
#include "ace/Dirent_Selector.h"

ACE_RCSID(tests, Dirent_Test, "Dirent_Test.cpp,v 1.5 2003/08/08 20:14:37 boris Exp")

#if defined (VXWORKS) || defined(CHORUS)
#  define TEST_DIR "."
#  define TEST_ENTRY ".."
#elif defined (ACE_HAS_WINCE)
  // The WinCE environment doesn't have access to the whole ACE tree. Each
  // test is copied down to \Windows. For details, see
  // ACE_wrappers\bin\PerlACE\Process_Win32.pm.
#  define TEST_DIR "\\Windows\\Start Menu"
#  define TEST_ENTRY "Dirent_Test.exe"
#else
#  define TEST_DIR "../tests"
#  define TEST_ENTRY "Dirent_Test.cpp"
#endif /* VXWORKS || CHORUS */

// Number of entries in the directory.
static int entrycount = 0;

static int
selector (const dirent *d)
{
  // Non-Windows don't offer wide-char names in dirent, so special-case
  // the name selection.
#if defined (ACE_LACKS_STRUCT_DIR)
  return ACE_OS_String::strcmp (d->d_name, ACE_TEXT (TEST_ENTRY)) == 0;
#else
  return ACE_OS_String::strcmp (d->d_name, TEST_ENTRY) == 0;
#endif
}

static int
comparator (const dirent **d1, const dirent **d2)
{
  return ACE_OS_String::strcmp ((*d1)->d_name, (*d2)->d_name);
}

static int
dirent_selector_test (void)
{
  int status;
  int n;

  ACE_Dirent_Selector sds;

  // Pass in functions that'll specify the selection criteria.
  status = sds.open (ACE_TEXT (TEST_DIR), selector, comparator);
  ACE_ASSERT (status != -1);

  // We should only have located ourselves!
  ACE_ASSERT (sds.length () == 1);

  for (n = 0; n < sds.length (); ++n)
    {
#if defined (ACE_LACKS_STRUCT_DIR)
      ACE_DEBUG ((LM_DEBUG, 
                  ACE_TEXT ("Sorted: %d: %s\n"),
                  n,
                  sds[n]->d_name));
#else
      ACE_DEBUG ((LM_DEBUG, 
                  ACE_TEXT ("Sorted: %d: %s\n"),
                  n,
                  ACE_TEXT_CHAR_TO_TCHAR (sds[n]->d_name)));
#endif /* ACE_LACKS_STRUCT_DIR */
    }

  status = sds.close ();
  ACE_ASSERT (status != -1);

  ACE_Dirent_Selector ds;

  // Don't specify any selection criteria.
  status = ds.open (ACE_TEXT (TEST_DIR));
  ACE_ASSERT (status != -1);

  ACE_ASSERT (entrycount == ds.length ());

  for (n = 0; n < ds.length (); ++n)
    {
#if defined (ACE_LACKS_STRUCT_DIR)
      ACE_DEBUG ((LM_DEBUG, 
                  ACE_TEXT ("Entry %d: %s\n"),
                  n,
                  ds[n]->d_name));
#else
      ACE_DEBUG ((LM_DEBUG, 
                  ACE_TEXT ("Entry %d: %s\n"),
                  n,
                  ACE_TEXT_CHAR_TO_TCHAR (ds[n]->d_name)));
#endif /* ACE_LACKS_STRUCT_DIR */
    }

  status = ds.close ();
  ACE_ASSERT (status != -1);

  return status;
}

static int
dirent_test (void)
{
  ACE_Dirent dir (ACE_TEXT (TEST_DIR));

  for (dirent *directory;
       (directory = dir.read ()) != 0;
       entrycount++)
    {
#if defined (ACE_LACKS_STRUCT_DIR)
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("Entry %d: %s\n"),
                  entrycount,
                  directory->d_name));
#else
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("Entry %d: %s\n"),
                  entrycount,
                  ACE_TEXT_CHAR_TO_TCHAR (directory->d_name)));
#endif /* ACE_LACKS_STRUCT_DIR */
    }

  switch (entrycount) 
    {
    case 0: 
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("readdir failed to read anything\n")),
                        -1);
      /* NOTREACHED */
    case 1:
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("readdir failed, only matched directory name\n")),
                        -1);
      /* NOTREACHED */
    default:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("readdir succeeded, read %d entries\n"),
                  entrycount));
    }
  return 0;
}

int
ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE_START_TEST (ACE_TEXT ("Dirent_Test"));

  int status = dirent_test ();

  if (status != -1)
    status = dirent_selector_test ();

  ACE_END_TEST;
  return status;
}
