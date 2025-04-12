///
/// \file   observer.h
/// \author Martin Reddy
/// \brief  Abstract base classes to implement Observer.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef OBSERVER_H
#define OBSERVER_H

#include <map>
#include <vector>

namespace apibook {

enum class MessageType {
    Add,
    Remove,
    Update,
};

///
/// An abstract interface for an observer class.
///
class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void Update(MessageType message) = 0;
};

///
/// An interface for a subject class.
///
class ISubject
{
public:
    ISubject();
    virtual ~ISubject();

    /// Add a new observer to the list of observers.
    virtual void Subscribe(MessageType message, IObserver *observer);
    /// Remove an existing observer from the list of observers.
    virtual void Unsubscribe(MessageType message, IObserver *observer);
    /// Call the Update() method of all subscribed observers.
    virtual void Notify(MessageType message);

private:
    using ObserverList = std::vector<IObserver *>;
    using ObserverMap = std::map<MessageType, ObserverList>;
    ObserverMap mObservers;
};

}  // namespace apibook

#endif
