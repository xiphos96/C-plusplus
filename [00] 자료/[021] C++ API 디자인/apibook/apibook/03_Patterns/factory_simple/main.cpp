///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  A simple example of a Factory Method.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "rendererfactory.h"

using namespace apibook;

int main(int, char **)
{
    // create the factory object
    RendererFactory *f = new RendererFactory;

    // create an OpenGL renderer
    IRenderer *ogl = f->CreateRenderer("opengl");
    ogl->Render();
    delete ogl;

    // create a Mesa software renderer
    IRenderer *mesa = f->CreateRenderer("mesa");
    mesa->Render();
    delete mesa;

    delete f;
    return 0;
}
