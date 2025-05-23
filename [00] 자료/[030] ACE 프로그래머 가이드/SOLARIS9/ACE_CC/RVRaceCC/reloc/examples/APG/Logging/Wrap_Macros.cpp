#if defined (__GNUC__)
// The macros in Trace.h only work on g++

// Listing 1 code/ch03
#include "Trace.h"

void foo (void);

int ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE_TRACE (ACE_TEXT ("main"));
  MY_DEBUG (ACE_TEXT ("Hi Mom\n"));
  foo ();
  MY_DEBUG (ACE_TEXT ("Goodnight\n"));
  return 0;
}

void foo (void)
{
  ACE_TRACE (ACE_TEXT ("foo"));
  MY_DEBUG (ACE_TEXT ("Howdy Pardner\n"));
}
// Listing 1

#else
#include <stdio.h>

int main (int, char *[])
{
  puts ("This example only works on g++\n");
  return 0;
}

#endif /* __GNUC__ */
