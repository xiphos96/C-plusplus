# Makefile,v 1.1 2003/10/07 15:54:15 shuston Exp
#
# Copyright 2003 Addison-Wesley Inc. All Rights Reserved.

BIN =	Atomic_Op \
	Barrier \
	Mutex \
	RW_Lock \
	Semaphore \
	Tokens \
	Tokens_Deadlock \
	TSS

SOURCES = $(addsuffix .cpp,$(BIN))

include $(ACE_ROOT)/include/makeinclude/wrapper_macros.GNU
include $(ACE_ROOT)/include/makeinclude/macros.GNU
include $(ACE_ROOT)/include/makeinclude/rules.common.GNU
include $(ACE_ROOT)/include/makeinclude/rules.nonested.GNU
include $(ACE_ROOT)/include/makeinclude/rules.bin.GNU
include $(ACE_ROOT)/include/makeinclude/rules.local.GNU
