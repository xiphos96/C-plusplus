#
# CMakeLists.txt - cmake build file for API Design examples
#
# Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
# Distributed under the X11/MIT License. See LICENSE.txt.
# See https://APIBook.com/ for the latest version.
#

# Define the include/link directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../auto_timer")
link_directories("${CMAKE_CURRENT_BINARY_DIR}/../auto_timer")

# Build the executable
add_executable(iterators main.cpp value.cpp)

# Link against the AutoTimer library
target_link_libraries(iterators autotimer)
