#
# CMakeLists.txt - cmake build file for API Design examples
#
# Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
# Distributed under the X11/MIT License. See LICENSE.txt.
# See https://APIBook.com/ for the latest version.
#

# create the library
add_library(library SHARED library.cpp)

add_executable(gcc_entry_point main.cpp)
target_link_libraries(gcc_entry_point library)
