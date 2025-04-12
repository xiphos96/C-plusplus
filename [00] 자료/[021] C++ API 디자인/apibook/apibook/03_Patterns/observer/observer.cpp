///
/// \file   observer.cpp
/// \author Martin Reddy
/// \brief  Abstract base classes to implement Observer.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "observer.h"

namespace apibook {

ISubject::ISubject() = default;
ISubject::~ISubject() = default;

void ISubject::Subscribe(MessageType message, IObserver *observer)
{
    if (observer) {
        ObserverMap::iterator it = mObservers.find(message);
        if (it == mObservers.end()) {
            mObservers[message] = ObserverList();
        }
        mObservers[message].push_back(observer);
    }
}

void ISubject::Unsubscribe(MessageType message, IObserver *observer)
{
    ObserverMap::iterator it = mObservers.find(message);
    if (it != mObservers.end()) {
        ObserverList &list = mObservers[message];
        for (auto li = list.begin(); li != list.end();) {
            if ((*li) == observer) {
                list.erase(li);
            } else {
                ++li;
            }
        }
    }
}

void ISubject::Notify(MessageType message)
{
    ObserverMap::iterator it = mObservers.find(message);
    if (it != mObservers.end()) {
        ObserverList &list = mObservers[message];
        for (auto li : list) {
            li->Update(message);
        }
    }
}

}  // namespace apibook
