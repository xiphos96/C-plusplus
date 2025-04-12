///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  An example using Boost shared pointers.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "myobject.h"
#include <iostream>

using namespace apibook;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    cout << "> main()" << endl;

    {
        MyObjectPtr ptr;

        // create a new instance of MyObject
        cout << "> CreateInstance(1)" << endl;
        ptr = MyObject::CreateInstance(1);

        // create another instance of MyObject
        cout << "> CreateInstance(2)" << endl;
        ptr = MyObject::CreateInstance(2);
    }
    // both instances get deleted when they go out of scope

    cout << "> exit()" << endl;
    return 0;
}
