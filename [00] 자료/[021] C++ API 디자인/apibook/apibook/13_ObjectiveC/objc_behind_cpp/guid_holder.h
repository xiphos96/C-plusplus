///
/// \file   guid_holder.h
/// \author Martin Reddy
/// \brief  A C++ API with Objective-C implementation.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include <string>

namespace apibook {

class GUIDHolder
{
public:
    GUIDHolder();

    // return the current GUID string
    std::string Get() const;

    // generate a new GUID string
    void Reset();

private:
    std::string mGUID;
};

}  // namespace apibook
