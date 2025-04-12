///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  An example of an API using the Pimpl idiom.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "autotimer.h"
#include <iostream>

using namespace apibook;
using std::cout;
using std::endl;

int main(int, char **)
{
    AutoTimer timer("MyTimer");

    for (int i = 0; i < 1000; ++i) {
        cout << ".";
    }
    cout << endl;

    return 0;
}
