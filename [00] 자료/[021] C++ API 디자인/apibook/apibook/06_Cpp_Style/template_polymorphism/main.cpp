///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Showing static polymorphism using templates.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "file.h"

using namespace apibook;

int main(int, char **)
{
    // create a text and image file object
    TextFile txt_file;
    ImageFile img_file;

    // use the function template to work on either object
    open_file(txt_file);  // open the text file
    open_file(img_file);  // open the image file

    return 0;
}
