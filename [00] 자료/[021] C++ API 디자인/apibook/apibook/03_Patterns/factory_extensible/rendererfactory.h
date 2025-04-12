///
/// \file   rendererfactory.h
/// \author Martin Reddy
/// \brief  A factory object to create IRenderer instances.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef RENDERERFACTORY_H
#define RENDERERFACTORY_H

#include "renderer.h"
#include <functional>
#include <map>
#include <string>

namespace apibook {

///
/// A factory object that creates instances of different
/// 3D renderers. New renderers can be dynamically added
/// and removed from the factory object.
///
class RendererFactory
{
public:
    /// The type for the callback that creates an IRenderer instance
    using CreateCallback = std::function<IRenderer *()>;

    /// Add a new 3D renderer to the system
    static void RegisterRenderer(const std::string &type,
                                 CreateCallback cb);
    /// Remove an existing 3D renderer from the system
    static void UnregisterRenderer(const std::string &type);

    /// Create an instance of a named 3D renderer
    static IRenderer *CreateRenderer(const std::string &type);

private:
    using CallbackMap = std::map<std::string, CreateCallback>;
    static CallbackMap mRenderers;
};

}  // namespace apibook

#endif
