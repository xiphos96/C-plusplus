API DESIGN FOR C++
==================

This package contains the source code examples for the 2nd Edition
of the book "API Design for C++", written by Martin Reddy and
published by Elsevier Science. The authoritative location for this
code is https://APIBook.com/. Refer to that website for more details.


Build System
------------

The 'cmake' cross-platform build system is used to create build files
for your preferred platform and compiler. So first you should download
a recent version of CMake from:

  https://www.cmake.org/


Building From The Command Line (Linux/Mac/Windows)
--------------------------------------------------

With the 'cmake' command in your path, you can simply do the following
to create a set of Makefiles for your platform and then build all of
the examples. This should work from a Linux shell, a Mac OS X Terminal,
or a Cygwin shell under Windows. (If compiling under Cygwin, make sure
you're using the cygwin /usr/bin/cmake version of CMake.)

  % mkdir build
  % cd build
  % cmake -G "Unix Makefiles" ..
  % make

Note, you can also run the configure.sh script in the root directory
to perform everything up to and including the cmake command.

Alternatively, you can simply use the run.sh script to configure,
compile, and run any single source code example, e.g.,

  % ./run.sh 03_Patterns/pimpl_smart_ptr


Building With XCode on Mac OS X
-------------------------------

If you prefer to use the XCode IDE on the Mac rather than compile from
the Terminal, then you can simply do the following:

  % mkdir build
  % cd build
  % cmake -G "Xcode" ..
  % open APIBook.xcodeproj

You can then build, run, and debug all of the examples from within XCode.


Build With Visual Studio on Windows
-----------------------------------

If you're on Windows then you can configure and build the examples
using Visual Studio as follows:

  1. Run the CMake GUI
  2. Specify the root directory of this package as the source location
  3. Create a 'build' subdirectory and specify that as the build location
  4. Press the "Configure" button
  5. Press the "Generate" button

This should generate a Visual Studio solution file called APIBook.sln
in the build directory that you specified. You can open that file in
Visual Studio to build, run, and debug the examples.


Acknowledgments
---------------

Nov 2021:
Thanks to Max Chatfield for reporting that the ArgList::Add() function
in "05_Styles/stack_datadriven" needed a "const char *" overloaded
version to avoid the compiler implicitly selecting the bool overload
instead of the std::string one when using a static string argument.
