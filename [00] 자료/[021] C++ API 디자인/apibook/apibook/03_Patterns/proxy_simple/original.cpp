///
/// \file   original.cpp
/// \author Martin Reddy
/// \brief  An original class to be wrapped by a Proxy.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "original.h"
#include <iostream>

using std::cout;
using std::endl;

namespace apibook {

bool Original::DoSomething(int value)
{
    cout << "In Original::DoSomething with value " << value << endl;
    return true;
}

}  // namespace apibook
