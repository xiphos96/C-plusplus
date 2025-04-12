///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Show a self test function to test private funcs.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "bbox.h"

int main(int, char **)
{
    BBox bbox;

    // call public SelfTest() method to test internal details
    bbox.SelfTest();

    return 0;
}
