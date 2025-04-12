///
/// \file   rendererfactory.h
/// \author Martin Reddy
/// \brief  A factory object to create Renderer instances.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef RENDERERFACTORY_H
#define RENDERERFACTORY_H

#include "renderer.h"
#include <string>

namespace apibook {

///
/// A factory object that creates instances of different
/// 3D renderers.
///
class RendererFactory
{
public:
    /// Create a new instance of a named 3D renderer.
    /// type can be one of "opengl", "directx", or "mesa"
    IRenderer *CreateRenderer(const std::string &type);
};

}  // namespace apibook

#endif
