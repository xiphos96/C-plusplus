# Makefile,v 1.1 2003/10/09 17:38:39 shuston Exp
#
# Copyright 2003 Addison-Wesley Inc. All Rights Reserved.

BIN     = Answerer

FILES	= CommandModule \
	  CommandStream \
	  CommandTask \
	  CommandTasks \
	  RecordingDeviceFactory \
	  RecordingDevice_Text

SRC	= $(addsuffix .cpp,$(FILES))
OBJ	= $(addsuffix .o,$(FILES))

BUILD   = $(VBIN)

include $(ACE_ROOT)/include/makeinclude/wrapper_macros.GNU
include $(ACE_ROOT)/include/makeinclude/macros.GNU
include $(ACE_ROOT)/include/makeinclude/rules.common.GNU
include $(ACE_ROOT)/include/makeinclude/rules.nonested.GNU
include $(ACE_ROOT)/include/makeinclude/rules.bin.GNU
include $(ACE_ROOT)/include/makeinclude/rules.local.GNU
