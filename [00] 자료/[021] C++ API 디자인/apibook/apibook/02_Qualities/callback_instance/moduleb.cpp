///
/// \file   moduleb.h
/// \author Martin Reddy
/// \brief  A module that invokes a callback on an object.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "moduleb.h"

namespace apibook {

ModuleB::ModuleB() :
    mCallback(nullptr),
    mClosure(nullptr)
{
}

void ModuleB::SetCallback(CallbackType cb, void *data)
{
    mCallback = cb;
    mClosure = data;
}

void ModuleB::InvokeCallback()
{
    if (mCallback) {
        mCallback("Hello World", mClosure);
    }
}

}  // namespace apibook
