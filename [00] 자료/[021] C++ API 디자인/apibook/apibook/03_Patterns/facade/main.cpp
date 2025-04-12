///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  An example of the Facade design pattern.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "facade.h"

using namespace apibook;

int main(int, char **)
{
    // create the facade object and call one of its functions
    Facade facade;
    facade.DoSomething();

    return 0;
}
