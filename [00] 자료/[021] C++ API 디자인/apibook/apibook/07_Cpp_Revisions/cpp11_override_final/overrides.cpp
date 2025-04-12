///
/// \file   overrides.cpp
/// \author Martin Reddy
/// \brief  Class hierarchy using override and final keywords.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "overrides.h"
#include <iostream>

using std::cout;
using std::endl;

namespace apibook {

Base::~Base() = default;

void Base::VirtualMethod()
{
    cout << "Base::VirtualMethod()" << endl;
}

void Base::EventuallyFinalMethod()
{
    cout << "Base::EventuallyFinalMethod()" << endl;
}

void Base::NonVirtualMethod()
{
    cout << "Base::NonVirtualMethod()" << endl;
}

Derived::~Derived() = default;

void Derived::VirtualMethod()
{
    cout << "Derived::VirtualMethod()" << endl;
}

void Derived::EventuallyFinalMethod()
{
    cout << "Derived::EventuallyFinalMethod()" << endl;
}

FurtherDerived::~FurtherDerived() = default;

void FurtherDerived::VirtualMethod()
{
    cout << "FurtherDerived::VirtualMethod()" << endl;
}

}  // namespace apibook
