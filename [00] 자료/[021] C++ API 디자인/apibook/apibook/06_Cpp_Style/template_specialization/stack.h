///
/// \file   stack.h
/// \author Martin Reddy
/// \brief  Template specialization of a class template.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef STACK_H
#define STACK_H

#include <string>
#include <vector>

///
/// A class template to create a stack of objects
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

///
/// A specialization for stacks of pointers
///
template <typename T>
class Stack<T *>
{
public:
    /// Push a new pointer to the stack
    void Push(T *val);
    /// Pop the last pointer off the stack
    T *Pop();
    /// Return true if the stack contains no pointers
    bool IsEmpty() const;

private:
    std::vector<T *> mStack;
};

// Specialization of the above 2 class templates for ints
using IntStack = Stack<int>;
using IntPtrStack = Stack<int *>;

#include "stack_priv.h"

#endif
