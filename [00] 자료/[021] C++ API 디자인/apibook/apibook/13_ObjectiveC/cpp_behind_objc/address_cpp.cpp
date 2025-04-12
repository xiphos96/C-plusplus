///
/// \file   address_cpp.cpp
/// \author Martin Reddy
/// \brief  A C++ API to store a person in an address book.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "address_cpp.h"

using std::string;

namespace address {

class Person::Impl
{
public:
    string mGivenName;
    string mFamilyName;
    string mNickname;
};

Person::Person() :
    mImpl(new Person::Impl())
{
}

void Person::SetGivenName(const string &name)
{
    mImpl->mGivenName = name;
}

string Person::GetGivenName() const
{
    return mImpl->mGivenName;
}

void Person::SetFamilyName(const string &name)
{
    mImpl->mFamilyName = name;
}

string Person::GetFamilyName() const
{
    return mImpl->mFamilyName;
}

void Person::SetNickname(const string &name)
{
    mImpl->mNickname = name;
}

string Person::GetNickname() const
{
    return mImpl->mNickname;
}

string Person::GetFullName() const
{
    string name;
    if (!mImpl->mGivenName.empty()) {
        name = mImpl->mGivenName;
    } else {
        name = mImpl->mNickname;
    }
    if (!mImpl->mFamilyName.empty()) {
        if (!name.empty()) {
            name += " ";
        }
        name += mImpl->mFamilyName;
    }
    return name;
}

}  // namespace address
