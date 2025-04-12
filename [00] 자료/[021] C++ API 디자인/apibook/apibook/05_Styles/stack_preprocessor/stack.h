///
/// \file   stack.h
/// \author Martin Reddy
/// \brief  An example of a pre-processor based API.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef STACK_H
#define STACK_H

#include <string>
#include <vector>

/// A macro to declare a stack of any type
#define DECLARE_STACK(Prefix, T) \
    class Prefix##Stack          \
    {                            \
    public:                      \
        void Push(T val);        \
        T Pop();                 \
        bool IsEmpty() const;    \
                                 \
    private:                     \
        std::vector<T> mStack;   \
    };

// Use the above macro to define stacks of ints, strings, and doubles
DECLARE_STACK(Int, int);
DECLARE_STACK(String, std::string);
DECLARE_STACK(Double, double);

#endif
