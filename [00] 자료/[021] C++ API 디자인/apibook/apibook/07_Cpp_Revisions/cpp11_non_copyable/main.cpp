///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  A non-copyable base class using delete/default
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "non_copyable.h"
#include <cassert>
#include <utility>

using namespace apibook;

class MyClass : public NonCopyable
{
};

int main(int, char **)
{
    MyClass obj;

    // Compiler error: base class has a deleted copy assignment operator
    // MyClass obj2;
    // obj2 = obj;

    // Compiler error: base class has a deleted copy constructor
    // MyClass obj3 = obj;

    return 0;
}
