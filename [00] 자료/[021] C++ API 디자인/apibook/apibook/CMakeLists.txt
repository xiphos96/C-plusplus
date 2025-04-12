#
# CMakeLists.txt - cmake build file for API Design examples
#
# Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
# Distributed under the X11/MIT License. See LICENSE.txt.
# See https://APIBook.com/ for the latest version.
#

# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 3.16)

# Setup the name for this CMake project
project(APIBook)

# use C++11 as the minimum standard
set(CMAKE_CXX_STANDARD 11)

# compile with debug information and all warnings by default
if (CMAKE_COMPILER_IS_GNUCC)
  set(CMAKE_CXX_FLAGS "-g -Wall")
endif ()

# Specify the subdirectories to build
add_subdirectory(02_Qualities)
add_subdirectory(03_Patterns)
add_subdirectory(04_Design)
add_subdirectory(05_Styles)
add_subdirectory(06_Cpp_Style)
add_subdirectory(07_Cpp_Revisions)
add_subdirectory(08_Performance)
add_subdirectory(10_Versioning)
add_subdirectory(11_Documentation)
add_subdirectory(12_Testing)
add_subdirectory(13_ObjectiveC)
add_subdirectory(14_Scripting)
add_subdirectory(15_Extensibility)
add_subdirectory(AA_Libraries)

# Note, some subdirs are not built because they have additional
# dependencies - see their CMakeLists.txt files for details.
