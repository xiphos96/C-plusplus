# Hey Emacs, this is a -*- Makefile -*-

# platform_linux_borland.GNU

# debug = 1
# optimize = 1

ifndef BCB
BCB = /usr/local/kylix3
endif

ifndef exceptions
  exceptions = 1
endif
ifeq (,$(debug))
  debug = 1
endif
ifeq (,$(optimize))
  optimize = 1
endif

ifeq (,$(threads))
  threads = 1
endif

ifeq ($(threads),0)
  CPPFLAGS += -DACE_MT_SAFE=0
endif # threads

PLATFORM_XT_CPPFLAGS=
PLATFORM_XT_LIBS=-lXt
PLATFORM_XT_LDFLAGS=

PLATFORM_FL_CPPFLAGS=
PLATFORM_FL_LIBS=-lfltk
PLATFORM_FL_LDFLAGS=

PLATFORM_X11_CPPFLAGS=-I/usr/X11R6/include
PLATFORM_X11_LIBS=-lX11
PLATFORM_X11_LDFLAGS=-L/usr/X11R6/lib

PLATFORM_GL_CPPFLAGS=-I/usr/X11R6/include
PLATFORM_GL_LIBS    =-lGL
PLATFORM_GL_LDFLAGS =-L/usr/X11R6/lib

PLATFORM_GTK_CPPFLAGS=$(shell gtk-config --cflags)
PLATFORM_GTK_LIBS    =$(shell gtk-config --libs)
PLATFORM_GTK_LDFLAGS=

PLATFORM_WX_CPPFLAGS= $(shell wx-config --cflags) $(PLATFORM_GTK_CPPFLAGS)
PLATFORM_WX_LIBS    = $(shell wx-config --libs)   $(PLATFORM_GTK_LIBS)
PLATFORM_WX_LDFLAGS =

PLATFORM_AIO_SUPPORT := \
       $(shell test -e /usr/lib/librt.so && echo -DACE_HAS_AIO_CALLS)

ifeq ($(insure),1)
CC  = insure
CXX = insure
else
CC  = $(BCB)/bin/bc++
CXX = $(BCB)/bin/bc++
endif

# Test for template instantiation.
#

#
# Common flags
#

ifdef debug
DCFLAGS = -v -y -Od -r- -vi- -D_DEBUG 
DCCFLAGS = #-v -y -Od -r- -vi- -k -D_DEBUG
else
DCFLAGS = -DNDEBUG
DCCFLAGS =
endif

kylix_build = 1
INCLUDEPATH = $(BCB)/include/stlport:$(BCB)/include:$(BCB)/include/vcl:/usr/include:$(ACE_ROOT)
LIBPATH = $(BCB)/lib/obj:$(BCB)/lib:/usr/lib:/lib:/usr/X11R6/lib:$(BCB)/bin
ACELIBPATH = $(ACE_ROOT)/ace:./

AR      = ar
ARFLAGS = rsuv
RANLIB  = @true

DLD     = $(BCB)/bin/ilink
LD      = $(BCB)/bin/ilink

WARNINGS_CFLAGS = -w-rvl -w-rch -w-ccc -w-obs -w-aus -w-pia -w-inl
BUILDSOFLAGS = -DACE_BUILD_DLL -DACE_OS_BUILD_DLL -DTAO_IDL_FE_BUILD_DLL -DTAO_IDL_BE_BUILD_DLL \
	-DTAO_BUILD_DLL -DTAO_EVENT_BUILD_DLL -DTAO_AV_BUILD_DLL

CFLAGS = $(BUILDSOFLAGS) $(WARNINGS_CFLAGS) -q -VP -Vx -a8 -b- -k $(DCFLAGS) \
	-c -I$(INCLUDEPATH) 

CPPFLAGS += #$(CFLAGS) 
CCFLAGS += $(CFLAGS)
BORLDFLAGS = -c -L$(LIBPATH):$(ACELIBPATH) -x -Gn -v -L$(LIBPATH):$(ACELIBPATH)
BORINITOBJ = borinitso.o borinit.o crt1.o 
BORSHAREDOBJ += libborcrtl.so libborstl.so libborunwind.so \
	libpthread.so libc.so libm.so libdl.so

PRELINK=
SOFLAGS= $(BORSHAREDOBJ) borinitso.o -Tpd
#ACELIB= libACE.so
#TAO_IDL_FE_LIB= libTAO_IDL_FE_DLL.so

SOLINK.cc = $(LD) $(BORINITOBJ) -Tpd 
LINK.cc = override
LINK.cc.override = $(LD) $(LDFLAGS) $(VLDLIBS) $(BORINITOBJ) $(BORSHAREDOBJ) $(BORLDFLAGS) $(POSTLINK)  

SONAME= 
SOVERSION=
#  ARFLAGS      Flags for the archive utility (ar)
#  CC           C compiler command
#  CXX          C++ compiler command
#  COMPILE.c    Flags for compiling with C
#  COMPILE.cc   Flags for compiling with C++
#  CPPFLAGS     C pre-processor flags
#  CFLAGS       C compilation flags
#  CCFLAGS      C++ compilation flags
#  DCFLAGS      C compilation flags for debugging
#  DCCFLAGS     C++ compilation flags for debugging
#  DEFFLAGS     C++ preprocessor flag for defining symbols
#  DLD          Name of dynamic linker
#  LD           Name of linker
#  IDL          Name of the CORBA IDL compiler
#  TEMPLATES_FLAG Flag to pass to the compiler to control the instantiation of
# 		  templates.
#  INSBIN       Binary (executable) installation directory
#  INSINC       Include file installation directory
#  INSMAN       Manpage installation directory
#  INSLIB       Library installation directory
#  LDFLAGS      ld linker flags
#  LINK.c       Flags for linking with C
#  LINK.cc      Flags for linking with C++
#  MAKEFLAGS    Flags that are passed into the compilation from the commandline
#  OCFLAGS      Optimizing C compilation flags
#  OCCFLAGS     Optimizing C++ compilation flags
#  PCFLAGS      C compilation flags for profiling
#  PCCFLAGS     C++ compilation flags for profiling
