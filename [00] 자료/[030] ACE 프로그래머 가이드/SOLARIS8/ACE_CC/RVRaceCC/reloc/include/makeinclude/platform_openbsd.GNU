# platform_openbsd.GNU,v 1.1 2002/10/15 01:22:54 fhunleth Exp

# platform_openbsd.GNU

# ***** Notice: This file is still under testing. *****
# To be used on an OpenBSD platform without pthread support.

versioned_so = 1

ifndef exceptions
  exceptions = 1
endif

ifeq (,$(debug))
  debug = 1
endif

ifeq (,$(optimize))
  optimize = 1
endif

CC              = gcc
CXX		= g++

# Setting the internal name and version of shared libraries isn't supported
# by OpenBSD.  In fact, the -h option gives an error and interestingly
# enough, the -soname option doesn't but just ignores its parameter.
SONAME =

include $(ACE_ROOT)/include/makeinclude/platform_g++_common.GNU

CFLAGS          += -W -Wall -Wpointer-arith -pipe
CCFLAGS         += $(CFLAGS) $(TEMPLATES_FLAG)
DCFLAGS         += -g
LDFLAGS		+= -Wl,-rpath $(ACE_ROOT)/ace
DLD             = $(CXX)
LD		= $(CXX)
LIBS            += -lstdc++
OCFLAGS         += -O2
PIC             = -fpic
AR              = ar
ARFLAGS         = ruv
RANLIB          = ranlib

#SOFLAGS += -Bshareable -x /usr/lib/c++rt0.o
SOFLAGS += $(CPPFLAGS) -shared
SOBUILD = $(COMPILE.cc) $(PIC) -o $(VSHDIR)$*.so  $<
PRELIB = @echo
