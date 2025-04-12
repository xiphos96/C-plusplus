///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  An example of explicit template instantiation.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "stack.h"
#include <iostream>

using namespace apibook;

int main(int, char **)
{
    // create a specialization of Stack for ints
    Stack<int> stack;

    // push and pop a value to the stack
    std::cout << "Empty: " << stack.IsEmpty() << std::endl;
    stack.Push(10);
    std::cout << "Empty: " << stack.IsEmpty() << std::endl;
    int val = stack.Pop();
    std::cout << "Popped off: " << val << std::endl;
    std::cout << "Empty: " << stack.IsEmpty() << std::endl;

    return 0;
}
