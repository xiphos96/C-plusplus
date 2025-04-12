# Makefile,v 1.1 2003/09/26 16:44:34 shuston Exp
#
# Copyright 2003 Addison-Wesley Inc. All Rights Reserved.

BIN =	DLList \
	Stacks \
	Queues \
	Array \
	Sets \
	Map_Manager \
	Map_Manager_Specialization \
	Hash_Map \
	Hash_Map_Hash \
	RB_Tree \
	RB_Tree_Functors \
	Allocator

SOURCES = $(addsuffix .cpp,$(BIN))
HEADERS = $(wildcard *.h)

OUT  = $(addsuffix .out,$(BIN))

All : $(VBIN) $(OUT) html

include $(ACE_ROOT)/include/makeinclude/wrapper_macros.GNU
include $(ACE_ROOT)/include/makeinclude/macros.GNU
include $(ACE_ROOT)/include/makeinclude/rules.common.GNU
include $(ACE_ROOT)/include/makeinclude/rules.nonested.GNU
include $(ACE_ROOT)/include/makeinclude/rules.bin.GNU
include $(ACE_ROOT)/include/makeinclude/rules.local.GNU
