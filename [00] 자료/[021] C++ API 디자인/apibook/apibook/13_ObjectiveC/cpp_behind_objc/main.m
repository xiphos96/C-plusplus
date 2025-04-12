///
/// \file   main.m
/// \author Martin Reddy
/// \brief  Wrapping an Objective-C API around a C++ API.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#import "address_objc.h"

int main(int argc, char **argv)
{
    // Use the Objective-C API; calls C++ API behind the scenes
    ADRPerson *person = [ADRPerson new];
    person.givenName = @"Joe";
    person.familyName = @"Bloggs";

    NSLog(@"Person name is %@", [person getFullName]);

    return 0;
}
