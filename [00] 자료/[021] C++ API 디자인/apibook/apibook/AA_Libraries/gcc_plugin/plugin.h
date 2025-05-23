///
/// \file   plugin.h
/// \author Martin Reddy
/// \brief  An example of a simple plugin interface
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef PLUGIN_H
#define PLUGIN_H

#include <string>

extern "C" void DoSomething(const std::string &name);

#endif
