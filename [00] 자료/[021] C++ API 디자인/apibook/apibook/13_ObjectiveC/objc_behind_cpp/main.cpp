///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  A C++ API with Objective-C implementation.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "guid_holder.h"
#include <iostream>

using namespace apibook;
using std::cout;
using std::endl;

int main(int, char **)
{
    // Use the C++ API; calls Objective-C behind the scenes
    GUIDHolder guid;

    cout << "GUID = " << guid.Get() << endl;

    return 0;
}
