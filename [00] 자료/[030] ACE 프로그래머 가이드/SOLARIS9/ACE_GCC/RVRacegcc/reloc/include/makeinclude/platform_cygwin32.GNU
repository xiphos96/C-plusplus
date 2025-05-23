# platform_cygwin32.GNU,v 4.3 2003/01/02 13:52:41 bala Exp

#
# This file should allow to build ACE for cygwin32 with cygwin tools.
#
# Edit to change TCPU and w32api defs below.
#
# Don't forget to define the ACE_ROOT environment variable!
#

#
# Chose your target CPU (uncomment ONE of these).
#
TCPU = pentiumpro
#TCPU = pentium
#TCPU = i486
#TCPU = i386

cygwin32 = 1
optimize = 0

# Cygwin doesn't allow to add the version number of ACE to the dll name
# because fe ace.dll.5.2.3 isn't a valid dll name
SONAME=
SOVERSION=

# Add --enable-auto-import to the linker flags. This will result in the
# linker doing auto-import without giving warnings about it.
LDFLAGS += --enable-auto-import

include $(ACE_ROOT)/include/makeinclude/platform_gnuwin32_common.GNU
