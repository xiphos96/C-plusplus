///
/// \file   address_objc.h
/// \author Martin Reddy
/// \brief  Wrapping an Objective-C API around a C++ API.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#import <Foundation/Foundation.h>

@interface ADRPerson : NSObject

@property(strong, nonatomic) NSString *givenName;
@property(strong, nonatomic) NSString *familyName;
@property(strong, nonatomic) NSString *nickname;

- (NSString *)getFullName;

@end

