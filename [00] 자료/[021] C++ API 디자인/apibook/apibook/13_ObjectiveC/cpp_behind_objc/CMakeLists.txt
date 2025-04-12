#
# CMakeLists.txt - cmake build file for API Design examples
#
# Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
# Distributed under the X11/MIT License. See LICENSE.txt.
# See https://APIBook.com/ for the latest version.
#

# Add support for compiling Objective-C code
enable_language(OBJC)
enable_language(OBJCXX)

# Build the executable
add_executable(cpp_behind_objc main.m address_objc.mm address_cpp.cpp)
target_link_libraries(cpp_behind_objc
    "-framework Foundation"
)
