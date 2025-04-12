///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  ModuleB calls a static method on ModuleA.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "modulea.h"
#include "moduleb.h"

using namespace apibook;

int main(int, char **)
{
    ModuleB b;
    int closure = 42;

    // add a callback for ModuleA to ModuleB
    b.SetCallback(ModuleA::StaticMethod, &closure);
    // tell ModuleB to invoke all its callbacks
    b.InvokeCallback();

    return 0;
}
