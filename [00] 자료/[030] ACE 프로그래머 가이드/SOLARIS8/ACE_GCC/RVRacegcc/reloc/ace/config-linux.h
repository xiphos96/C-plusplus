// -*- C++ -*-
//
// config-linux.h,v 4.35 2002/10/02 17:51:41 ossama Exp

// The following configuration file is designed to work for Linux
// platforms using GNU C++.

#ifndef ACE_CONFIG_LINUX_H
#define ACE_CONFIG_LINUX_H
#include "ace/pre.h"

#include "ace/config-linux-common.h"

#define ACE_HAS_SVR4_DYNAMIC_LINKING
#define ACE_HAS_AUTOMATIC_INIT_FINI

#if !defined (ACE_MT_SAFE)
#define ACE_MT_SAFE 1                           // JCEJ 12/22/96        #1
#endif

#if ACE_MT_SAFE
// Yes, we do have threads.
#define ACE_HAS_THREADS
// And they're even POSIX pthreads (LinuxThreads implementation)
#define ACE_HAS_PTHREADS

#if !defined (ACE_HAS_PTHREADS_UNIX98_EXT)
#  define ACE_LACKS_RWLOCK_T 
#endif  /* !ACE_HAS_PTHREADS_UNIX98_EXT */

// ... and the final standard even!
#define ACE_HAS_PTHREADS_STD
#define ACE_HAS_THREAD_SPECIFIC_STORAGE     // jcej 12/22/96         #2

#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS    // JCEJ 1/7-8/96

#if defined(__GLIBC__)
// Platform supports reentrant functions (i.e., all the POSIX *_r
// functions).
#define ACE_HAS_REENTRANT_FUNCTIONS

#if (__GLIBC__ < 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ < 1)
   // Older versions of glibc lacked reentrant netdb functions
#  define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS

   // glibc < 2.1 lacks pthread_attr_setstacksize()
#  define ACE_LACKS_THREAD_STACK_SIZE
#endif /* (__GLIBC__ < 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ < 1) */

// uses ctime_r & asctime_r with only two parameters vs. three
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R
#endif

#include /**/ <pthread.h>

#if (__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 2)
   // glibc 2.2.x or better has pthread_mutex_timedlock()
#  define ACE_HAS_MUTEX_TIMEOUTS
#  if !defined (_XOPEN_SOURCE) \
   || (defined (_XOPEN_SOURCE) && (_XOPEN_SOURCE - 0) < 600)
// pthread_mutex_timedlock() prototype is not visible if _XOPEN_SOURCE
// is not >= 600 (i.e. for XPG6).
extern "C" int pthread_mutex_timedlock (pthread_mutex_t *mutex,
                                        const struct timespec * abstime);
#  endif  /* _XOPEN_SOURCE && _XOPEN_SOURCE < 600 */
#endif  /* (__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 2) */

#endif  /* ACE_MT_SAFE */


#include "ace/post.h"

#endif /* ACE_CONFIG_LINUX_H */
