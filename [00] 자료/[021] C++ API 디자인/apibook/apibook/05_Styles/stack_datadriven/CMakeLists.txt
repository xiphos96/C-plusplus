#
# CMakeLists.txt - cmake build file for API Design examples
#
# Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
# Distributed under the X11/MIT License. See LICENSE.txt.
# See https://APIBook.com/ for the latest version.
#

# Build the executable
add_executable(stack_datadriven main.cpp stack.cpp arglist.cpp)

# Build the test program for the arglist module
add_executable(arglist_test arglist_test.cpp arglist.cpp)
