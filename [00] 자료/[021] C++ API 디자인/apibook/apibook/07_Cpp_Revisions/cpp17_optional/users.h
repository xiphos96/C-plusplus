///
/// \file   user.h
/// \author Martin Reddy
/// \brief  Users class with a func that returns an std::optional
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef USERS_H
#define USERS_H

#include <optional>
#include <string>
#include <vector>

namespace apibook {

/// hold a single user
class User
{
public:
    /// for this example, a user has a name and an ID
    User(const std::string &name, const std::string &id);
    std::string GetName() const;
    std::string GetId() const;

private:
    std::string mName;
    std::string mId;
};

/// hold a list of users with the ability to find users
class Users
{
public:
    /// add a new user to the list of users
    void Add(const User &user);

    /// search for a user by ID, returning an std::optional
    std::optional<User> FindById(const std::string &id);

private:
    std::vector<User> mUsers;
};

}  // namespace apibook

#endif