Redundant Includes
==================

This directory contains code to let you test the improved performance
of using redundant #include guards. It's not setup to use CMake, and
it's really tuned to running from a Unix shell using GCC/make, i.e.,
Linux, Mac OS X, or Cygwin.

There's a `generate_includes.py` Python scripts that will generate
This will create two directories, src_fast_100 and src_slow_100. The
first has code that uses redundant includes, whereas the second does
not.

Feel free to check out the actual sources and tweak the generator
script to your heart's content. Note, you can pass two optional
parameters to generate_includes.py to specify how many files to
generate, and how many classes to generate per header.


g++ Usage
---------

To run the test using a g++ style compiler:

% ./generate_includes.py
% (cd src_fast_100 ; /usr/bin/time -p make)
% (cd src_slow_100 ; /usr/bin/time -p make)


cl Usage
--------

To run the test on Windows with the Visual Studio compiler,
install Python3 and then run:

> python3 ./generate_includes.py --win
> cd src_fast_100
> make.bat > log.txt
> findstr "time" log.txt
> cd ../src_slow_100
> make.bat > log.txt
> findstr "time" log.txt
 

