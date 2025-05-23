///
/// \file   stringutil.cpp
/// \author Martin Reddy
/// \brief  A string conversion utility to be unit tested.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "stringutil.h"

#include <stdlib.h>

bool StringToDouble(const std::string &str, double &result)
{
    const char *ptr = str.c_str();
    char *endptr = nullptr;
    result = strtod(ptr, &endptr);
    return (ptr != endptr && endptr[0] == '\0');
}
