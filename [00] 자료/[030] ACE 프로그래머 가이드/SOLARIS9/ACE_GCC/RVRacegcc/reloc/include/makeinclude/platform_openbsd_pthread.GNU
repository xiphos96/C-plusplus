# platform_openbsd_pthread.GNU,v 1.1 2002/10/15 01:22:54 fhunleth Exp

# platform_openbsd_pthread.GNU

include $(ACE_ROOT)/include/makeinclude/platform_openbsd.GNU

LDFLAGS		+= -pthread
CFLAGS          += -D_THREAD_SAFE
