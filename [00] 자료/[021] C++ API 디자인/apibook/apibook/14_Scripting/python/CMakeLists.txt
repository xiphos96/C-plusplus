#
# CMakeLists.txt - cmake build file for API Design examples
#
# Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
# Distributed under the X11/MIT License. See LICENSE.txt.
# See https://APIBook.com/ for the latest version.
#
#
# to get this to work properly, you need to add include paths to:
#
#  1. Your Python header files
#  2. Your Boost installation
#
# and add to your lib paths:
#
#  1. The directory where libpython lives
#  2. The directory where libboost_python lives
#
# Note: The version of Python you specify MUST be the same version that Boost.Python
# was compiled against otherwise you'll get lots of errors.
#

include_directories(
	/System/Library/Frameworks/Python.framework/Versions/2.6/include/python2.6/
)
link_directories(
	.
	/usr/lib
)

# build the library
add_library(phonebook SHARED phonebook.cpp phonebook_wrap.cpp)
target_link_libraries(phonebook boost_python python)

# on Darwin/Linux, create phonebook.so, not libphonebook.dylib or libphonebook.so
set_target_properties(phonebook PROPERTIES PREFIX "")
if ("${CMAKE_SYSTEM_NAME}" MATCHES "Darwin")
  #set_target_properties(phonebook PROPERTIES OUTPUT_NAME phonebook)
  set_target_properties(phonebook PROPERTIES SUFFIX .so)
endif ()
