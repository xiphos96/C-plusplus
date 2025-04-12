///
/// \file   pluginapi.cpp
/// \author Martin Reddy
/// \brief  An API that lets users write plugins.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "pluginapi.h"
#include "coreapi.h"

void RegisterRenderer(const char *type,
                      RendererInitFunc init_cb,
                      RendererFreeFunc free_cb)
{
    RendererFactory::RegisterRenderer(type, init_cb);
    (void) free_cb;  // we never free these objects
}
