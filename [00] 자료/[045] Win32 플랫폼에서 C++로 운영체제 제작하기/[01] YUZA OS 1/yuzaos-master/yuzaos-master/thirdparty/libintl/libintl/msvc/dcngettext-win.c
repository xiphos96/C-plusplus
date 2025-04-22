/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the libintl for msvc.
 * No warranty is given. You can use this at your own risk.
 */

#include <minwindef.h>
#include <wchar.h>
#include <winapi.h>
#include <memory.h>
#include "config.h"
#include "../intl/gettextP.h"

#if defined(_MSC_VER) && defined(_DEBUG)
#include <debug.h>
#endif

extern DLL_EXPORTED
const wchar_t *libintl_dciwgettext (const char *domainname, const wchar_t *wmsgid1, const wchar_t *wmsgid2,
	    int plural, unsigned long int n, int category);

/**
   This function is wchar_t version of dcngettext().
   Look up MSGID in the DOMAINNAME message catalog for the current CATEGORY
   locale.  */
DLL_EXPORTED
const wchar_t *libintl_dcnwgettext (const char *domainname,
	    const wchar_t *wmsgid1, const wchar_t *wmsgid2, unsigned long int n,
	    int category)
{
  return libintl_dciwgettext (domainname, wmsgid1, wmsgid2, 1, n, category);
}
