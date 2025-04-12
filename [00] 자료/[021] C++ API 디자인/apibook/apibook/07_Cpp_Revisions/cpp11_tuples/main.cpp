///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Illustrate the use of tuples to return data
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include <iostream>
#include <tuple>

class User
{
public:
    // return the user's name, ID, and whether they're an admin
    std::tuple<std::string, int, bool> GetInfo() const
    {
        return {"Fred", 123456, false};
    }
};

int main(int, char **)
{
    // can only reference tuple data with a compile-time constant index
    // using a class/struct with named elements would be a better design
    auto user = User().GetInfo();
    std::cout << "Name = " << std::get<0>(user) << std::endl;
    std::cout << "UserId = " << std::get<1>(user) << std::endl;
    std::cout << "IsAdmin = " << std::get<2>(user) << std::endl;

    return 0;
}
