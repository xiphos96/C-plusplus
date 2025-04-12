///
/// \file   coreapi.h
/// \author Martin Reddy
/// \brief  A factory object to create Renderer instances.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef COREAPI_H
#define COREAPI_H

#include "defines.h"
#include "renderer.h"

#include <map>
#include <string>

///
/// A factory object in the Core API
///
class CORE_API RendererFactory
{
public:
    typedef IRenderer *(*CreateCallback)();

    static void RegisterRenderer(const std::string &type,
                                 CreateCallback cb);
    static void UnregisterRenderer(const std::string &type);

    static IRenderer *CreateRenderer(const std::string &type);

private:
    typedef std::map<std::string, CreateCallback> CallbackMap;
    static CallbackMap mRenderers;
};

#endif
