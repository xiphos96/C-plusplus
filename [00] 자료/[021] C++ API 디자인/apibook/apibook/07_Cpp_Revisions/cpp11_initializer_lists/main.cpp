///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  A class that uses an initializer list constructor
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "myclass.h"

using namespace apibook;

int main(int, char **)
{
    MyClass obj1{1, 2, 3};  // calls initializer_list constructor
    MyClass obj2{1};        // calls initializer_list constructor
    MyClass obj3(1);        // calls single int constructor
    MyClass obj4{};         // calls default constructor
    MyClass obj5;           // calls default constructor

    return 0;
}
