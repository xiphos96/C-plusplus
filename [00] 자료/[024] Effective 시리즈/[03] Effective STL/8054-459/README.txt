==================================
Effective STL Source Code Examples
==================================

Leor Zolman
leor@bdsoft.com
www.bdsoft.com

Last Updated: 1/1/2002
	(applied all notes in Scott's ESTL Errata page as of that date)

*****************************************************************************
* This code is being maintained by me, Leor Zolman, and NOT by Scott Meyers *
*  Please send all bug reports / comments / suggestions, etc., to ME.       *
*               -Thanks!                                                    *
*****************************************************************************


When Scott Meyers asked if I'd be interested in testing out the source
code for Effective STL, I jumped at the opportunity for several reasons:

    1) I'm learning STL myself, and this was a great way to help familiarize
    myself with the library;

    2) I needed test cases for my STL Error Decryption filter
    (www.bdsoft.com/tools/stlfilt.html), and the typos in Scott's original
    manuscript made for excellent filter fodder ;-)

This archive is the result of that testing. For each item, I began with a
single test harness program, then added additional programs as necessary.
To make sure I was testing the exact code from the book, I cut and pasted
the actual code from an ASCII version of the manuscript directly into the
test harnesses (whitespace and comments were reformatted to fit their new
context, but that's about it).

The initial pass was performed under just one platform, MSVC 6 with the
Dinkumware 3.08 drop-in library. After completing the test programs and
ferreting out syntax and (the rare) coding errors, I batch-compiled
all the test programs using several platforms. The results were logged, and
I annotated the logs to indicate "on purpose" errors (intentional examples
of incorrect code) as well as errors due to the various compiler and library
bugs in each platform. The platforms and their corresponding log files are:

        Microsoft VC6/Native Library        vc6Native.log       
        Microsoft VC6/Dinkum 3.08 Library   dinkum.log
        Borland C++ 5.5 (free cmd line)     borland.log
        DJGPP v2.03                         gpp.log
        Microsoft VC6/STLPort 4.0 Library   STLPort.log
        Visual VC7 (".NET") Beta/Native Lib vcnet.log
        STLPort 4.0                         stlport.log
        STLPort 4.5b6                       stlport41b6.log

[Note: I have not re-run the batch compiles since applying Scott's errata,
 so compiling the current examples may yield different results, error-wise]

Main Example source files are numbered as follows:

        Introduction:           00-1.cpp
        Item n:                 nn-1.cpp, nn-2.cpp, etc.
        Appendices:             a-1.cpp, b-1.cpp, b-2.cpp

Scott's general-purpose Container Utilities header file, ESTLUtil.h, is
included in most examples. Its "using ESTLUtils" directive typically appears within
main(). The "std" namespace is usually also pulled in within main, but
occasionally I've put it at file scope to avoid having to add the explicit
std:: qualifier(s) into file-scope template definitions.


DISCLAIMER / INVITATION FOR FEEDBACK: I completed this testing in early April,
but Scott continued to tweak the book for some time thereafter and some of
the printed code examples may no longer correspond to the test code. As 
discrepancies are brought to my attention, I'll strive to bring the examples
into sync with the book. Please let me know if you find any such discrepancies.

