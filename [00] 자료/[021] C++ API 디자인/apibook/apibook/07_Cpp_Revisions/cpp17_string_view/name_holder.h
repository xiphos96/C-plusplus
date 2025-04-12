///
/// \file   name_holder.h
/// \author Martin Reddy
/// \brief  Demonstrate use of std::string_view in C++17
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef NAME_HOLDER_H
#define NAME_HOLDER_H

#include <string>
#include <string_view>

namespace apibook {

/// can only use std::string_view in a constexpr, not a std::string
constexpr std::string_view STRING_CONSTANT = "Hello World";

class NameHolder
{
public:
    /// okay to accept std::string_view as function argument
    NameHolder(std::string_view name);

    // don't return a std::string_view - exposes pointer to internal data
    std::string GetName() const;

private:
    /// store as a std::string to retain ownership of the data
    std::string mName;
};

}  // namespace apibook

#endif