///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Demonstrate the use of C++17's std::optional<>
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "users.h"
#include <iostream>

using namespace apibook;

int main(int, char **)
{
    // create a list of users with names and IDs
    Users users;
    users.Add(User("User 1", "id_123"));
    users.Add(User("User 2", "id_456"));
    users.Add(User("User 3", "id_789"));

    // FindById() returns an std::optional<User>
    auto match = users.FindById("id_456");
    if (match) {
        std::cout << "Found user " << match->GetName() << std::endl;
    }

    return 0;
}
