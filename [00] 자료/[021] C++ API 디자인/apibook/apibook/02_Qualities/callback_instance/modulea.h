///
/// \file   modulea.h
/// \author Martin Reddy
/// \brief  A module that provides a method for a callback.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef MODULEA_H
#define MODULEA_H

#include <string>

namespace apibook {

///
/// An object with an instance method that we will register
/// as a callback to be called by ModuleB.
///
class ModuleA
{
public:
    /// The member function callback
    void InstanceMethod(const std::string &name, void *data);
};

}  // namespace apibook

#endif
