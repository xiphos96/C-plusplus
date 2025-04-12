///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  An example of the Adapter design pattern.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "adapter.h"

using namespace apibook;

int main(int, char **)
{
    // create an adapter object and call one of its functions
    Adapter adapter;
    adapter.DoSomething(42);

    return 0;
}
