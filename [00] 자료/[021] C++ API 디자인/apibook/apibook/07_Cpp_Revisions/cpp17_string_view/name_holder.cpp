///
/// \file   name_holder.cpp
/// \author Martin Reddy
/// \brief  Demonstrate use of std::string_view in C++17
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "name_holder.h"
#include <iostream>

namespace apibook {

NameHolder::NameHolder(std::string_view name) :
    mName(name)
{
}

std::string
NameHolder::GetName() const
{
    return mName;
}

}  // namespace apibook
