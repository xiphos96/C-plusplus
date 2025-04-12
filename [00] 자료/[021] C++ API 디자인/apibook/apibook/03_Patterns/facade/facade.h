///
/// \file   facade.h
/// \author Martin Reddy
/// \brief  An example of the Facade design pattern.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef FACADE_H
#define FACADE_H

namespace apibook {

///
/// An facade that wraps access to a sub-system.
///
class Facade
{
public:
    Facade();
    ~Facade();

    /// Call various functions in the sub-system to aggregate its functionality
    bool DoSomething();

    // prevent copying of this class because we have a pointer data member
    Facade(const Facade &) = delete;
    const Facade &operator=(const Facade &) = delete;

private:
    class Impl;
    Impl *mImpl;
};

}  // namespace apibook

#endif
