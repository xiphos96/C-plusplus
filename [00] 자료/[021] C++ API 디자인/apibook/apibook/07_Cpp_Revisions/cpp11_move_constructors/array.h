///
/// \file   array.h
/// \author Martin Reddy
/// \brief  C++11 move constructors and move assignment operators
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <vector>

namespace apibook {

///
/// An array of elements.
///
class Array
{
public:
    /// default constructor
    Array();
    /// non-default constructor
    explicit Array(size_t size);
    /// destructor
    ~Array();
    /// copy constructor
    Array(const Array &other);
    /// assignment operator
    Array &operator=(const Array &other);
    /// move constructor
    Array(Array &&other);
    /// move assignment operator
    Array &operator=(Array &&other);

    /// Return the element at the given array index
    std::string Get(int index) const;
    /// Set the element at the given array index
    bool Set(int index, const std::string &str);
    /// Return the number of elements in the array
    size_t Size() const;
    /// Return true if the array has been allocated
    bool IsDefined() const;
    /// Output the array contents to stdout
    void Print() const;

private:
    std::vector<std::string> *mData;
};

}  // namespace apibook

#endif
