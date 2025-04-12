///
/// \file   deprecate.h
/// \author Martin Reddy
/// \brief  Function to deprecate functionality.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef DEPRECATE_H
#define DEPRECATE_H

#include <string>

/// Output a one-time deprecation warning and suggest an alternative
void Deprecated(const std::string oldfunc, const std::string newfunc = "");

#endif
