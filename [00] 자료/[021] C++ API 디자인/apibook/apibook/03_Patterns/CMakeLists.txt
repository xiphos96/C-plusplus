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
add_subdirectory(pimpl_none)
add_subdirectory(pimpl_simple)
add_subdirectory(pimpl_smart_ptr)
add_subdirectory(opaque_pointer)
add_subdirectory(singleton)
add_subdirectory(factory_simple)
add_subdirectory(factory_extensible)
add_subdirectory(proxy_simple)
add_subdirectory(proxy_interface)
add_subdirectory(adapter)
add_subdirectory(facade)
add_subdirectory(observer)
