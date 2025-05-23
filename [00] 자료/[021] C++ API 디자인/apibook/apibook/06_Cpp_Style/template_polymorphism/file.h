///
/// \file   file.h
/// \author Martin Reddy
/// \brief  Showing static polymorphism using templates.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef FILE_H
#define FILE_H

#include <stdio.h>

namespace apibook {

///
/// An ASCII text file
///
class TextFile
{
public:
    void Open();
};

///
/// A bitmapped image file
///
class ImageFile
{
public:
    void Open();
};

// function template to open a given file
template <typename T>
void open_file(T file)
{
    file.Open();
}

}  // namespace apibook

#endif
