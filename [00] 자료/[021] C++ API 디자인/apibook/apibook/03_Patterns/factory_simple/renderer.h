///
/// \file   renderer.h
/// \author Martin Reddy
/// \brief  An abstract base class for a simple 3D renderer.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef RENDERER_H
#define RENDERER_H

#include <string>

namespace apibook {

///
/// An abstract interface for a 3D renderer.
///
class IRenderer
{
public:
    virtual ~IRenderer() = default;
    virtual bool LoadScene(const std::string &filename) = 0;
    virtual void SetViewportSize(int w, int h) = 0;
    virtual void SetCameraPos(double x, double y, double z) = 0;
    virtual void SetLookAt(double x, double y, double z) = 0;
    virtual void Render() = 0;
};

}  // namespace apibook

#endif
