///
/// \file   singleton.h
/// \author Martin Reddy
/// \brief  An example of the Singleton design pattern.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef SINGLETON_H
#define SINGLETON_H

#include <string>

namespace apibook {

///
/// A class that enforces the policy that only one
/// instance is ever created.
///
class Singleton
{
public:
    /// Return the single instance of this class
    static Singleton &GetInstance();

    /// Return some class-specific single-instance state
    int GetState();

    // Prevent copying of this class
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

private:
    // Only allow construction within this class
    Singleton();
    ~Singleton();
};

}  // namespace apibook

#endif
