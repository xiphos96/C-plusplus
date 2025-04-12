///
/// \file   myobject.h
/// \author Martin Reddy
/// \brief  Showing how "internal" details can be leaked.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef MYOBJECT_H
#define MYOBJECT_H

namespace apibook {

///
/// A dummy object.
/// The meat of this example is in myobject.cpp
///
class MyObject
{
public:
    void SetValue(int value);
    int GetValue() const;

private:
    int mValue;
};

}  // namespace apibook

#endif
