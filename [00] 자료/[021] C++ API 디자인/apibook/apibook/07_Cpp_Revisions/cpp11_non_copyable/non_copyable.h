///
/// \file   non_copyable.h
/// \author Martin Reddy
/// \brief  A non-copyable base class using delete/default
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef NON_COPYABLE_H
#define NON_COPYABLE_H

namespace apibook {

///
/// Inherit from this class to make the subclass non copyable
///
class NonCopyable
{
public:
    // default constructor and virtual destructor
    NonCopyable() = default;
    virtual ~NonCopyable() = default;

    // deleted copy and move special functions
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;
    NonCopyable(NonCopyable &&) = delete;
    NonCopyable &operator=(NonCopyable &&) = delete;
};

}  // namespace apibook

#endif
