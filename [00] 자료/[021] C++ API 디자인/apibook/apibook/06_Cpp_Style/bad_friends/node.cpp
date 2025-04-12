///
/// \file   node.cpp
/// \author Martin Reddy
/// \brief  A single node in a graph. Graph is a friend.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "node.h"
#include <iostream>

using std::cout;
using std::endl;

namespace apibook {

void Node::SetVisited()
{
    cout << "Private method called!" << endl;
}

bool Node::IsVisited() const
{
    cout << "Private method called!" << endl;
    return false;
}

}  // namespace apibook
