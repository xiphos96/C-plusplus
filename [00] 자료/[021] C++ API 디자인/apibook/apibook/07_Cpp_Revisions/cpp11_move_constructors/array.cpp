///
/// \file   array.cpp
/// \author Martin Reddy
/// \brief  C++11 move constructors and move assignment operators
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "array.h"
#include <algorithm>
#include <iostream>

namespace apibook {

// default constructor
Array::Array() :
    mData(nullptr)
{
    std::cout << "default constructor" << std::endl;
}

// non-default constructor
Array::Array(size_t size) :
    mData(new std::vector<std::string>())
{
    std::cout << "non-default constructor" << std::endl;
    mData->resize(size);
}

// destructor
Array::~Array()
{
    std::cout << "destructor" << std::endl;
    delete mData;
}

// copy constructor
Array::Array(const Array &other) :
    mData(nullptr)
{
    std::cout << "In copy constructor" << std::endl;
    if (other.mData) {
        mData = new std::vector<std::string>();
        mData->resize(other.mData->size());
        std::copy(other.mData->begin(), other.mData->end(), mData->begin());
    }
}

// assignment operator
Array &Array::operator=(const Array &other)
{
    std::cout << "In copy assignment operator" << std::endl;
    if (this != &other) {
        delete mData;
        mData = new std::vector<std::string>();
        mData->resize(other.mData->size());
        std::copy(other.mData->begin(), other.mData->end(), mData->begin());
    }
    return *this;
}

// move constructor
Array::Array(Array &&other) :
    mData(nullptr)
{
    std::cout << "In move constructor" << std::endl;
    if (other.mData) {
        mData = other.mData;
        other.mData = nullptr;
    }
}

// move assignment operator
Array &Array::operator=(Array &&other)
{
    std::cout << "In move assignment operator" << std::endl;
    if (this != &other) {
        delete mData;
        mData = other.mData;
        other.mData = nullptr;
    }
    return *this;
}

std::string Array::Get(int index) const
{
    if (mData == nullptr || index < 0 || index >= mData->size()) {
        return std::string("");
    }

    return (*mData)[index];
}

bool Array::Set(int index, const std::string &str)
{
    if (mData == nullptr || index < 0 || index >= mData->size()) {
        return false;
    }

    (*mData)[index] = str;
    return true;
}

size_t Array::Size() const
{
    return mData ? mData->size() : 0;
}

bool Array::IsDefined() const
{
    return mData != nullptr;
}

void Array::Print() const
{
    std::cout << "Size = " << Size() << std::endl;
    for (int i = 0; i < Size(); ++i) {
        std::cout << i << ": " << (*mData)[i] << std::endl;
    }
}

}  // namespace apibook
