// Obstack.cpp,v 4.10 2001/06/13 15:53:16 nanbor Exp

#include "ace/Obstack.h"

ACE_RCSID(ace, Obstack, "Obstack.cpp,v 4.10 2001/06/13 15:53:16 nanbor Exp")

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Obstack_T<char>;
#  if defined (ACE_HAS_WCHAR)
template class ACE_Obstack_T<wchar_t>;
#  endif /* ACE_HAS_WCHAR */
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Obstack_T<char>
#  if defined (ACE_HAS_WCHAR)
#    pragma instantiate ACE_Obstack_T<wchar_t>
#  endif /* ACE_HAS_WCHAR */
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
