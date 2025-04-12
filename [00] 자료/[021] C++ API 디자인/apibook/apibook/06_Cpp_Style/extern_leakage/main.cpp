///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Showing how "internal" details can be leaked.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "myobject.h"
#include <iostream>
#include <string>

// declare the external linkage elements of myobject.cpp
extern void FreeFunction();
extern int INTERNAL_CONSTANT;
extern std::string Filename;

int main(int, char **)
{
    // call a function hidden within the myobject.cpp module
    FreeFunction();

    // access a constant defined within myobject.cpp
    std::cout << "Internal constant = " << INTERNAL_CONSTANT << std::endl;

    // change global state within myobject.cpp
    Filename = "different.txt";

    return 0;
}
