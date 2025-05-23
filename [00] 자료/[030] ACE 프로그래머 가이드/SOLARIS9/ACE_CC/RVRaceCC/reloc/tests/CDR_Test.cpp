// CDR_Test.cpp,v 1.26 2002/08/27 17:36:27 shuston Exp

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    CDR_Test.cpp
//
// = DESCRIPTION
//    Checks the functionality of the ACE CDR streams.
//
// = AUTHORS
//    Istvan Buki <istvan.buki@euronet.be> and
//    Jeff Parsons <parsons@cs.wustl.edu> and
//    Carlos O'Ryan <coryan@cs.wustl.edu>
//
// ============================================================================

#include "test_config.h"
#include "ace/Get_Opt.h"
#include "ace/Auto_Ptr.h"
#include "ace/CDR_Stream.h"
#include "ace/SString.h"

ACE_RCSID(tests, CDR_Test, "CDR_Test.cpp,v 1.26 2002/08/27 17:36:27 shuston Exp")

static int n = 4096;
static int nloops = 100;

struct CDR_Test_Types
{
  CDR_Test_Types (void);

  ACE_CDR::Octet o;
  ACE_CDR::Short s;
  ACE_CDR::Long l;
  const ACE_CDR::Char *str;
  const ACE_CDR::WChar *wstr;
  ACE_CDR::Double d;

  int test_put (ACE_OutputCDR& cdr);
  int test_get (ACE_InputCDR& cdr) const;

  enum
  {
    ARRAY_SIZE = 10
  };

  ACE_CDR::Short a[ARRAY_SIZE];
};

CDR_Test_Types::CDR_Test_Types (void)
  : o (1),
    s (2),
    l (4),
    str ("abc"),
    wstr (0),
    d (8)
{
  for (int i = 0;
       i < CDR_Test_Types::ARRAY_SIZE;
       ++i)
    a[i] = i;
}

static int
short_stream (void)
{
  // counter
  u_int i;

  // Build an output stream
  ACE_OutputCDR os;

  // Basic types for output
  ACE_CDR::Char ch = 'A';
  ACE_CDR::Char wchtmp[] = {"\xF3"};
  ACE_CDR::WChar wch = *wchtmp;
  ACE_CDR::WChar wchar2[] = {'\x00'};    // empty wide string
  ACE_CDR::WChar *wstr = wchar2;
  ACE_CString str ("Test String");
  ACE_CDR::Short s = -123;
  ACE_CDR::UShort us =  123;
  ACE_CDR::Long l = -65800L;
  ACE_CDR::ULong ul =  65800UL;
  ACE_CDR::Float f =  1.23f;
  ACE_CDR::Double d =  123.456789;

  // Arrays for output
  ACE_CDR::Short s_array[3] = { -1, 0, 1 };
  ACE_CDR::Long l_array[3] = { -345678, 0, 345678 };
  ACE_CDR::Float f_array[3] = { -1.23f, 0.0f, 1.23f };
  ACE_CDR::Double d_array[3] = { -123.456789, 0.0, 123.456789 };

  ACE_OutputCDR::from_char fc (ch);
  os << fc;
  ACE_OutputCDR::from_wchar fwc (wch);
  os << fwc;
  os << str;
  os << wstr;
  os << s;
  os << us;
  os << l;
  os << ul;
  os << f;
  os << d;
  os.write_short_array (s_array, 3);
  os.write_long_array (l_array, 3);
  os.write_float_array (f_array, 3);
  os.write_double_array (d_array, 3);

  const ACE_Message_Block *out_mb = os.begin ();
  size_t len = out_mb->length ();

  // Create an input stream (copy constructor)
  ACE_InputCDR is (os);
  const ACE_Message_Block *in_mb = is.start ();

  if (in_mb->length () != len)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("buffer length not preserved")),
                      1);

  u_long in_chunk, out_chunk;

  for (i = 0; i < len; i++)
    {
      in_chunk = u_long (* (in_mb->rd_ptr () + i));
      out_chunk = u_long (* (out_mb->rd_ptr () + i));
      if (in_chunk != out_chunk )
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("buffer contents not preserved")),
                          1);
    }

  // Basic types for input
  ACE_CDR::Char ch1 = '\0';
  ACE_CDR::WChar wch1 = '\x00';
  ACE_CDR::WChar *wstr1 = 0;
  ACE_CString str1;
  ACE_CDR::Short s1 = 0;
  ACE_CDR::UShort us1 = 0;
  ACE_CDR::Long l1 = 0L;
  ACE_CDR::ULong ul1 = 0UL;
  ACE_CDR::Float f1 = 0.0f;
  ACE_CDR::Double d1 = 0.0;

  // Arrays for input
  ACE_CDR::Short s_array1[3];
  ACE_CDR::Long l_array1[3];
  ACE_CDR::Float f_array1[3];
  ACE_CDR::Double d_array1[3];

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Checking operators and arrays\n\n")));

  ACE_InputCDR::to_char tc (ch1);
  is >> tc;
  ACE_InputCDR::to_wchar twc (wch1);
  is >> twc;
  is >> str1;
  is >> wstr1;
  is >> s1;
  is >> us1;
  is >> l1;
  is >> ul1;
  is >> f1;
  is >> d1;
  is.read_short_array (s_array1, 3);
  is.read_long_array (l_array1, 3);
  is.read_float_array (f_array1, 3);
  is.read_double_array (d_array1, 3);

  if (ch1 != ch)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("char transfer error")),
                      1);

  if (wch1 != wch)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("wchar transfer error")),
                      1);

  if (str1 != str)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("string transfer error")),
                      1);

  if (ACE_OS::wscmp(wstr1, wstr))
     ACE_ERROR_RETURN ((LM_ERROR,
                        ACE_TEXT ("%p\n"),
                        ACE_TEXT ("wide string transfer error")),
                       1);


  if (s1 != s)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("short transfer error")),
                      1);

  if (us1 != us)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("ushort transfer error")),
                      1);

  if (l1 != l)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("long transfer error")),
                      1);

  if (ul1 != ul)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("ulong transfer error")),
                      1);

  if (f1 != f)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("float transfer error")),
                      1);

  if (d1 != d)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("double transfer error")),
                      1);

  for (i = 0 ; i < 3; i++)
    if (s_array1[i] != s_array[i])
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("short array transfer error")),
                        1);

  for (i = 0 ; i < 3; i++)
    if (l_array1[i] != l_array[i])
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("long array transfer error")),
                        1);

  for (i = 0 ; i < 3; i++)
    if (f_array1[i] != f_array[i])
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("float array transfer error")),
                        1);

  for (i = 0 ; i < 3; i++)
    if (d_array1[i] != d_array[i])
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("double array transfer error")),
                        1);

  return 0;
}

int
CDR_Test_Types::test_put (ACE_OutputCDR &cdr)
{
  for (int i = 0; i < n; ++i)
    {
      if (cdr.write_octet (this->o) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("write_octet[%d] failed\n"),
                           i),
                          1);
      if (cdr.write_short (this->s) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("write_short[%d] failed\n"),
                           i),
                          1);
      if (cdr.write_octet (this->o) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("write_octet-2[%d] failed\n"),
                           i),
                          1);
      if (cdr.write_long (this->l) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("write_long[%d] failed\n"),
                           i),
                          1);
      if (cdr.write_long (this->l) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("write_long-2[%d] failed\n"),
                           i),
                          1);

      if (cdr.write_string (this->str) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("write_string[%d] failed\n"),
                           i),
                          1);

      if (cdr.write_wstring (this->wstr) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("write_wstring[%d] failed\n"),
                           i),
                          1);

    }

  return 0;
}

int
CDR_Test_Types::test_get (ACE_InputCDR &cdr) const
{
  ACE_CDR::Octet xo;
  ACE_CDR::Short xs;
  ACE_CDR::Long xl;

  for (int i = 0; i < n; ++i)
    {
      if (cdr.read_octet (xo) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("read_octet[%d] failed\n"),
                           i),
                          1);
      if (xo != this->o)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("octet[%d] differs\n"),
                           i),
                          1);
      if (cdr.read_short (xs) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("read_short[%d] failed\n"),
                           i), 1);
      if (xs != this->s)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("short[%d] differs\n"),
                           i),
                          1);
      if (cdr.read_octet (xo) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("read_octet-2[%d] failed\n"),
                           i),
                          1);
      if (xo != this->o)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("octet-2[%d] differs\n"),
                           i),
                          1);
      if (cdr.read_long (xl) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("read_long[%d] failed\n"),
                           i),
                          1);
      if (xl != this->l)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("long[%d] differs\n"),
                           i),
                          1);
      if (cdr.read_long (xl) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("read_long-2[%d] failed\n"),
                           i),
                          1);
      if (xl != this->l)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("long-2[%d] differs\n"),
                           i),
                          1);

      ACE_CDR::Char *xstr;
      if (cdr.read_string (xstr) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("read_string2[%d] failed\n"),
                           i),
                          1);
      ACE_Auto_Basic_Array_Ptr<ACE_CDR::Char> auto_xstr (xstr);
      if (ACE_OS::strcmp (auto_xstr.get (), this->str) != 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("string[%d] differs\n"),
                           i),
                          1);

      ACE_CDR::WChar *wstr1;
      if (cdr.read_wstring (wstr1) == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                            ACE_TEXT ("read_wstring2[%d] failed\n"),
                            i),
                           1);
      // zero length
      ACE_Auto_Basic_Array_Ptr<ACE_CDR::WChar> auto_xwstr (wstr1);
       if (ACE_OS::wslen(auto_xwstr.get () ))
         ACE_ERROR_RETURN ((LM_ERROR,
                            ACE_TEXT ("wstring[%d] differs\n"),
                             i),
                            1);
    }
  return 0;
}

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_START_TEST (ACE_TEXT ("CDR_Test"));

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("This is ACE Version %u.%u.%u\n\n"),
              ACE::major_version (),
              ACE::minor_version(),
              ACE::beta_version()));

  ACE_Get_Opt get_opt (argc, argv, ACE_TEXT ("dn:l:"));
  int opt;
  int debug = 0;

  while ((opt = get_opt ()) != EOF)
    {
      switch (opt)
        {
          case 'd':
            debug++;
            break;
          case 'n':
            n = ACE_OS::atoi (get_opt.opt_arg ());
            break;
          case 'l':
            nloops = ACE_OS::atoi (get_opt.opt_arg ());
            break;
          case '?':
          default:
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("Usage: %s ")
                        ACE_TEXT ("-d debug")
                        ACE_TEXT ("-n <num> ")
                        ACE_TEXT ("-l <loops> ")
                        ACE_TEXT ("\n"),
                        argv[0]));
            return -1;
        }
    }

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Testing ACE CDR functions - short stream\n\n")));

  if (short_stream () != 0 )
    return 1;

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Short stream - no errors\n\n")
              ACE_TEXT ("Testing basic types - long stream\n\n")));

  for (int i = 0; i < nloops; ++i)
    {
      ACE_OutputCDR output;
      CDR_Test_Types test_types;

      if (test_types.test_put (output) != 0)
        return 1;

      ACE_InputCDR input (output);
      if (debug > 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("Output CDR: \n")));
          ACE_HEX_DUMP ((LM_DEBUG,
                         input.rd_ptr(),
                         64));
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("Input CDR: \n")));
          ACE_HEX_DUMP ((LM_DEBUG,
                         input.rd_ptr(),
                         64));
        }

      if (test_types.test_get (input) != 0)
        return 1;
    }

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Long stream - no errors\n\n")
              ACE_TEXT ("Testing basic types - long stream[2]\n\n")));

  for (int j = 0; j < nloops; ++j)
    {
      ACE_OutputCDR output;
      CDR_Test_Types test_types;

      if (test_types.test_put (output) != 0)
        return 1;

      ACE_InputCDR input (output.begin ());
      if (debug > 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("Output CDR: \n")));
          ACE_HEX_DUMP ((LM_DEBUG,
                         input.rd_ptr(),
                         64));
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("Input CDR: \n")));
          ACE_HEX_DUMP ((LM_DEBUG,
                         input.rd_ptr(),
                         64));
        }

      if (test_types.test_get (input) != 0)
        return 1;
    }

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Long stream[2] - no errors\n\n")));

  ACE_END_TEST;
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

// Not necessary here, because it's instantiated in
// ace/Memory_Pool.cpp.
// template class ACE_Auto_Basic_Array_Ptr<ACE_CDR::Char>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

// Not necessary here, because it's instantiated in
// ace/Memory_Pool.cpp.
// #pragma instantiate ACE_Auto_Basic_Array_Ptr<ACE_CDR::Char>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
