///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Demonstrating good C++ operator style.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "currency.h"
#include <iostream>

using namespace apibook;

int main(int, char **)
{
    // use one of the operator functions of Currency
    Currency c1(100);
    Currency c2(150);

    c1 += c2;

    std::cout << "Currency: " << c1 << std::endl;

    return 0;
}
