///
/// \file   address_objc.mm
/// \author Martin Reddy
/// \brief  Wrapping an Objective-C API around a C++ API.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#import "address_objc.h"
#include "address_cpp.h"

@interface ADRPerson () {
    address::Person mPerson;
}
@end

@implementation ADRPerson {
}

- (NSString *)givenName
{
    auto cppStr = mPerson.GetGivenName();
    return [NSString stringWithUTF8String:cppStr.c_str()];
}

- (void)setGivenName:(NSString *)name
{
    auto cppStr = (name) ? [name UTF8String] : "";
    mPerson.SetGivenName(cppStr);
}

- (NSString *)familyName
{
    auto cppStr = mPerson.GetFamilyName();
    return [NSString stringWithUTF8String:cppStr.c_str()];
}

- (void)setFamilyName:(NSString *)name
{
    auto cppStr = (name) ? [name UTF8String] : "";
    mPerson.SetFamilyName(cppStr);
}

- (NSString *)nickName
{
    auto cppStr = mPerson.GetNickname();
    return [NSString stringWithUTF8String:cppStr.c_str()];
}

- (NSString *)getFullName
{
    auto cppStr = mPerson.GetFullName();
    return [NSString stringWithUTF8String:cppStr.c_str()];
}

@end
