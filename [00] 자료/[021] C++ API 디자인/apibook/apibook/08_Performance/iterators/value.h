///
/// \file   value.h
/// \author Martin Reddy
/// \brief  A simple copyable class with getter/setter.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef VALUE_H
#define VALUE_H

#include <string>

namespace apibook {

///
/// A class that holds a single integer value.
///
class Value
{
public:
    /// default constructor
    Value();
    /// non-default constructor
    explicit Value(int val);
    /// destructor
    ~Value();
    /// copy constructor
    Value(const Value &in_array);
    /// assignment operator
    Value &operator=(const Value &in_array);

    /// Get the integer value
    int Get() const;
    /// Set the integer value
    void Set(int value);

private:
    int mValue;
};

}  // namespace apibook

#endif
