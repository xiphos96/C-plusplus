// -*- C++ -*-

//=============================================================================
/**
 *  @file    Encoding.h
 *
 * This file provides utility functions to determine the encoding of a file
 * or a byte stream automatically.
 *
 *  Encoding.h,v 1.1 2002/10/15 22:21:35 kitty Exp
 *
 *  @author Krishnakumar B <kitty@cs.wustl.edu>
 */
//=============================================================================

#ifndef _ACEXML_ENCODING_H
#define _ACEXML_ENCODING_H

#include "ace/pre.h"
#include "ACEXML/common/ACEXML_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ACEXML/common/XML_Types.h"

/**
 * @class ACEXML_Encoding Encoding.h "ACEXML/common/Encoding.h"
 *
 * @brief ACEXML_Encoding
 *
 * Wrapper class for determining the encoding of a file or a byte stream.
 */
class ACEXML_Export ACEXML_Encoding
{
public:
  enum {
    UCS4BE = 0,
    UCS4LE = 1,
    UCS4_2143 = 2,
    UCS4_3412 = 3,
    UTF16BE = 4,
    UTF16LE = 5,
    UTF8 = 6,
    OTHER = 7
  } ENCODING;

  static const ACEXML_Char* encoding_names_[8];

  static const ACEXML_UTF8 byte_order_mark_[][4];

  static const ACEXML_UTF8 magic_values_[][4];

  static const ACEXML_Char* get_encoding (const char* input);

};

#include "ace/post.h"

#endif /* _ACEXML_ENCODING_H */
