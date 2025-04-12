///
/// \file   plugin.cpp
/// \author Martin Reddy
/// \brief  An example of a simple plugin interface
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "plugin.h"

#include <iostream>

void DoSomething(const std::string &name)
{
    std::cout << "Plugin says: " << name << std::endl;
}
