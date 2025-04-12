#
# CMakeLists.txt - cmake build file for API Design examples
#
# Copyright (c) 2023-2024, Martin Reddy. All rights reserved.
# Distributed under the X11/MIT License. See LICENSE.txt.
# See https://APIBook.com/ for the latest version.
#

# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 3.0)

# Specify the subdirectories to build
add_subdirectory(cpp11_move_constructors)
add_subdirectory(cpp11_non_copyable)
add_subdirectory(cpp11_initializer_lists)
add_subdirectory(cpp11_smart_pointers)
add_subdirectory(cpp11_override_final)
add_subdirectory(cpp11_user_defined_literals)
add_subdirectory(cpp11_tuples)
add_subdirectory(cpp11_variadic_templates)
add_subdirectory(cpp14_variable_templates)
add_subdirectory(cpp17_inline_variables)
add_subdirectory(cpp17_string_view)
add_subdirectory(cpp17_optional)
add_subdirectory(cpp17_any)
