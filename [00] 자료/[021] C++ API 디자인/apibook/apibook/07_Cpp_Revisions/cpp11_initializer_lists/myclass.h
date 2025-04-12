///
/// \file   myclass.h
/// \author Martin Reddy
/// \brief  A class that uses an initializer list constructor
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef MYCLASS_H
#define MYCLASS_H

#include <initializer_list>

namespace apibook {

class MyClass
{
public:
    /// default constructor
    MyClass();
    /// non-default constructor
    MyClass(int a);
    /// initializer list constructor
    MyClass(std::initializer_list<int> intList);
};

}  // namespace apibook

#endif