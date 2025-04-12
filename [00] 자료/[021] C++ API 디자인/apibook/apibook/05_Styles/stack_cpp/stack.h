///
/// \file   stack.h
/// \author Martin Reddy
/// \brief  An example of an object-oriented C++ style API.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef STACK_H
#define STACK_H

#include <vector>

namespace apibook {

///
/// A C++ class for a stack of integers.
///
class IntStack
{
public:
    /// Push a new integer to the stack
    void Push(int val);
    /// Pop the last integer off the stack
    int Pop();
    /// Return true if the stack contains no values
    bool IsEmpty() const;

private:
    std::vector<int> mStack;
};

}  // namespace apibook

#endif
