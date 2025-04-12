///
/// \file   temperature.cpp
/// \author Martin Reddy
/// \brief  User defined literals for temperature units.
///
/// Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#include "temperature.h"
#include <string>

namespace apibook {

Temperature::Temperature(double celsius) :
    mCelsius(celsius)
{
}

double Temperature::Get() const
{
    return mCelsius;
}

std::string Temperature::ToString() const
{
    return std::to_string(mCelsius) + " °C";
}

Temperature operator"" _degC(long double celsius)
{
    return Temperature(static_cast<double>(celsius));
}

Temperature operator"" _degC(unsigned long long int celsius)
{
    return Temperature(static_cast<double>(celsius));
}

Temperature operator"" _degF(long double fahrenheit)
{
    return Temperature(static_cast<double>(5.0 / 9.0 * (fahrenheit - 32.0)));
}

Temperature operator"" _degF(unsigned long long int fahrenheit)
{
    return Temperature(static_cast<long double>(5.0 / 9.0 * (fahrenheit - 32.0)));
}

Temperature operator+(const Temperature &lhs, const Temperature &rhs)
{
    return Temperature(lhs.Get() + rhs.Get());
}

}  // namespace apibook
