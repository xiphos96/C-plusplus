///
/// \file   original.h
/// \author Martin Reddy
/// \brief  An original class to be wrapped by an Adapter.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef ORIGINAL_H
#define ORIGINAL_H

namespace apibook {

///
/// An Original class that is wrapped by Adapter.
///
class Original
{
public:
    /// A function that does something!
    void DoOperation(int value, bool extra_arg);
};

}  // namespace apibook

#endif
