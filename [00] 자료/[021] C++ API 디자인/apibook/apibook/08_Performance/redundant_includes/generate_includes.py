#!/usr/bin/env python3
#
# generate_includes.py
#
# A script to generate a series of C++ source files that demonstrate
# the improved performance of using redundant #include guards when you
# have large include dependencies. E.g.,
#
#    #ifndef INC0_H
#    #include "inc0.h"
#    #endif
#
# instead of simply,
#
#    #include "inc0.h"
#
# Usage:
#    generate_includes.py [-f <file-count>] [-c <classes-per-file>] [--win]
#
# Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
# Distributed under the X11/MIT License. See LICENSE.txt.
# See https://APIBook.com/ for the latest version.
#

import os
import sys
import shutil
import argparse

DIR_NORMAL       = "src_slow"
DIR_FAST         = "src_fast"

def open_output_file(filename):
    '''
    Helper routine to try to open a file for writing
    '''
    try:
        fp = open(filename, "w")
    except Exception as e:
        sys.exit("Couldn't create file: %s\n%s" % (filename, e))
    return fp

def generate_include(args, dir, curr, max, redundant_guards):
    '''
    Generate an include file that includes a bunch of other headers
    and includes various class definitions for the compiler to parse.
    Pass True for redundant_guards to generate guards around each
    #include statement.
    '''
    fp = open_output_file(os.path.join(dir, "inc%d.h" % curr))

    fp.write("#ifndef INC%d_H\n" % curr)
    fp.write("#define INC%d_H\n\n" % curr)

    for i in range(0, max):
        if i == curr:
            continue
        if redundant_guards:
            fp.write("#ifndef INC%d_H\n" % i)
            fp.write("#include \"inc%d.h\"\n" % i)
            fp.write("#endif\n")
        else:
            fp.write("#include \"inc%d.h\"\n" % i)

    for i in range(0, args.num_classes_per_file):
        name = "Foo%d_%d" % (curr, i)
        fp.write("\nclass %s\n{\n" % name)
        fp.write("public:\n")
        fp.write("    %s();\n" % name)
        fp.write("    ~%s();\n" % name)
        fp.write("    int GetValue() const;\n")
        fp.write("    void SetValue(int val);\n\n")
        fp.write("private:\n")
        fp.write("    int mValue;\n")
        fp.write("};\n")

    fp.write("#endif\n")
    fp.close()

def generate_cpp(dir, curr):
    '''
    Write a .cpp file that just includes the relevant header file
    '''
    fp = open_output_file(os.path.join(dir, "inc%d.cpp" % curr))

    fp.write("#include \"inc%d.h\"\n" % curr)
    fp.close()

def generate_makefile(dir, max):
    '''
    Create the Makefile to compile the set of all generated files
    '''
    filename = os.path.join(dir, "Makefile")
    fp = open_output_file(filename)

    fp.write("default:\n")
    for i in range(0, max):
        name = "inc%d" % i
        fp.write("\tg++ -c %s.cpp -o %s.o\n" % (name, name))

    fp.close()
    print("Created %s" % filename);

def generate_batfile(dir, max):
    '''
    Create a make.bat file to compile all generated files with Visual Studio
    '''
    filename = os.path.join(dir, "make.bat")
    fp = open_output_file(filename)

    fp.write("echo:| TIME\n")
    for i in range(0, max):
        name = "inc%d" % i
        fp.write("cl /c %s.cpp\n" % name)
    fp.write("echo:| TIME\n")

    fp.close()
    print("Created %s" % filename);

def generate_dir(args, dir, redundant_guards):
    '''
    Create a directory of source files that do or do not use redundant guards
    '''
    if os.path.exists(dir):
        shutil.rmtree(dir)
    os.mkdir(dir)

    for i in range(0, args.num_files):
        generate_include(args, dir, i, args.num_files, redundant_guards)
        generate_cpp(dir, i)

    if args.win:
        generate_batfile(dir, args.num_files)
    else:
        generate_makefile(dir, args.num_files)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        prog='generate_includes',
        description='Create include trees for performance testing'
    )
    parser.add_argument('-f', '--num-files', default=100, type=int)
    parser.add_argument('-c', '--num-classes-per-file', default=10, type=int)
    parser.add_argument('--win', action='store_true')
    args = parser.parse_args()

    # generate sources with and without redundant guards
    ext = "_%03d" % args.num_files
    generate_dir(args, DIR_NORMAL + ext, False)
    generate_dir(args, DIR_FAST + ext, True)
