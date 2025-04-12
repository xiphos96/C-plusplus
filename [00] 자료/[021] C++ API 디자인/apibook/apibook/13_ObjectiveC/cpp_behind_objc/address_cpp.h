///
/// \file   address_cpp.h
/// \author Martin Reddy
/// \brief  A C++ API to store a person in an address book.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include <memory>
#include <string>

namespace address {

class Person
{
public:
    Person();

    // The given name is normally the first name
    void SetGivenName(const std::string &name);
    std::string GetGivenName() const;

    // The family name is normally the surname
    void SetFamilyName(const std::string &name);
    std::string GetFamilyName() const;

    // The nickname is an alternative first name
    void SetNickname(const std::string &name);
    std::string GetNickname() const;

    // The full name has the given/nickname + family name
    std::string GetFullName() const;

private:
    class Impl;
    std::shared_ptr<Impl> mImpl;
};

}  // namespace address
