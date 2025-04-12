///
/// \file   adapter.h
/// \author Martin Reddy
/// \brief  An example of the Adapter design pattern.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef ADAPTER_H
#define ADAPTER_H

namespace apibook {

// forward declaration for the object wrapped by Adapter
class Original;

///
/// An Adapter that wraps access to an Original object.
///
class Adapter
{
public:
    Adapter();
    ~Adapter();

    /// Call through to Original::DoSomething()
    bool DoSomething(int value);

    // prevent copying of this class because we have a pointer data member
    Adapter(const Adapter &) = delete;
    const Adapter &operator=(const Adapter &) = delete;

private:
    Original *mOrig;
};

}  // namespace apibook

#endif
