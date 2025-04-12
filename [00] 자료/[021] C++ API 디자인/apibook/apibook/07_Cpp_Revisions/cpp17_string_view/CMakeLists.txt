#
# CMakeLists.txt - cmake build file for API Design examples
#
# Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
# Distributed under the X11/MIT License. See LICENSE.txt.
# See https://APIBook.com/ for the latest version.
#

# This example uses C++17
set(CMAKE_CXX_STANDARD 17)

# Build the executable
add_executable(cpp17_string_view main.cpp name_holder.cpp)
