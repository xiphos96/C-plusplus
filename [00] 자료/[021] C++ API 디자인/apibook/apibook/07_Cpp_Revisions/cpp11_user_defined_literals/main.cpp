///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Demonstrate use of user defined literals for units.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "temperature.h"
#include <iostream>

using namespace apibook;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    // create a temperature using a value in degrees Celsius
    Temperature temp1 = 100.0_degC;
    cout << "temp1 = " << temp1.ToString() << endl;

    // create a temperature using a value in degrees Fahrenheit
    Temperature temp2 = 100_degF;
    cout << "temp2 = " << temp2.ToString() << endl;

    // do temperature math with values in different units
    Temperature temp3 = 100.0_degC + 100_degF;
    cout << "temp3 = " << temp3.ToString() << endl;

    // the following is a compile error because the Temperature
    // constructor is marked as explicit.
    // Temperature temp4 = 10;

    return 0;
}
