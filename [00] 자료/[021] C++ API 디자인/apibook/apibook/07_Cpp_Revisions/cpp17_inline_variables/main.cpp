///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Illustrate the use of inline variables in C++17.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "myclass.h"
#include <iostream>

using namespace apibook;

int main(int, char **)
{
    MyClass obj;

    std::cout << "Version = " << obj.VERSION << std::endl;
    std::cout << "Updated = " << MyClass::UPDATED << std::endl;

    return 0;
}
