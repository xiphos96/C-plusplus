///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  An example of the Observer design pattern.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "observer.h"
#include <iostream>
#include <string>

using namespace apibook;
using std::cout;
using std::endl;

/// An observer class that wishes to receive a notification
class MyObserver : public IObserver
{
public:
    MyObserver(const std::string &str) :
        mName(str)
    {
    }

    void Update(MessageType message)
    {
        std::string str;
        switch (message) {
        case MessageType::Add:
            str = "Add";
            break;
        case MessageType::Remove:
            str = "Remove";
            break;
        case MessageType::Update:
            str = "Update";
            break;
        }
        cout << mName << " Received message " << str << endl;
    }

private:
    std::string mName;
};

int main(int, char **)
{
    // create three observer classes
    MyObserver observer1("observer1");
    MyObserver observer2("observer2");
    MyObserver observer3("observer3");
    // create a single subject class
    ISubject subject;

    // each observer registers interest for specific
    // messages that the subject can issue
    subject.Subscribe(MessageType::Add, &observer1);
    subject.Subscribe(MessageType::Add, &observer2);
    subject.Subscribe(MessageType::Remove, &observer2);
    subject.Subscribe(MessageType::Remove, &observer1);
    subject.Subscribe(MessageType::Update, &observer3);

    // make the subject issue ADD and UPDATE messages
    cout << "Notify ADD:" << endl;
    subject.Notify(MessageType::Add);
    cout << "Notify UPDATE:" << endl;
    subject.Notify(MessageType::Update);

    return 0;
}
