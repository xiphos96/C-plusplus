///
/// \file   myobject.h
/// \author Martin Reddy
/// \brief  A simple class to demonstrate shared pointers.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <memory>

namespace apibook {

/// A reference-counted pointer to MyObject
using MyObjectPtr = std::shared_ptr<class MyObject>;

///
/// A class that lets you create reference-counted
/// pointers to itself via a factory method.
///
class MyObject
{
public:
    MyObject(int id);
    ~MyObject();

    /// Create a new (reference-counted) instance of MyObject
    static MyObjectPtr CreateInstance(int id);

private:
    int mID;
};

}  // namespace apibook

#endif
