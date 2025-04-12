///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Demonstrate the user of C++17's std::any.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include <any>
#include <cassert>

int main(int, char **)
{
    // new std::any holds no value
    std::any anyVal;
    assert(!anyVal.has_value());

    // hold an integer value
    anyVal = 5;
    assert(anyVal.has_value());
    assert(anyVal.type() == typeid(int));
    assert(std::any_cast<int>(anyVal) == 5);

    // change to holding a string value
    anyVal = "Hello";
    assert(anyVal.has_value());
    assert(anyVal.type() == typeid(const char *));

    // clear out the value
    anyVal.reset();
    assert(!anyVal.has_value());

    return 0;
}
