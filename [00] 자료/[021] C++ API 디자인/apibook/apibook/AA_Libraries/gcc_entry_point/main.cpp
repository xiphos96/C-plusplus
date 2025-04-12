///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Demonstrate API entry and exit points in GCC.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "library.h"
#include <string>

int main(int argc, char **)
{
    DoSomething("Hello");
    return 0;
}
