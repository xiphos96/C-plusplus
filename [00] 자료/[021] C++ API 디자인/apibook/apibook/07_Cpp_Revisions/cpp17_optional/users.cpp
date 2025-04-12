///
/// \file   users.cpp
/// \author Martin Reddy
/// \brief  Users class with a func that returns an std::optional
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "users.h"
#include <iostream>

namespace apibook {

User::User(const std::string &name, const std::string &id) :
    mName(name),
    mId(id)
{
}

std::string User::GetName() const
{
    return mName;
}

std::string User::GetId() const
{
    return mId;
}

void Users::Add(const User &user)
{
    mUsers.push_back(user);
}

std::optional<User> Users::FindById(const std::string &id)
{
    for (const auto &user : mUsers) {
        if (user.GetId() == id) {
            return user;
        }
    }
    return std::nullopt;
}

}  // namespace apibook
