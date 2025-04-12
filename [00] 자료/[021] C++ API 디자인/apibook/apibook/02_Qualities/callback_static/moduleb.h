///
/// \file   moduleb.h
/// \author Martin Reddy
/// \brief  A module that invokes a static callback method.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef MODULEB_H
#define MODULEB_H

#include <stdlib.h>
#include <string>

namespace apibook {

///
/// An object that can register a callback function and then
/// invoke that callback when desired.
///
class ModuleB
{
public:
    /// A type for the function signature that is accepted as a callback
    using CallbackType = void (*)(const std::string &name, void *data);

    ModuleB();

    /// Set the callback function. Only one callback can be registered.
    void SetCallback(CallbackType cb, void *data);
    /// Call the callback function.
    void InvokeCallback();

private:
    CallbackType mCallback;
    void *mClosure;
};

}  // namespace apibook

#endif
