#----------------------------------------------------------------------------
# Makefile.SLD,v 1.3 2002/12/23 17:15:12 shuston Exp
#
# Makefile for the SLD library in the C++NPv2, Chapter 5 example.
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
#       Local macros
#----------------------------------------------------------------------------

SHLIB   = libSLD.$(SOEXT)
FILES   = SLD \
          Logging_Acceptor \
          Logging_Event_Handler \
          Logging_Handler
LSRC    = $(addsuffix .cpp,$(FILES))

LIBS   += $(ACELIB)

BUILD   = $(VSHLIB)

#----------------------------------------------------------------------------
#       Include macros and targets
#----------------------------------------------------------------------------

include $(ACE_ROOT)/include/makeinclude/wrapper_macros.GNU
include $(ACE_ROOT)/include/makeinclude/macros.GNU
include $(ACE_ROOT)/include/makeinclude/rules.common.GNU
include $(ACE_ROOT)/include/makeinclude/rules.nonested.GNU
include $(ACE_ROOT)/include/makeinclude/rules.lib.GNU
include $(ACE_ROOT)/include/makeinclude/rules.local.GNU
