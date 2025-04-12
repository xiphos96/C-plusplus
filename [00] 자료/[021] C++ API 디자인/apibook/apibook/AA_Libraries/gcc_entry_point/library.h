///
/// \file   library.h
/// \author Martin Reddy
/// \brief  An example of a shared library with entry points
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>

extern "C" {

void DoSomething(const std::string &name);
}

#endif
