///
/// \file   myclass.cpp
/// \author Martin Reddy
/// \brief  A class that uses an initializer list constructor
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "myclass.h"
#include <iostream>

namespace apibook {

MyClass::MyClass()
{
    std::cout << "default constructor" << std::endl;
}

MyClass::MyClass(int a)
{
    std::cout << "non-default constructor with value " << a << std::endl;
}

MyClass::MyClass(std::initializer_list<int> intList)
{
    std::cout << "initializer list constructor with " << intList.size() << " elements" << std::endl;
}

}  // namespace apibook
