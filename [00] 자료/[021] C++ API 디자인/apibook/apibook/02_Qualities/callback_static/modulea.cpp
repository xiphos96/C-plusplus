///
/// \file   modulea.cpp
/// \author Martin Reddy
/// \brief  A module that declares a static callback method.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "modulea.h"
#include <iostream>

using std::cout;
using std::endl;

namespace apibook {

void ModuleA::StaticMethod(const std::string &name, void *data)
{
    int closure = *static_cast<int *>(data);
    cout << "In static callback: '" << name << "', closure=" << closure << endl;
}

}  // namespace apibook
