///
/// \file   cowptr.h
/// \author Martin Reddy
/// \brief  A class template with copy-on-write behavior.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef COWPTR_H
#define COWPTR_H

#include <memory>

namespace apibook {

///
/// A class template for declaring a copy-on-write type.
///
template <class T>
class CowPtr
{
public:
    using RefPtr = std::shared_ptr<T>;

    CowPtr();
    ~CowPtr();
    explicit CowPtr(T *other);
    CowPtr(const CowPtr<T> &other);

    T &operator*();
    const T &operator*() const;

    T *operator->();
    const T *operator->() const;

    operator T *();
    operator const T *() const;

    T *data();
    const T *data() const;
    const T *constData() const;

    bool operator==(const CowPtr<T> &other) const;
    bool operator!=(const CowPtr<T> &other) const;
    bool operator!() const;

    CowPtr<T> &operator=(const CowPtr<T> &other);
    CowPtr<T> &operator=(T *other);

private:
    void Detach();

    RefPtr mPtr;
};

}  // namespace apibook

#include "cowptr_priv.h"

#endif
