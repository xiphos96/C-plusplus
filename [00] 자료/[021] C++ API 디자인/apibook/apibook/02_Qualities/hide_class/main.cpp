///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Example of a private nested class.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "fireworks.h"

using namespace apibook;

int main(int, char **)
{
    // create a new Fireworks object
    Fireworks fireworks;

    // set the properties of the Fireworks particle system
    fireworks.SetOrigin(50, 20);
    fireworks.SetColor(1.0, 0.0, 0.0);
    fireworks.SetSpeed(10.0);
    fireworks.SetNumberOfParticles(1000);

    // start the particle system
    fireworks.Start();

    return 0;
}
