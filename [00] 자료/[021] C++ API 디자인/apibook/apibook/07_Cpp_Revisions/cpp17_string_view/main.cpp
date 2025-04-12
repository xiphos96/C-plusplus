///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Demonstrate use of std::string_view in C++17
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "name_holder.h"
#include <iostream>

using namespace apibook;

int main(int, char **)
{
    std::string str = "std::string name";
    std::string_view str_view = "std::string_view name";
    const char *str_c = "c_str name";

    std::cout << STRING_CONSTANT << std::endl;
    std::cout << NameHolder(str).GetName() << std::endl;
    std::cout << NameHolder(str_view).GetName() << std::endl;
    std::cout << NameHolder(str_c).GetName() << std::endl;

    return 0;
}
