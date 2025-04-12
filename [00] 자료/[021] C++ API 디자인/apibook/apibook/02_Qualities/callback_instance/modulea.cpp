///
/// \file   modulea.cpp
/// \author Martin Reddy
/// \brief  A module that uses one of its methods as a callback.
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

void ModuleA::InstanceMethod(const std::string &name, void *data)
{
    int closure = *static_cast<int *>(data);
    cout << "In instance callback: '" << name << "' (closure=" << closure << ")" << endl;
}

}  // namespace apibook
