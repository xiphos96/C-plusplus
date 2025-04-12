///
/// \file   proxy.cpp
/// \author Martin Reddy
/// \brief  A Proxy design pattern using a common interface.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "proxy.h"
#include "original.h"
#include <iostream>

using std::cout;
using std::endl;

namespace apibook {

Proxy::Proxy() :
    mOrig(new Original)
{
    cout << "Allocated new Original object inside Proxy" << endl;
}

Proxy::~Proxy()
{
    cout << "Destroyed Original object inside Proxy" << endl;
    delete mOrig;
}

bool Proxy::DoSomething(int value)
{
    cout << "About to call Original::DoSomething from Proxy" << endl;
    return mOrig->DoSomething(value);
}

}  // namespace apibook
