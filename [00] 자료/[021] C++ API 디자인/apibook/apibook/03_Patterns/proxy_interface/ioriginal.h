///
/// \file   ioriginal.h
/// \author Martin Reddy
/// \brief  A common interface for Proxy and Original.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef IORIGINAL_H
#define IORIGINAL_H

namespace apibook {

///
/// A shared abstract interface for Proxy and Original.
///
class IOriginal
{
public:
    virtual ~IOriginal() = default;
    virtual bool DoSomething(int value) = 0;
};

}  // namespace apibook

#endif
