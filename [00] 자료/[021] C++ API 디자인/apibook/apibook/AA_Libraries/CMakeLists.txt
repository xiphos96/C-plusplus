#
# CMakeLists.txt - cmake build file for API Design examples
#
# Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
# Distributed under the X11/MIT License. See LICENSE.txt.
# See https://APIBook.com/ for the latest version.
#

# These directories only build under GCC
if (CMAKE_COMPILER_IS_GNUCC)
  add_subdirectory(gcc_entry_point)
  add_subdirectory(gcc_plugin)
endif (CMAKE_COMPILER_IS_GNUCC)
