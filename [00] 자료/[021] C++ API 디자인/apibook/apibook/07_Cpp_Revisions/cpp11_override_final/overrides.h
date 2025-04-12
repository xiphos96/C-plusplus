///
/// \file   overrides.h
/// \author Martin Reddy
/// \brief  Class hierarchy using override and final keywords.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef OVERRIDES_H
#define OVERRIDES_H

namespace apibook {

class Base
{
public:
    virtual ~Base();
    /// virtual method that can be overriden
    virtual void VirtualMethod();
    /// virtual method that we will make final
    virtual void EventuallyFinalMethod();
    /// non-virtual method that cannot be overridden
    void NonVirtualMethod();
};

class Derived : public Base
{
public:
    virtual ~Derived();
    /// Override Base::VirtualMethod()
    void VirtualMethod() override;
    /// Override Base::EventuallyFinalMethod but make it final
    void EventuallyFinalMethod() final;
    /// Cannot override a non-virtual with override specifier
    // void NonVirtualMethod() override;  // compile error
};

class FurtherDerived : public Derived
{
public:
    virtual ~FurtherDerived();

    /// Override Derived::VirtualMethod()
    void VirtualMethod() override;
    /// Cannot override a method marked final in base class
    // void EventuallyFinalMethod() override;  // compile error
};

}  // namespace apibook

#endif
