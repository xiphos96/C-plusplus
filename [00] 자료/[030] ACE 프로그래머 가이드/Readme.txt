Thank you for purchasing this copy of "The ACE Programmer's Guide"!

This README file describes how to use this CD and includes
the licensing statement for ACE itself.

COPYRIGHTS AND LICENSING
========================
This README file and the book's examples in the ACE_wrappers/examples/APG
directory are copyright (c) 2003 Pearson Education. All Rights Reserved.

The ACE kit installation procedures for the Windows, HP-UX, and Solaris
kits are copyright 2003 Riverace Corporation. All Rights Reserved.

The ACE sources themselves are covered by the following license:

     _________________________________________________________________
   
  Copyright and Licensing Information for ACE(TM) and TAO(TM)
  
   [1]ACE(TM) and [2]TAO(TM) are copyrighted by [3]Douglas C. Schmidt and
   his [4]research group at [5]Washington University, Copyright (c)
   1993-2003, all rights reserved. Since ACE and TAO are [6]open source,
   [7]free software, you are free to use, modify, and distribute the ACE
   and TAO source code and object code produced from the source, as long
   as you include this copyright statement along with code built using
   ACE and TAO.
   
   In particular, you can use ACE and TAO in proprietary software and are
   under no obligation to redistribute any of your source code that is
   built using ACE and TAO. Note, however, that you may not do anything
   to the ACE and TAO code, such as copyrighting it yourself or claiming
   authorship of the ACE and TAO code, that will prevent ACE and TAO from
   being distributed freely using an open source development model.
   
   ACE and TAO are provided as is with no warranties of any kind,
   including the warranties of design, merchantibility and fitness for a
   particular purpose, noninfringement, or arising from a course of
   dealing, usage or trade practice. Moreover, ACE and TAO are provided
   with no support and without any obligation on the part of Washington
   University, its employees, or students to assist in its use,
   correction, modification, or enhancement. However, commercial support
   for ACE and TAO are available from [8]Riverace and [9]OCI,
   respectively. Moreover, both ACE and TAO are Y2K-compliant, as long as
   the underlying OS platform is Y2K-compliant.
   
   Washington University, its employees, and students shall have no
   liability with respect to the infringement of copyrights, trade
   secrets or any patents by ACE and TAO or any part thereof. Moreover,
   in no event will Washington University, its employees, or students be
   liable for any lost revenue or profits or other special, indirect and
   consequential damages.
   
   The [10]ACE and [11]TAO web sites are maintained by the [12]Center for
   Distributed Object Computing of Washington University for the
   development of open source software as part of the [13]open source
   software community. By submitting comments, suggestions, code, code
   snippets, techniques (including that of usage), and algorithms,
   submitters acknowledge that they have the right to do so, that any
   such submissions are given freely and unreservedly, and that they
   waive any claims to copyright or ownership. In addition, submitters
   acknowledge that any such submission might become part of the
   copyright maintained on the overall body of code, which comprises the
   [14]ACE and [15]TAO software. By making a submission, submitters agree
   to these terms. Furthermore, submitters acknowledge that the
   incorporation or modification of such submissions is entirely at the
   discretion of the moderators of the open source ACE and TAO projects
   or their designees.
   
   The names ACE(TM), TAO(TM), and Washington University may not be used 
   to endorse or promote products or services derived from this source 
   without express written permission from Washington University. Further, 
   products or services derived from this source may not be called ACE(TM) or
   TAO(TM), nor may the name Washington University appear in their names,
   without express written permission from Washington University.
   
   If you have any suggestions, additions, comments, or questions, please
   let [16]me know.
   
   [17]Douglas C. Schmidt
     _________________________________________________________________
   
References

   1. http://www.cs.wustl.edu/~schmidt/ACE.html
   2. http://www.cs.wustl.edu/~schmidt/TAO.html
   3. http://www.cs.wustl.edu/~schmidt/
   4. http://www.cs.wustl.edu/~schmidt/ACE-members.html
   5. http://www.wustl.edu/
   6. http://www.opensource.org/
   7. http://www.gnu.org/
   8. http://www.riverace.com/
   9. http://www.ociweb.com/
  10. http://www.cs.wustl.edu/~schmidt/ACE.html
  11. http://www.cs.wustl.edu/~schmidt/TAO.html
  12. http://www.cs.wustl.edu/~schmidt/doc-center.html
  13. http://www.opensource.org/
  14. http://www.cs.wustl.edu/~schmidt/ACE-obtain.html
  15. http://www.cs.wustl.edu/~schmidt/TAO-obtain.html
  16. mailto:schmidt@cs.wustl.edu
  17. http://www.cs.wustl.edu/~schmidt/


HOW TO USE THIS CD
==================
This CD contains files that are platform-neutral and some that are
platform-specific. Many are compressed to save space. Compressed files
can be opened directly from the CD or copied to a local drive on your
computer and used there. There are two types of platform-neutral
compressed files:
- Gzip'd tar file. These have .tgz suffixes. Windows users can use the
  WinZip utility (http://www.winzip.com/). UNIX/Linux users can use the
  GNU Zip tool (gunzip) to get a .tar file and the tar command to extract
  the files.
- Zip file. These have .zip suffixes. Windows users can use the WinZip
  utility on these as well. Many UNIX platforms have a zip tool as well.

This CD contains the following platform-neutral files:
. README.txt - this file.
. ACE_html.tgz - the ACE reference documentation in a Gzip'd tar file.
. ACE_html.zip - the ACE reference documentation in a Zip file.
. ACESRC.tgz - the ACE 5.3b source kit in a Gzip'd tar file.
Unpack the desired file(s) into a clean directory (or directories).
When unpacking ACESRC.tgz, you will have an ACE_wrappers directory.
The instructions for building ACE are located in the file
ACE_wrappers/ACE-INSTALL.html. For further information, please see
Chapter 2 in "The ACE Programmer's Guide."

After unpacking the ACE reference documentation, the files can be opened
in-place from your web browser or linked into a web site you may have
at your site. Please see your System Administrator for help in linking
the ACE reference documentation set into an existing web site.

This CD also contains the following platform-specific ACE kits:

. Windows NT4(SP3)/2000/XP using Microsoft Visual C++ version 6
  This kit was built on Windows 2000 using Microsoft Visual C++
  version 6 (SP3). This kit is delivered as an executable self-installer.
  Execute the file ACE53b.exe to begin the installation.

. HP-UX 11 using aC++
  This kit was built on HP-UX 11.00 using aC++ A.03.39. It contains
  both 32-bit and 64-bit versions of both the shared and archive ACE library.
  If installed on a 32-bit system, the 64-bit ACE library will not be
  installed. The libraries are built optimized, without symbolic
  debugging information, with exception support.

  The kit is delivered as a depot file. It can be installed with SAM or
  directly with swinstall. As an example, these are the steps to install
  directly from a command line:
   1. Backup your system before installing this, or any, package.
   2. Login as root.
   3. Install the package using the swinstall command:
        swinstall -x autoreboot=true -s /cdrom/HPUX/ACE_aCC.depot ACE-aCC
  The installation contains 4 components: ACE-aCC.base, ACE-aCC.docs,
  ACE-aCC.examples, ACE-aCC.netsvcs. The total disk space required for
  all 4 parts is approximately 51 MB.

. HP-UX 11 using g++ 3.2
  This kit was built on HP-UX 11.00 using g++ 3.2. It contains a 32-bit
  version of both the shared and archive ACE library. The libraries are
  built optimized, without symbolic debugging information, with
  exception support.

  The kit is delivered as a depot file. It can be installed with SAM or
  directly with swinstall. As an example, these are the steps to install
  directly from a command line:
   1. Backup your system before installing this, or any, package.
   2. Login as root.
   3. Install the package using the swinstall command:
        swinstall -x autoreboot=true -s /cdrom/HPUX/ACE_gcc.depot ACE-gcc
  The installation contains 4 components: ACE-gcc.base, ACE-gcc.docs,
  ACE-gcc.examples, ACE-gcc.netsvcs. The total disk space required for
  all 4 parts is approximately 52 MB.

. Solaris 8 for SPARC using Sun WorkShop 6 Update 2
  This kit was built on Solaris 8 for SPARC using Sun WorkShop 6 Update 2
  (C++ 5.3).

  The kit is delivered as a tar file that should be copied to a local disk
  and expanded for installation using the pkgadd utility.
  These are the installation steps:
   1. Backup your system before installing this, or any, package.
   2. Copy the tar file from the CD:
        cp /cdrom/Solaris8/ACE_CC.tar /tmp
   3. Extract the tar file:
        cd /tmp
        tar xf ACE_CC.tar
   4. Install the package using the pkgadd command:
        pkgadd -d /tmp RVRaceCC
   5. The installation will prompt you to install the 4 parts of the
      package: ACE base, Documentation, Network services, and Example/test
      program sources. The total disk space required for all 4 parts is 
      approximately 40 MB.

. Solaris 8 for SPARC using g++ 3.2.2
  This kit was built on Solaris 8 for SPARC using g++ 3.2.2. It contains a
  32-bit version of both the shared and archive ACE library. The libraries
  are built optimized, without symbolic debugging information, without
  exception support.

  The kit is delivered as a tar file that should be copied to a local disk
  and expanded for installation using the pkgadd utility.
  These are the installation steps:
   1. Backup your system before installing this, or any, package.
   2. Copy the tar file from the CD:
        cp /cdrom/Solaris8/ACE_gcc.tar /tmp
   3. Extract the tar file:
        cd /tmp
        tar xf ACE_gcc.tar
   4. Install the package using the pkgadd command:
        pkgadd -d /tmp RVRacegcc
   3. The installation will prompt you to install the 4 parts of the
      package: ACE base, Documentation, Network services, and Example/test
      program sources. The total disk space required for all 4 parts is 
      approximately 40 MB.

. Solaris 9 for SPARC using Sun Forte Developer 7
  This kit was built on Solaris 9 for SPARC using Sun Forte Developer 7
  (C++ 5.4).

  The kit is delivered as a tar file that should be copied to a local disk
  and expanded for installation using the pkgadd utility.
  These are the installation steps:
   1. Backup your system before installing this, or any, package.
   2. Copy the tar file from the CD:
        cp /cdrom/Solaris9/ACE_CC.tar /tmp
   3. Extract the tar file:
        cd /tmp
        tar xf ACE_CC.tar
   4. Install the package using the pkgadd command:
        pkgadd -d /tmp RVRaceCC
   5. The installation will prompt you to install the 4 parts of the
      package: ACE base, Documentation, Network services, and Example/test
      program sources. The total disk space required for all 4 parts is 
      approximately 40 MB.

. Solaris 9 for SPARC using g++ 3.2
  This kit was built on Solaris 8 for SPARC using g++ 3.2. It contains a
  32-bit version of both the shared and archive ACE library. The libraries
  are built optimized, without symbolic debugging information, without
  exception support.

  The kit is delivered as a tar file that should be copied to a local disk
  and expanded for installation using the pkgadd utility.
  These are the installation steps:
   1. Backup your system before installing this, or any, package.
   2. Copy the tar file from the CD:
        cp /cdrom/Solaris9/ACE_gcc.tar /tmp
   3. Extract the tar file:
        cd /tmp
        tar xf ACE_gcc.tar
   4. Install the package using the pkgadd command:
        pkgadd -d /tmp RVRacegcc
   3. The installation will prompt you to install the 4 parts of the
      package: ACE base, Documentation, Network services, and Example/test
      program sources. The total disk space required for all 4 parts is 
      approximately 40 MB.
