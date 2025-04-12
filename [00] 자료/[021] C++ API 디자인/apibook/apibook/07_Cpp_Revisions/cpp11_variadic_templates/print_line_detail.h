///
/// \file   print_line_deatil.h
/// \author Martin Reddy
/// \brief  Implementation for the variadic template
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef PRINT_LINE_DETAIL_H
#define PRINT_LINE_DETAIL_H

#include <iostream>

namespace apibook {

void printLine()
{
    std::cout << std::endl;
}

template <typename T1, typename... T2>
void printLine(T1 var1, T2... var2)
{
    std::cout << var1;
    printLine(var2...);
}

}  // namespace apibook

#endif