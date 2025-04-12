///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Demonstrate the override and final specifiers.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "overrides.h"
#include <iostream>
#include <string>

using namespace apibook;

void DescribeClass(const std::string &name, Base *cls)
{
    std::cout << "=== " << name << std::endl;
    cls->VirtualMethod();
    cls->EventuallyFinalMethod();
    cls->NonVirtualMethod();
}

int main(int argc, char *argv[])
{
    Base base;
    DescribeClass("Base", &base);

    Derived derived;
    DescribeClass("Derived", &derived);

    FurtherDerived further;
    DescribeClass("FurtherDerived", &further);

    return 0;
}
