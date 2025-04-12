///
/// \file   autotimer.h
/// \author Martin Reddy
/// \brief  An object to time the lifetime of a scope.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef AUTOTIMER_H
#define AUTOTIMER_H

#include <string>

namespace apibook {

///
/// An object that reports how long it was alive for
/// when it is destroyed.
///
class AutoTimer
{
public:
    /// Create a new timer object with a human-readable name
    AutoTimer(const std::string &name);
    /// On destruction, the timer reports how long it was alive
    ~AutoTimer();

    /// Return how long the object has been alive
    double GetElapsed() const;

private:
    // Make this object be noncopyable because it holds a pointer
    AutoTimer(const AutoTimer &);
    const AutoTimer &operator=(const AutoTimer &);

    class Impl;
    Impl *mImpl;
};

}  // namespace apibook

#endif
