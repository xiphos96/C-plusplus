///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  C++11 move constructors and move assignment operators
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "array.h"
#include <cassert>
#include <utility>

using namespace apibook;

int main(int, char **)
{
    // create an array, calling the non-default constructor
    Array array1(2);
    array1.Set(0, "Hello");
    array1.Set(1, "World");
    array1.Print();
    assert(array1.IsDefined());

    // call the move constructor
    Array array2(std::move(array1));
    assert(!array1.IsDefined());
    assert(array2.IsDefined());

    // call the move assignment operator
    Array array3;
    array3 = std::move(array2);

    return 0;
}
