///
/// \file   file.cpp
/// \author Martin Reddy
/// \brief  Showing static polymorphism using templates.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "file.h"
#include <iostream>

using std::cout;
using std::endl;

namespace apibook {

void TextFile::Open()
{
    cout << "TextFile.Open()" << endl;
}

void ImageFile::Open()
{
    cout << "ImageFile.Open()" << endl;
}

}  // namespace apibook
