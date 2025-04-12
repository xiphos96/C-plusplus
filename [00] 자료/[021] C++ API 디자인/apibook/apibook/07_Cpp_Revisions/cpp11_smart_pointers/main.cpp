///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Demonstrate shared, unique, and weak smart pointers.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class MyObject
{
};

int main(int, char **)
{
    // shared pointer provides reference-counted copying
    // where the underlying objects are the same
    auto shared1 = std::make_shared<MyObject>();
    auto shared2 = shared1;
    cout << "shared1 ptr = " << (shared1.get()) << endl;
    cout << "shared2 ptr = " << (shared2.get()) << endl;

    // unique pointer can only have one active instance
    // trying to copy it will give a compile error
    auto unique1 = std::unique_ptr<MyObject>(new MyObject());
    auto unique2 = std::move(unique1);
    // auto unique3 = unique2;  // compile error
    cout << "unique1 ptr = " << (unique1.get()) << endl;
    cout << "unique2 ptr = " << (unique2.get()) << endl;

    // weak pointer can return a shared pointer
    // but will return nullptr if it's expired
    std::weak_ptr<MyObject> weak;
    {
        auto shared = std::make_shared<MyObject>();
        weak = shared;
        cout << "weak ptr active = " << weak.lock() << endl;
    }
    cout << "weak ptr expired = " << weak.lock() << endl;

    return 0;
}
