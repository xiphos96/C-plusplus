#
# CMakeLists.txt - cmake build file for API Design examples
#
# Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
# Distributed under the X11/MIT License. See LICENSE.txt.
# See https://APIBook.com/ for the latest version.
#

# Using the C:\Program Files\ version of cmake won't build shared libraries
# properly under Cygwin. You must install Cygwin's version of cmake for that.

if ("${CMAKE_GENERATOR}" STREQUAL "Unix Makefiles" AND WIN32 AND NOT CYGWIN)

message("WARNING: plugin_api will not be built unless you use Cygwin's /usr/bin/cmake")

else ()

add_library(coreapi SHARED coreapi.cpp pluginapi.cpp pluginmanager.cpp)
set_target_properties(coreapi PROPERTIES DEFINE_SYMBOL BUILDING_CORE)

add_library(plugin1 SHARED plugin1.cpp)
target_link_libraries(plugin1 coreapi)

add_library(plugin2 SHARED plugin2.cpp)
target_link_libraries(plugin2 coreapi)

# create the libraries
add_executable(plugin_api main.cpp)
target_link_libraries(plugin_api coreapi)

if (WIN32)
   find_library(DL_LIB Kernel32.dll)
else ()
   find_library(DL_LIB dl)
endif ()

target_link_libraries(plugin_api ${DL_LIB})

endif ()
