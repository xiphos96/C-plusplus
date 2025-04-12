///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Demonstrate the use of variadic templates.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "print_line.h"
#include <iostream>

using namespace apibook;

int main(int, char **)
{
    printLine("Hello World!");

    int numFiles = 5;
    float secs = 0.1;
    printLine("Wrote ", numFiles, " file(s) in ", secs, " secs.");

    return 0;
}
