#
# CMakeLists.txt - cmake build file for API Design examples
#
# Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
# Distributed under the X11/MIT License. See LICENSE.txt.
# See https://APIBook.com/ for the latest version.
#

# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 3.0)

# Specify the subdirectories to build
add_subdirectory(constructors)
add_subdirectory(operators)
add_subdirectory(template_explicit)
add_subdirectory(template_polymorphism)
add_subdirectory(template_specialization)
add_subdirectory(bad_friends)
add_subdirectory(extern_leakage)
