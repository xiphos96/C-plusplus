///
/// \file   myclass.cpp
/// \author Martin Reddy
/// \brief  Example class to demonstrate deprecation.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "myclass.h"
#include "deprecated.h"

std::string MyClass::GetName()
{
    Deprecated("MyClass::GetName", "MyClass::GetFullName");
    return "Name";
}

std::string MyClass::GetFullName()
{
    return "FullName";
}
