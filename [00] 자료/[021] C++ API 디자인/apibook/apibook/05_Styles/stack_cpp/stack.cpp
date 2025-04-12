///
/// \file   stack.cpp
/// \author Martin Reddy
/// \brief  An example of an object-oriented C++ style API.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "stack.h"

namespace apibook {

void IntStack::Push(int val)
{
    mStack.push_back(val);
}

int IntStack::Pop()
{
    if (IsEmpty()) {
        return 0;
    }
    int val = mStack.back();
    mStack.pop_back();
    return val;
}

bool IntStack::IsEmpty() const
{
    return mStack.empty();
}

}  // namespace apibook
