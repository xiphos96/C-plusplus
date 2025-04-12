///
/// \file   print_line.h
/// \author Martin Reddy
/// \brief  Use a variadic template to print variables to stdout
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef PRINT_LINE_H
#define PRINT_LINE_H

namespace apibook {

// variadic template to accept multiple arguments to print
template <typename T1, typename... T2>
void printLine(T1 var1, T2... var2);

}  // namespace apibook

#include "print_line_detail.h"

#endif