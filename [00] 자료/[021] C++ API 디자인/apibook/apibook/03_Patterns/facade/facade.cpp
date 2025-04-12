///
/// \file   facade.cpp
/// \author Martin Reddy
/// \brief  An example of the Facade design pattern.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "facade.h"
#include "original.h"
#include <iostream>

using std::cout;
using std::endl;

namespace apibook {

class Facade::Impl
{
public:
    Impl() :
        mOriginal1(nullptr),
        mOriginal2(nullptr)
    {
    }

    ~Impl()
    {
        cout << "Destroyed Original objects inside Facade" << endl;
        delete mOriginal1;
        delete mOriginal2;
    }

    Original1 *GetOriginal1()
    {
        if (!mOriginal1) {
            cout << "Lazily allocating Original1" << endl;
            mOriginal1 = new Original1;
        }
        return mOriginal1;
    }

    Original2 *GetOriginal2()
    {
        if (!mOriginal2) {
            cout << "Lazily allocating Original2" << endl;
            mOriginal2 = new Original2;
        }
        return mOriginal2;
    }

private:
    Original1 *mOriginal1;
    Original2 *mOriginal2;
};

Facade::Facade() :
    mImpl(new Facade::Impl)
{
}

Facade::~Facade()
{
    delete mImpl;
}

bool Facade::DoSomething()
{
    cout << "About to call routines in Original1 and Original2" << endl;
    int result = mImpl->GetOriginal1()->DoOperation1();
    if (result < 100) {
        return mImpl->GetOriginal2()->DoOperation2(result);
    }
    return false;
}

}  // namespace apibook
