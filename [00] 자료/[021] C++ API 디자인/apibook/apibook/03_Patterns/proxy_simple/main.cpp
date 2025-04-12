///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  A simple example of a Proxy design pattern.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "proxy.h"

using namespace apibook;

int main(int, char **)
{
    Proxy proxy;
    proxy.DoSomething(42);

    return 0;
}
