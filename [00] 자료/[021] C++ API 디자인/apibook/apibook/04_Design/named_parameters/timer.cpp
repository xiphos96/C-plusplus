///
/// \file   timer.cpp
/// \author Martin Reddy
/// \brief  Example of the Named Parameter Idiom (NPI)
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "timer.h"
#include <iostream>

using std::cout;
using std::endl;

namespace apibook {

class Timer::Impl
{
public:
    float mDelay;
    bool mSingleShot;
};

Timer::Timer() :
    mImpl(new Timer::Impl)
{
    mImpl->mDelay = 0.0f;
    mImpl->mSingleShot = false;
}

Timer::~Timer()
{
    delete mImpl;
}

Timer::Timer(const Timer &other) :
    mImpl(new Timer::Impl)
{
    mImpl->mDelay = other.mImpl->mDelay;
    mImpl->mSingleShot = other.mImpl->mSingleShot;
}

const Timer &Timer::operator=(const Timer &other)
{
    mImpl->mDelay = other.mImpl->mDelay;
    mImpl->mSingleShot = other.mImpl->mSingleShot;
    return *this;
}

Timer &Timer::SetDelay(float t)
{
    mImpl->mDelay = t;
    return *this;
}

Timer &Timer::SetSingleShot(bool ss)
{
    mImpl->mSingleShot = ss;
    return *this;
}

Timer &Timer::Start()
{
    cout << "Start timer: delay = " << mImpl->mDelay;
    cout << ", single-shot = " << mImpl->mSingleShot << endl;
    return *this;
}

}  // namespace apibook
