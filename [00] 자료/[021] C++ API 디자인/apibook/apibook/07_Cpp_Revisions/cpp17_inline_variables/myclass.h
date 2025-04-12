///
/// \file   myclass.h
/// \author Martin Reddy
/// \brief  Use of inline variables for header-only constants.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef MYCLASS_H
#define MYCLASS_H

#include <string>
#include <string_view>

namespace apibook {

class MyClass
{
public:
    /// inline variables can have value declared in header
    inline static const std::string VERSION = "1.0";

    /// can also use constexpr as it implies inline
    static constexpr std::string_view UPDATED = "2024-01-11";
};

}  // namespace apibook

#endif
