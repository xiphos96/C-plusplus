///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  ModuleB calls an instance method on ModuleA.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "modulea.h"
#include "moduleb.h"
#include <functional>

using namespace apibook;
using namespace std::placeholders;

int main(int, char **)
{
    ModuleB b;
    ModuleA a;
    int closure = 42;

    // using std::bind to add a callback for ModuleA to ModuleB
    b.SetCallback(std::bind(&ModuleA::InstanceMethod, a, _1, _2), &closure);
    // tell ModuleB to invoke the callback
    b.InvokeCallback();

    // also demonstrate using a lambda function to call the instance method
    b.SetCallback([&a](const std::string &name, void *data) {
        a.InstanceMethod(name, data);
    }, &closure);
    b.InvokeCallback();

    return 0;
}
