///
/// \file   original.h
/// \author Martin Reddy
/// \brief  An original class to be wrapped by a Proxy.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef ORIGINAL_H
#define ORIGINAL_H

#include "ioriginal.h"

namespace apibook {

///
/// An Original class wrapped by Proxy.
///
class Original : public IOriginal
{
public:
    bool DoSomething(int value);
};

}  // namespace apibook

#endif
