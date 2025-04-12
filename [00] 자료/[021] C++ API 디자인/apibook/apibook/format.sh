#!/bin/sh
#
# Script to automatically format the source code using the clang-format
# tool, using the provided .clang-format configuration file.
#

if [ "`which clang-format`" == "" ]; then
    echo "You must install clang-format first, e.g, brew install clang-format"
    exit
fi

find . -name \*.h -o -name \*.cpp -o -name \*.c | grep -v fmod_samples | xargs clang-format --style=file -i
