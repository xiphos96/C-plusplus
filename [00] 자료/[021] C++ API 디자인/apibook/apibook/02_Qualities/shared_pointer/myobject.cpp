///
/// \file   myobject.cpp
/// \author Martin Reddy
/// \brief  A simple class to demonstrate shared pointers.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "myobject.h"
#include <iostream>

using std::cout;
using std::endl;

namespace apibook {

MyObject::MyObject(int id) :
    mID(id)
{
    cout << "... created object " << mID << endl;
}

MyObject::~MyObject()
{
    cout << "... destroyed object " << mID << endl;
}

MyObjectPtr MyObject::CreateInstance(int id)
{
    return std::make_shared<MyObject>(id);
}

}  // namespace apibook
