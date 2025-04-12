///
/// \file   guid_holder.mm
/// \author Martin Reddy
/// \brief  A C++ API with Objective-C implementation.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "guid_holder.h"
#import <Foundation/Foundation.h>

using std::string;

namespace apibook {

GUIDHolder::GUIDHolder()
{
    Reset();
}

string GUIDHolder::Get() const
{
    return mGUID;
}

void GUIDHolder::Reset()
{
    NSString *uuid = [[NSUUID UUID] UUIDString];
    NSLog(@"Generated new GUID: %@", uuid);
    mGUID = (uuid) ? [uuid UTF8String] : "";
}

}  // namespace apibook
