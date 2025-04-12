///
/// \file   autotimer.h
/// \author Martin Reddy
/// \brief  An example of Pimpl with a smart pointer.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef AUTOTIMER_H
#define AUTOTIMER_H

#include <memory>
#include <string>

namespace apibook {

///
/// An object that reports how long it was alive for when it
/// is destroyed.
///
class AutoTimer
{
public:
    /// Create a new timer object with a human-readable name
    explicit AutoTimer(const std::string &name);
    /// On destruction, the timer reports how long it was alive
    ~AutoTimer();

private:
    class Impl;
    std::shared_ptr<Impl> mImpl;
};

}  // namespace apibook

#endif
