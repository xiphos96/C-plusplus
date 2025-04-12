#!/bin/sh
#
# Run a single example given the path to its directory.
# This will configure and make the executable if needed.
# e.g.,
#
#  ./run.sh 03_Patterns/pimpl_smart_ptr
#

# check for required argument
if [ "$1" == "" ]; then
    echo "usage: run.sh <path-to-example-directory>"
	exit
fi

# configure CMake if needed
if ! [ -f "build/$1/Makefile" ]; then
	./configure.sh
fi

# build and run the example
cd build/$1
make
./$(basename `pwd`)
