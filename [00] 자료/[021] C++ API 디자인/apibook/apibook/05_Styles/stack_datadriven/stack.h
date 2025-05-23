///
/// \file   stack.h
/// \author Martin Reddy
/// \brief  An example of a data-driven style API.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef STACK_H
#define STACK_H

#include "arglist.h"
#include <vector>

namespace apibook {

///
/// A data-driven interface for a stack of values.
///
class Stack
{
public:
    /// Perform a named operation on this stack with an optional
    /// list of arguments. The supported operations include:
    ///
    ///  - "Push": accepts a single integer argument
    ///  - "Pop": returns the integer on the top of the stack
    ///  - "IsEmpty": returns true if the stack contains no values
    Arg Command(const std::string &cmd, const ArgList &args = ArgList());

private:
    std::vector<int> mStack;
};

}  // namespace apibook

#endif
