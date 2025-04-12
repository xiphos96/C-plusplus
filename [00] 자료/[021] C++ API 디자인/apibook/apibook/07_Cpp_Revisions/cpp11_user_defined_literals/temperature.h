///
/// \file   temperature.h
/// \author Martin Reddy
/// \brief  User defined literals for temperature units.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <string>

namespace apibook {

// a class that holds a temperature value in degrees Celsius
class Temperature
{
public:
    explicit Temperature(double celsius);

    double Get() const;

    std::string ToString() const;

private:
    double mCelsius;
};

// user defined literals to specify values in degrees Celsius
Temperature operator"" _degC(long double celsius);
Temperature operator"" _degC(unsigned long long int celsius);

// user defined literals to specify values in degrees Fahrenheit
Temperature operator"" _degF(long double fahrenheit);
Temperature operator"" _degF(unsigned long long int fahrenheit);

// addition operator to allow two temperatures to be added together
Temperature operator+(const Temperature &lhs, const Temperature &rhs);

}  // namespace apibook

#endif
