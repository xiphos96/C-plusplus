///
/// \file   stack.h
/// \author Martin Reddy
/// \brief  An example of a C++ template style API.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef STACK_H
#define STACK_H

#include <string>
#include <vector>

namespace apibook {

///
/// A class template to create a stack of objects
/// of any type
///
template <typename T>
class Stack
{
public:
    /// Push a new value to the stack
    void Push(T val);
    /// Pop the last value off the stack
    T Pop();
    /// Return true if the stack contains no values
    bool IsEmpty() const;

private:
    std::vector<T> mStack;
};

// Declare specializations of the above template for ints, strings, and doubles
using IntStack = Stack<int>;
using StringStack = Stack<std::string>;
using DoubleStack = Stack<double>;

}  // namespace apibook

#include "stack_priv.h"

#endif
