///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Demonstrate the use of variable templates.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include <iomanip>
#include <iostream>

template <typename T>
constexpr T pi = 3.1415926535897932385;

template <>
constexpr float pi<float> = 3.1415;

template <>
const std::string pi<std::string> = "pi";

int main(int, char **)
{
    std::cout << std::setprecision(9) << pi<int> << std::endl;
    std::cout << std::setprecision(9) << pi<float> << std::endl;
    std::cout << std::setprecision(9) << pi<double> << std::endl;
    std::cout << pi<std::string> << std::endl;

    return 0;
}
