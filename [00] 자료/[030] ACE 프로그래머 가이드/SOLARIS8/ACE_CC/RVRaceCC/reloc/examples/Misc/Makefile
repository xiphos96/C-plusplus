#----------------------------------------------------------------------------
#	Makefile,v 4.42 2002/11/16 15:37:15 bala Exp
#
#	Makefile for testing the miscellaneous ACE components.
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
#	Local macros
#----------------------------------------------------------------------------

BIN     = test_dump \
	  test_get_opt \
	  test_profile_timer \
	  test_read_buffer \
	  test_set \
	  test_sstring \
	  test_trace 

# Uncomment the following if you want to test out the XtReactor.
#	  test_XtReactor1 \
#	  test_XtReactor2

LSRC    = $(addsuffix .cpp,$(BIN))

LDLIBS  = 

VLDLIBS = $(LDLIBS:%=%$(VAR))

BUILD   = $(VBIN)

#----------------------------------------------------------------------------
#	Include macros and targets
#----------------------------------------------------------------------------

include	$(ACE_ROOT)/include/makeinclude/wrapper_macros.GNU
include	$(ACE_ROOT)/include/makeinclude/macros.GNU
include	$(ACE_ROOT)/include/makeinclude/rules.common.GNU
include	$(ACE_ROOT)/include/makeinclude/rules.nonested.GNU
include	$(ACE_ROOT)/include/makeinclude/rules.bin.GNU
include	$(ACE_ROOT)/include/makeinclude/rules.local.GNU

# To build multiple executables in the same directory on AIX, it works
# best to wipe out any previously-created tempinc directory.
# The compiler/linker isn't too smart about instantiating templates...
ifdef TEMPINCDIR
COMPILE.cc := $(RM) -rf tempinc; $(COMPILE.cc)
endif

#----------------------------------------------------------------------------
#	Local targets
#----------------------------------------------------------------------------
 
#----------------------------------------------------------------------------
#	Dependencies
#----------------------------------------------------------------------------

# DO NOT DELETE THIS LINE -- g++dep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.


.obj/test_dump.o .obj/test_dump.so .shobj/test_dump.o .shobj/test_dump.so: test_dump.cpp \
 $(ACE_ROOT)/ace/Dump.h \
 $(ACE_ROOT)/ace/pre.h \
 $(ACE_ROOT)/ace/Synch.h \
 $(ACE_ROOT)/ace/ACE_export.h \
 $(ACE_ROOT)/ace/post.h \
 $(ACE_ROOT)/ace/ace_wchar.h \
 $(ACE_ROOT)/ace/ace_wchar.inl \
 $(ACE_ROOT)/ace/OS.h \
 $(ACE_ROOT)/ace/OS_Dirent.h \
 $(ACE_ROOT)/ace/OS_Export.h \
 $(ACE_ROOT)/ace/OS_Errno.h \
 $(ACE_ROOT)/ace/OS_Errno.inl \
 $(ACE_ROOT)/ace/OS_Dirent.inl \
 $(ACE_ROOT)/ace/OS_String.h \
 $(ACE_ROOT)/ace/Basic_Types.h \
 $(ACE_ROOT)/ace/Basic_Types.i \
 $(ACE_ROOT)/ace/OS_String.inl \
 $(ACE_ROOT)/ace/OS_Memory.h \
 $(ACE_ROOT)/ace/OS_Memory.inl \
 $(ACE_ROOT)/ace/OS_TLI.h \
 $(ACE_ROOT)/ace/OS_TLI.inl \
 $(ACE_ROOT)/ace/Time_Value.h \
 $(ACE_ROOT)/ace/Time_Value.inl \
 $(ACE_ROOT)/ace/Default_Constants.h \
 $(ACE_ROOT)/ace/Global_Macros.h \
 $(ACE_ROOT)/ace/Min_Max.h \
 $(ACE_ROOT)/ace/streams.h \
 $(ACE_ROOT)/ace/Trace.h \
 $(ACE_ROOT)/ace/OS.i \
 $(ACE_ROOT)/ace/Synch.i \
 $(ACE_ROOT)/ace/Synch_T.h \
 $(ACE_ROOT)/ace/Synch_T.i \
 $(ACE_ROOT)/ace/Thread.h \
 $(ACE_ROOT)/ace/Thread_Adapter.h \
 $(ACE_ROOT)/ace/Base_Thread_Adapter.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.inl \
 $(ACE_ROOT)/ace/Base_Thread_Adapter.inl \
 $(ACE_ROOT)/ace/Thread_Adapter.inl \
 $(ACE_ROOT)/ace/Thread.i \
 $(ACE_ROOT)/ace/Synch_T.cpp \
 $(ACE_ROOT)/ace/Log_Msg.h \
 $(ACE_ROOT)/ace/Log_Priority.h \
 $(ACE_ROOT)/ace/Dump_T.h \
 $(ACE_ROOT)/ace/Dump_T.cpp \
 test_dump.h \
 $(ACE_ROOT)/ace/Reactor.h \
 $(ACE_ROOT)/ace/Handle_Set.h \
 $(ACE_ROOT)/ace/Handle_Set.i \
 $(ACE_ROOT)/ace/Timer_Queue.h \
 $(ACE_ROOT)/ace/Timer_Queue_T.h \
 $(ACE_ROOT)/ace/Free_List.h \
 $(ACE_ROOT)/ace/Free_List.i \
 $(ACE_ROOT)/ace/Free_List.cpp \
 $(ACE_ROOT)/ace/Test_and_Set.h \
 $(ACE_ROOT)/ace/Event_Handler.h \
 $(ACE_ROOT)/ace/Event_Handler.i \
 $(ACE_ROOT)/ace/Test_and_Set.i \
 $(ACE_ROOT)/ace/Test_and_Set.cpp \
 $(ACE_ROOT)/ace/Timer_Queue_T.i \
 $(ACE_ROOT)/ace/Timer_Queue_T.cpp \
 $(ACE_ROOT)/ace/Signal.h \
 $(ACE_ROOT)/ace/Signal.i \
 $(ACE_ROOT)/ace/Reactor.i \
 $(ACE_ROOT)/ace/Reactor_Impl.h

.obj/test_get_opt.o .obj/test_get_opt.so .shobj/test_get_opt.o .shobj/test_get_opt.so: test_get_opt.cpp \
 $(ACE_ROOT)/ace/Get_Opt.h \
 $(ACE_ROOT)/ace/pre.h \
 $(ACE_ROOT)/ace/SString.h \
 $(ACE_ROOT)/ace/String_Base.h \
 $(ACE_ROOT)/ace/ACE.h \
 $(ACE_ROOT)/ace/OS.h \
 $(ACE_ROOT)/ace/post.h \
 $(ACE_ROOT)/ace/ace_wchar.h \
 $(ACE_ROOT)/ace/ace_wchar.inl \
 $(ACE_ROOT)/ace/OS_Dirent.h \
 $(ACE_ROOT)/ace/OS_Export.h \
 $(ACE_ROOT)/ace/OS_Errno.h \
 $(ACE_ROOT)/ace/OS_Errno.inl \
 $(ACE_ROOT)/ace/OS_Dirent.inl \
 $(ACE_ROOT)/ace/OS_String.h \
 $(ACE_ROOT)/ace/Basic_Types.h \
 $(ACE_ROOT)/ace/ACE_export.h \
 $(ACE_ROOT)/ace/Basic_Types.i \
 $(ACE_ROOT)/ace/OS_String.inl \
 $(ACE_ROOT)/ace/OS_Memory.h \
 $(ACE_ROOT)/ace/OS_Memory.inl \
 $(ACE_ROOT)/ace/OS_TLI.h \
 $(ACE_ROOT)/ace/OS_TLI.inl \
 $(ACE_ROOT)/ace/Time_Value.h \
 $(ACE_ROOT)/ace/Time_Value.inl \
 $(ACE_ROOT)/ace/Default_Constants.h \
 $(ACE_ROOT)/ace/Global_Macros.h \
 $(ACE_ROOT)/ace/Min_Max.h \
 $(ACE_ROOT)/ace/streams.h \
 $(ACE_ROOT)/ace/Trace.h \
 $(ACE_ROOT)/ace/OS.i \
 $(ACE_ROOT)/ace/Flag_Manip.h \
 $(ACE_ROOT)/ace/Flag_Manip.i \
 $(ACE_ROOT)/ace/Handle_Ops.h \
 $(ACE_ROOT)/ace/Handle_Ops.i \
 $(ACE_ROOT)/ace/Lib_Find.h \
 $(ACE_ROOT)/ace/Lib_Find.i \
 $(ACE_ROOT)/ace/Init_ACE.h \
 $(ACE_ROOT)/ace/Init_ACE.i \
 $(ACE_ROOT)/ace/Sock_Connect.h \
 $(ACE_ROOT)/ace/Sock_Connect.i \
 $(ACE_ROOT)/ace/ACE.i \
 $(ACE_ROOT)/ace/String_Base_Const.h \
 $(ACE_ROOT)/ace/String_Base.i \
 $(ACE_ROOT)/ace/Malloc_Base.h \
 $(ACE_ROOT)/ace/String_Base.cpp \
 $(ACE_ROOT)/ace/Malloc.h \
 $(ACE_ROOT)/ace/Log_Msg.h \
 $(ACE_ROOT)/ace/Log_Priority.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.inl \
 $(ACE_ROOT)/ace/Malloc.i \
 $(ACE_ROOT)/ace/Malloc_T.h \
 $(ACE_ROOT)/ace/Synch.h \
 $(ACE_ROOT)/ace/Synch.i \
 $(ACE_ROOT)/ace/Synch_T.h \
 $(ACE_ROOT)/ace/Synch_T.i \
 $(ACE_ROOT)/ace/Thread.h \
 $(ACE_ROOT)/ace/Thread_Adapter.h \
 $(ACE_ROOT)/ace/Base_Thread_Adapter.h \
 $(ACE_ROOT)/ace/Base_Thread_Adapter.inl \
 $(ACE_ROOT)/ace/Thread_Adapter.inl \
 $(ACE_ROOT)/ace/Thread.i \
 $(ACE_ROOT)/ace/Synch_T.cpp \
 $(ACE_ROOT)/ace/Malloc_Allocator.h \
 $(ACE_ROOT)/ace/Malloc_Allocator.i \
 $(ACE_ROOT)/ace/Free_List.h \
 $(ACE_ROOT)/ace/Free_List.i \
 $(ACE_ROOT)/ace/Free_List.cpp \
 $(ACE_ROOT)/ace/Malloc_T.i \
 $(ACE_ROOT)/ace/Malloc_T.cpp \
 $(ACE_ROOT)/ace/Memory_Pool.h \
 $(ACE_ROOT)/ace/Event_Handler.h \
 $(ACE_ROOT)/ace/Event_Handler.i \
 $(ACE_ROOT)/ace/Signal.h \
 $(ACE_ROOT)/ace/Signal.i \
 $(ACE_ROOT)/ace/Mem_Map.h \
 $(ACE_ROOT)/ace/Mem_Map.i \
 $(ACE_ROOT)/ace/SV_Semaphore_Complex.h \
 $(ACE_ROOT)/ace/SV_Semaphore_Simple.h \
 $(ACE_ROOT)/ace/SV_Semaphore_Simple.i \
 $(ACE_ROOT)/ace/SV_Semaphore_Complex.i \
 $(ACE_ROOT)/ace/Unbounded_Set.h \
 $(ACE_ROOT)/ace/Node.h \
 $(ACE_ROOT)/ace/Node.cpp \
 $(ACE_ROOT)/ace/Unbounded_Set.inl \
 $(ACE_ROOT)/ace/Unbounded_Set.cpp \
 $(ACE_ROOT)/ace/Memory_Pool.i \
 $(ACE_ROOT)/ace/Auto_Ptr.h \
 $(ACE_ROOT)/ace/Auto_Ptr.i \
 $(ACE_ROOT)/ace/Auto_Ptr.cpp \
 $(ACE_ROOT)/ace/SString.i \
 $(ACE_ROOT)/ace/Containers.h \
 $(ACE_ROOT)/ace/Containers.i \
 $(ACE_ROOT)/ace/Containers_T.h \
 $(ACE_ROOT)/ace/Array_Base.h \
 $(ACE_ROOT)/ace/Array_Base.inl \
 $(ACE_ROOT)/ace/Array_Base.cpp \
 $(ACE_ROOT)/ace/Unbounded_Queue.h \
 $(ACE_ROOT)/ace/Unbounded_Queue.inl \
 $(ACE_ROOT)/ace/Unbounded_Queue.cpp \
 $(ACE_ROOT)/ace/Containers_T.i \
 $(ACE_ROOT)/ace/Containers_T.cpp \
 $(ACE_ROOT)/ace/Get_Opt.i

.obj/test_profile_timer.o .obj/test_profile_timer.so .shobj/test_profile_timer.o .shobj/test_profile_timer.so: test_profile_timer.cpp \
 $(ACE_ROOT)/ace/Profile_Timer.h \
 $(ACE_ROOT)/ace/pre.h \
 $(ACE_ROOT)/ace/post.h \
 $(ACE_ROOT)/ace/ace_wchar.h \
 $(ACE_ROOT)/ace/ace_wchar.inl \
 $(ACE_ROOT)/ace/OS.h \
 $(ACE_ROOT)/ace/OS_Dirent.h \
 $(ACE_ROOT)/ace/OS_Export.h \
 $(ACE_ROOT)/ace/OS_Errno.h \
 $(ACE_ROOT)/ace/OS_Errno.inl \
 $(ACE_ROOT)/ace/OS_Dirent.inl \
 $(ACE_ROOT)/ace/OS_String.h \
 $(ACE_ROOT)/ace/Basic_Types.h \
 $(ACE_ROOT)/ace/ACE_export.h \
 $(ACE_ROOT)/ace/Basic_Types.i \
 $(ACE_ROOT)/ace/OS_String.inl \
 $(ACE_ROOT)/ace/OS_Memory.h \
 $(ACE_ROOT)/ace/OS_Memory.inl \
 $(ACE_ROOT)/ace/OS_TLI.h \
 $(ACE_ROOT)/ace/OS_TLI.inl \
 $(ACE_ROOT)/ace/Time_Value.h \
 $(ACE_ROOT)/ace/Time_Value.inl \
 $(ACE_ROOT)/ace/Default_Constants.h \
 $(ACE_ROOT)/ace/Global_Macros.h \
 $(ACE_ROOT)/ace/Min_Max.h \
 $(ACE_ROOT)/ace/streams.h \
 $(ACE_ROOT)/ace/Trace.h \
 $(ACE_ROOT)/ace/OS.i \
 $(ACE_ROOT)/ace/High_Res_Timer.h \
 $(ACE_ROOT)/ace/High_Res_Timer.i \
 $(ACE_ROOT)/ace/Profile_Timer.i \
 $(ACE_ROOT)/ace/Log_Msg.h \
 $(ACE_ROOT)/ace/Log_Priority.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.inl

.obj/test_read_buffer.o .obj/test_read_buffer.so .shobj/test_read_buffer.o .shobj/test_read_buffer.so: test_read_buffer.cpp \
 $(ACE_ROOT)/ace/Service_Config.h \
 $(ACE_ROOT)/ace/pre.h \
 $(ACE_ROOT)/ace/post.h \
 $(ACE_ROOT)/ace/ace_wchar.h \
 $(ACE_ROOT)/ace/ace_wchar.inl \
 $(ACE_ROOT)/ace/Service_Types.h \
 $(ACE_ROOT)/ace/Service_Object.h \
 $(ACE_ROOT)/ace/Shared_Object.h \
 $(ACE_ROOT)/ace/ACE_export.h \
 $(ACE_ROOT)/ace/OS.h \
 $(ACE_ROOT)/ace/OS_Dirent.h \
 $(ACE_ROOT)/ace/OS_Export.h \
 $(ACE_ROOT)/ace/OS_Errno.h \
 $(ACE_ROOT)/ace/OS_Errno.inl \
 $(ACE_ROOT)/ace/OS_Dirent.inl \
 $(ACE_ROOT)/ace/OS_String.h \
 $(ACE_ROOT)/ace/Basic_Types.h \
 $(ACE_ROOT)/ace/Basic_Types.i \
 $(ACE_ROOT)/ace/OS_String.inl \
 $(ACE_ROOT)/ace/OS_Memory.h \
 $(ACE_ROOT)/ace/OS_Memory.inl \
 $(ACE_ROOT)/ace/OS_TLI.h \
 $(ACE_ROOT)/ace/OS_TLI.inl \
 $(ACE_ROOT)/ace/Time_Value.h \
 $(ACE_ROOT)/ace/Time_Value.inl \
 $(ACE_ROOT)/ace/Default_Constants.h \
 $(ACE_ROOT)/ace/Global_Macros.h \
 $(ACE_ROOT)/ace/Min_Max.h \
 $(ACE_ROOT)/ace/streams.h \
 $(ACE_ROOT)/ace/Trace.h \
 $(ACE_ROOT)/ace/OS.i \
 $(ACE_ROOT)/ace/Shared_Object.i \
 $(ACE_ROOT)/ace/Svc_Conf_Tokens.h \
 $(ACE_ROOT)/ace/Event_Handler.h \
 $(ACE_ROOT)/ace/Event_Handler.i \
 $(ACE_ROOT)/ace/DLL.h \
 $(ACE_ROOT)/ace/Service_Object.i \
 $(ACE_ROOT)/ace/ACE.h \
 $(ACE_ROOT)/ace/Flag_Manip.h \
 $(ACE_ROOT)/ace/Flag_Manip.i \
 $(ACE_ROOT)/ace/Handle_Ops.h \
 $(ACE_ROOT)/ace/Handle_Ops.i \
 $(ACE_ROOT)/ace/Lib_Find.h \
 $(ACE_ROOT)/ace/Lib_Find.i \
 $(ACE_ROOT)/ace/Init_ACE.h \
 $(ACE_ROOT)/ace/Init_ACE.i \
 $(ACE_ROOT)/ace/Sock_Connect.h \
 $(ACE_ROOT)/ace/Sock_Connect.i \
 $(ACE_ROOT)/ace/ACE.i \
 $(ACE_ROOT)/ace/Synch.h \
 $(ACE_ROOT)/ace/Synch.i \
 $(ACE_ROOT)/ace/Synch_T.h \
 $(ACE_ROOT)/ace/Synch_T.i \
 $(ACE_ROOT)/ace/Thread.h \
 $(ACE_ROOT)/ace/Thread_Adapter.h \
 $(ACE_ROOT)/ace/Base_Thread_Adapter.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.inl \
 $(ACE_ROOT)/ace/Base_Thread_Adapter.inl \
 $(ACE_ROOT)/ace/Thread_Adapter.inl \
 $(ACE_ROOT)/ace/Thread.i \
 $(ACE_ROOT)/ace/Synch_T.cpp \
 $(ACE_ROOT)/ace/Log_Msg.h \
 $(ACE_ROOT)/ace/Log_Priority.h \
 $(ACE_ROOT)/ace/Service_Types.i \
 $(ACE_ROOT)/ace/Signal.h \
 $(ACE_ROOT)/ace/Signal.i \
 $(ACE_ROOT)/ace/Unbounded_Queue.h \
 $(ACE_ROOT)/ace/Node.h \
 $(ACE_ROOT)/ace/Node.cpp \
 $(ACE_ROOT)/ace/Unbounded_Queue.inl \
 $(ACE_ROOT)/ace/Unbounded_Queue.cpp \
 $(ACE_ROOT)/ace/Malloc_Base.h \
 $(ACE_ROOT)/ace/Unbounded_Set.h \
 $(ACE_ROOT)/ace/Unbounded_Set.inl \
 $(ACE_ROOT)/ace/Unbounded_Set.cpp \
 $(ACE_ROOT)/ace/SString.h \
 $(ACE_ROOT)/ace/String_Base.h \
 $(ACE_ROOT)/ace/String_Base_Const.h \
 $(ACE_ROOT)/ace/String_Base.i \
 $(ACE_ROOT)/ace/String_Base.cpp \
 $(ACE_ROOT)/ace/Malloc.h \
 $(ACE_ROOT)/ace/Malloc.i \
 $(ACE_ROOT)/ace/Malloc_T.h \
 $(ACE_ROOT)/ace/Malloc_Allocator.h \
 $(ACE_ROOT)/ace/Malloc_Allocator.i \
 $(ACE_ROOT)/ace/Free_List.h \
 $(ACE_ROOT)/ace/Free_List.i \
 $(ACE_ROOT)/ace/Free_List.cpp \
 $(ACE_ROOT)/ace/Malloc_T.i \
 $(ACE_ROOT)/ace/Malloc_T.cpp \
 $(ACE_ROOT)/ace/Memory_Pool.h \
 $(ACE_ROOT)/ace/Mem_Map.h \
 $(ACE_ROOT)/ace/Mem_Map.i \
 $(ACE_ROOT)/ace/SV_Semaphore_Complex.h \
 $(ACE_ROOT)/ace/SV_Semaphore_Simple.h \
 $(ACE_ROOT)/ace/SV_Semaphore_Simple.i \
 $(ACE_ROOT)/ace/SV_Semaphore_Complex.i \
 $(ACE_ROOT)/ace/Memory_Pool.i \
 $(ACE_ROOT)/ace/Auto_Ptr.h \
 $(ACE_ROOT)/ace/Auto_Ptr.i \
 $(ACE_ROOT)/ace/Auto_Ptr.cpp \
 $(ACE_ROOT)/ace/SString.i \
 $(ACE_ROOT)/ace/XML_Svc_Conf.h \
 $(ACE_ROOT)/ace/Service_Config.i \
 $(ACE_ROOT)/ace/Reactor.h \
 $(ACE_ROOT)/ace/Handle_Set.h \
 $(ACE_ROOT)/ace/Handle_Set.i \
 $(ACE_ROOT)/ace/Timer_Queue.h \
 $(ACE_ROOT)/ace/Timer_Queue_T.h \
 $(ACE_ROOT)/ace/Test_and_Set.h \
 $(ACE_ROOT)/ace/Test_and_Set.i \
 $(ACE_ROOT)/ace/Test_and_Set.cpp \
 $(ACE_ROOT)/ace/Timer_Queue_T.i \
 $(ACE_ROOT)/ace/Timer_Queue_T.cpp \
 $(ACE_ROOT)/ace/Reactor.i \
 $(ACE_ROOT)/ace/Reactor_Impl.h \
 $(ACE_ROOT)/ace/Read_Buffer.h \
 $(ACE_ROOT)/ace/Read_Buffer.i

.obj/test_set.o .obj/test_set.so .shobj/test_set.o .shobj/test_set.so: test_set.cpp \
 $(ACE_ROOT)/ace/Containers.h \
 $(ACE_ROOT)/ace/pre.h \
 $(ACE_ROOT)/ace/ACE_export.h \
 $(ACE_ROOT)/ace/post.h \
 $(ACE_ROOT)/ace/ace_wchar.h \
 $(ACE_ROOT)/ace/ace_wchar.inl \
 $(ACE_ROOT)/ace/Containers.i \
 $(ACE_ROOT)/ace/Containers_T.h \
 $(ACE_ROOT)/ace/Node.h \
 $(ACE_ROOT)/ace/Node.cpp \
 $(ACE_ROOT)/ace/Array_Base.h \
 $(ACE_ROOT)/ace/Global_Macros.h \
 $(ACE_ROOT)/ace/OS_Export.h \
 $(ACE_ROOT)/ace/OS.h \
 $(ACE_ROOT)/ace/OS_Dirent.h \
 $(ACE_ROOT)/ace/OS_Errno.h \
 $(ACE_ROOT)/ace/OS_Errno.inl \
 $(ACE_ROOT)/ace/OS_Dirent.inl \
 $(ACE_ROOT)/ace/OS_String.h \
 $(ACE_ROOT)/ace/Basic_Types.h \
 $(ACE_ROOT)/ace/Basic_Types.i \
 $(ACE_ROOT)/ace/OS_String.inl \
 $(ACE_ROOT)/ace/OS_Memory.h \
 $(ACE_ROOT)/ace/OS_Memory.inl \
 $(ACE_ROOT)/ace/OS_TLI.h \
 $(ACE_ROOT)/ace/OS_TLI.inl \
 $(ACE_ROOT)/ace/Time_Value.h \
 $(ACE_ROOT)/ace/Time_Value.inl \
 $(ACE_ROOT)/ace/Default_Constants.h \
 $(ACE_ROOT)/ace/Min_Max.h \
 $(ACE_ROOT)/ace/streams.h \
 $(ACE_ROOT)/ace/Trace.h \
 $(ACE_ROOT)/ace/OS.i \
 $(ACE_ROOT)/ace/Array_Base.inl \
 $(ACE_ROOT)/ace/Array_Base.cpp \
 $(ACE_ROOT)/ace/Malloc_Base.h \
 $(ACE_ROOT)/ace/Unbounded_Set.h \
 $(ACE_ROOT)/ace/Unbounded_Set.inl \
 $(ACE_ROOT)/ace/Unbounded_Set.cpp \
 $(ACE_ROOT)/ace/Log_Msg.h \
 $(ACE_ROOT)/ace/Log_Priority.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.inl \
 $(ACE_ROOT)/ace/Unbounded_Queue.h \
 $(ACE_ROOT)/ace/Unbounded_Queue.inl \
 $(ACE_ROOT)/ace/Unbounded_Queue.cpp \
 $(ACE_ROOT)/ace/Containers_T.i \
 $(ACE_ROOT)/ace/Containers_T.cpp

.obj/test_sstring.o .obj/test_sstring.so .shobj/test_sstring.o .shobj/test_sstring.so: test_sstring.cpp \
 $(ACE_ROOT)/ace/SString.h \
 $(ACE_ROOT)/ace/pre.h \
 $(ACE_ROOT)/ace/String_Base.h \
 $(ACE_ROOT)/ace/ACE.h \
 $(ACE_ROOT)/ace/OS.h \
 $(ACE_ROOT)/ace/post.h \
 $(ACE_ROOT)/ace/ace_wchar.h \
 $(ACE_ROOT)/ace/ace_wchar.inl \
 $(ACE_ROOT)/ace/OS_Dirent.h \
 $(ACE_ROOT)/ace/OS_Export.h \
 $(ACE_ROOT)/ace/OS_Errno.h \
 $(ACE_ROOT)/ace/OS_Errno.inl \
 $(ACE_ROOT)/ace/OS_Dirent.inl \
 $(ACE_ROOT)/ace/OS_String.h \
 $(ACE_ROOT)/ace/Basic_Types.h \
 $(ACE_ROOT)/ace/ACE_export.h \
 $(ACE_ROOT)/ace/Basic_Types.i \
 $(ACE_ROOT)/ace/OS_String.inl \
 $(ACE_ROOT)/ace/OS_Memory.h \
 $(ACE_ROOT)/ace/OS_Memory.inl \
 $(ACE_ROOT)/ace/OS_TLI.h \
 $(ACE_ROOT)/ace/OS_TLI.inl \
 $(ACE_ROOT)/ace/Time_Value.h \
 $(ACE_ROOT)/ace/Time_Value.inl \
 $(ACE_ROOT)/ace/Default_Constants.h \
 $(ACE_ROOT)/ace/Global_Macros.h \
 $(ACE_ROOT)/ace/Min_Max.h \
 $(ACE_ROOT)/ace/streams.h \
 $(ACE_ROOT)/ace/Trace.h \
 $(ACE_ROOT)/ace/OS.i \
 $(ACE_ROOT)/ace/Flag_Manip.h \
 $(ACE_ROOT)/ace/Flag_Manip.i \
 $(ACE_ROOT)/ace/Handle_Ops.h \
 $(ACE_ROOT)/ace/Handle_Ops.i \
 $(ACE_ROOT)/ace/Lib_Find.h \
 $(ACE_ROOT)/ace/Lib_Find.i \
 $(ACE_ROOT)/ace/Init_ACE.h \
 $(ACE_ROOT)/ace/Init_ACE.i \
 $(ACE_ROOT)/ace/Sock_Connect.h \
 $(ACE_ROOT)/ace/Sock_Connect.i \
 $(ACE_ROOT)/ace/ACE.i \
 $(ACE_ROOT)/ace/String_Base_Const.h \
 $(ACE_ROOT)/ace/String_Base.i \
 $(ACE_ROOT)/ace/Malloc_Base.h \
 $(ACE_ROOT)/ace/String_Base.cpp \
 $(ACE_ROOT)/ace/Malloc.h \
 $(ACE_ROOT)/ace/Log_Msg.h \
 $(ACE_ROOT)/ace/Log_Priority.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.inl \
 $(ACE_ROOT)/ace/Malloc.i \
 $(ACE_ROOT)/ace/Malloc_T.h \
 $(ACE_ROOT)/ace/Synch.h \
 $(ACE_ROOT)/ace/Synch.i \
 $(ACE_ROOT)/ace/Synch_T.h \
 $(ACE_ROOT)/ace/Synch_T.i \
 $(ACE_ROOT)/ace/Thread.h \
 $(ACE_ROOT)/ace/Thread_Adapter.h \
 $(ACE_ROOT)/ace/Base_Thread_Adapter.h \
 $(ACE_ROOT)/ace/Base_Thread_Adapter.inl \
 $(ACE_ROOT)/ace/Thread_Adapter.inl \
 $(ACE_ROOT)/ace/Thread.i \
 $(ACE_ROOT)/ace/Synch_T.cpp \
 $(ACE_ROOT)/ace/Malloc_Allocator.h \
 $(ACE_ROOT)/ace/Malloc_Allocator.i \
 $(ACE_ROOT)/ace/Free_List.h \
 $(ACE_ROOT)/ace/Free_List.i \
 $(ACE_ROOT)/ace/Free_List.cpp \
 $(ACE_ROOT)/ace/Malloc_T.i \
 $(ACE_ROOT)/ace/Malloc_T.cpp \
 $(ACE_ROOT)/ace/Memory_Pool.h \
 $(ACE_ROOT)/ace/Event_Handler.h \
 $(ACE_ROOT)/ace/Event_Handler.i \
 $(ACE_ROOT)/ace/Signal.h \
 $(ACE_ROOT)/ace/Signal.i \
 $(ACE_ROOT)/ace/Mem_Map.h \
 $(ACE_ROOT)/ace/Mem_Map.i \
 $(ACE_ROOT)/ace/SV_Semaphore_Complex.h \
 $(ACE_ROOT)/ace/SV_Semaphore_Simple.h \
 $(ACE_ROOT)/ace/SV_Semaphore_Simple.i \
 $(ACE_ROOT)/ace/SV_Semaphore_Complex.i \
 $(ACE_ROOT)/ace/Unbounded_Set.h \
 $(ACE_ROOT)/ace/Node.h \
 $(ACE_ROOT)/ace/Node.cpp \
 $(ACE_ROOT)/ace/Unbounded_Set.inl \
 $(ACE_ROOT)/ace/Unbounded_Set.cpp \
 $(ACE_ROOT)/ace/Memory_Pool.i \
 $(ACE_ROOT)/ace/Auto_Ptr.h \
 $(ACE_ROOT)/ace/Auto_Ptr.i \
 $(ACE_ROOT)/ace/Auto_Ptr.cpp \
 $(ACE_ROOT)/ace/SString.i

.obj/test_trace.o .obj/test_trace.so .shobj/test_trace.o .shobj/test_trace.so: test_trace.cpp \
 $(ACE_ROOT)/ace/Signal.h \
 $(ACE_ROOT)/ace/pre.h \
 $(ACE_ROOT)/ace/Synch.h \
 $(ACE_ROOT)/ace/ACE_export.h \
 $(ACE_ROOT)/ace/post.h \
 $(ACE_ROOT)/ace/ace_wchar.h \
 $(ACE_ROOT)/ace/ace_wchar.inl \
 $(ACE_ROOT)/ace/OS.h \
 $(ACE_ROOT)/ace/OS_Dirent.h \
 $(ACE_ROOT)/ace/OS_Export.h \
 $(ACE_ROOT)/ace/OS_Errno.h \
 $(ACE_ROOT)/ace/OS_Errno.inl \
 $(ACE_ROOT)/ace/OS_Dirent.inl \
 $(ACE_ROOT)/ace/OS_String.h \
 $(ACE_ROOT)/ace/Basic_Types.h \
 $(ACE_ROOT)/ace/Basic_Types.i \
 $(ACE_ROOT)/ace/OS_String.inl \
 $(ACE_ROOT)/ace/OS_Memory.h \
 $(ACE_ROOT)/ace/OS_Memory.inl \
 $(ACE_ROOT)/ace/OS_TLI.h \
 $(ACE_ROOT)/ace/OS_TLI.inl \
 $(ACE_ROOT)/ace/Time_Value.h \
 $(ACE_ROOT)/ace/Time_Value.inl \
 $(ACE_ROOT)/ace/Default_Constants.h \
 $(ACE_ROOT)/ace/Global_Macros.h \
 $(ACE_ROOT)/ace/Min_Max.h \
 $(ACE_ROOT)/ace/streams.h \
 $(ACE_ROOT)/ace/Trace.h \
 $(ACE_ROOT)/ace/OS.i \
 $(ACE_ROOT)/ace/Synch.i \
 $(ACE_ROOT)/ace/Synch_T.h \
 $(ACE_ROOT)/ace/Synch_T.i \
 $(ACE_ROOT)/ace/Thread.h \
 $(ACE_ROOT)/ace/Thread_Adapter.h \
 $(ACE_ROOT)/ace/Base_Thread_Adapter.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.h \
 $(ACE_ROOT)/ace/OS_Log_Msg_Attributes.inl \
 $(ACE_ROOT)/ace/Base_Thread_Adapter.inl \
 $(ACE_ROOT)/ace/Thread_Adapter.inl \
 $(ACE_ROOT)/ace/Thread.i \
 $(ACE_ROOT)/ace/Synch_T.cpp \
 $(ACE_ROOT)/ace/Log_Msg.h \
 $(ACE_ROOT)/ace/Log_Priority.h \
 $(ACE_ROOT)/ace/Event_Handler.h \
 $(ACE_ROOT)/ace/Event_Handler.i \
 $(ACE_ROOT)/ace/Signal.i \
 $(ACE_ROOT)/ace/Task.h \
 $(ACE_ROOT)/ace/Service_Object.h \
 $(ACE_ROOT)/ace/Shared_Object.h \
 $(ACE_ROOT)/ace/Shared_Object.i \
 $(ACE_ROOT)/ace/Svc_Conf_Tokens.h \
 $(ACE_ROOT)/ace/DLL.h \
 $(ACE_ROOT)/ace/Service_Object.i \
 $(ACE_ROOT)/ace/Thread_Manager.h \
 $(ACE_ROOT)/ace/Thread_Exit.h \
 $(ACE_ROOT)/ace/Thread_Control.h \
 $(ACE_ROOT)/ace/Thread_Control.inl \
 $(ACE_ROOT)/ace/Unbounded_Queue.h \
 $(ACE_ROOT)/ace/Node.h \
 $(ACE_ROOT)/ace/Node.cpp \
 $(ACE_ROOT)/ace/Unbounded_Queue.inl \
 $(ACE_ROOT)/ace/Unbounded_Queue.cpp \
 $(ACE_ROOT)/ace/Malloc_Base.h \
 $(ACE_ROOT)/ace/Containers.h \
 $(ACE_ROOT)/ace/Containers.i \
 $(ACE_ROOT)/ace/Containers_T.h \
 $(ACE_ROOT)/ace/Array_Base.h \
 $(ACE_ROOT)/ace/Array_Base.inl \
 $(ACE_ROOT)/ace/Array_Base.cpp \
 $(ACE_ROOT)/ace/Unbounded_Set.h \
 $(ACE_ROOT)/ace/Unbounded_Set.inl \
 $(ACE_ROOT)/ace/Unbounded_Set.cpp \
 $(ACE_ROOT)/ace/Containers_T.i \
 $(ACE_ROOT)/ace/Containers_T.cpp \
 $(ACE_ROOT)/ace/Free_List.h \
 $(ACE_ROOT)/ace/Free_List.i \
 $(ACE_ROOT)/ace/Free_List.cpp \
 $(ACE_ROOT)/ace/Singleton.h \
 $(ACE_ROOT)/ace/Singleton.i \
 $(ACE_ROOT)/ace/Singleton.cpp \
 $(ACE_ROOT)/ace/Object_Manager.h \
 $(ACE_ROOT)/ace/Object_Manager.i \
 $(ACE_ROOT)/ace/Managed_Object.h \
 $(ACE_ROOT)/ace/Managed_Object.i \
 $(ACE_ROOT)/ace/Managed_Object.cpp \
 $(ACE_ROOT)/ace/Framework_Component.h \
 $(ACE_ROOT)/ace/Framework_Component.inl \
 $(ACE_ROOT)/ace/ACE.h \
 $(ACE_ROOT)/ace/Flag_Manip.h \
 $(ACE_ROOT)/ace/Flag_Manip.i \
 $(ACE_ROOT)/ace/Handle_Ops.h \
 $(ACE_ROOT)/ace/Handle_Ops.i \
 $(ACE_ROOT)/ace/Lib_Find.h \
 $(ACE_ROOT)/ace/Lib_Find.i \
 $(ACE_ROOT)/ace/Init_ACE.h \
 $(ACE_ROOT)/ace/Init_ACE.i \
 $(ACE_ROOT)/ace/Sock_Connect.h \
 $(ACE_ROOT)/ace/Sock_Connect.i \
 $(ACE_ROOT)/ace/ACE.i \
 $(ACE_ROOT)/ace/Framework_Component_T.h \
 $(ACE_ROOT)/ace/Framework_Component_T.inl \
 $(ACE_ROOT)/ace/Framework_Component_T.cpp \
 $(ACE_ROOT)/ace/Thread_Manager.i \
 $(ACE_ROOT)/ace/Task.i \
 $(ACE_ROOT)/ace/Task_T.h \
 $(ACE_ROOT)/ace/Message_Queue.h \
 $(ACE_ROOT)/ace/Message_Block.h \
 $(ACE_ROOT)/ace/Message_Block.i \
 $(ACE_ROOT)/ace/Message_Block_T.h \
 $(ACE_ROOT)/ace/Message_Block_T.i \
 $(ACE_ROOT)/ace/Message_Block_T.cpp \
 $(ACE_ROOT)/ace/IO_Cntl_Msg.h \
 $(ACE_ROOT)/ace/Message_Queue_T.h \
 $(ACE_ROOT)/ace/Message_Queue_T.i \
 $(ACE_ROOT)/ace/Message_Queue_T.cpp \
 $(ACE_ROOT)/ace/Notification_Strategy.h \
 $(ACE_ROOT)/ace/Notification_Strategy.inl \
 $(ACE_ROOT)/ace/Message_Queue.i \
 $(ACE_ROOT)/ace/Task_T.i \
 $(ACE_ROOT)/ace/Task_T.cpp \
 $(ACE_ROOT)/ace/Module.h \
 $(ACE_ROOT)/ace/Module.i \
 $(ACE_ROOT)/ace/Module.cpp \
 $(ACE_ROOT)/ace/Stream_Modules.h \
 $(ACE_ROOT)/ace/Stream_Modules.cpp

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
