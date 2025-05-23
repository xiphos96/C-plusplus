/* -*- C++ -*- */
// SV_Semaphore_Simple.i,v 1.3 2003/03/31 23:23:50 shuston Exp
// SV_Semaphore_Simple.i,v 4.6 1998/04/30 23:25:52 nanbor Exp

#include "ace/Trace.h"


#if defined (ACE_HAS_WCHAR)
// Semaphores don't offer wide-char names, so convert the name and forward
// to the narrow-char open().
ASYS_INLINE int
ACE_SV_Semaphore_Simple::open (const wchar_t *name,
                               int flags,
                               int initial_value,
                               u_short nsems,
                               int perms)
{
  ACE_TRACE ("ACE_SV_Semaphore_Simple::open (wchar_t)");
  return this->open (ACE_Wide_To_Ascii (name).char_rep (),
                     flags,
                     initial_value,
                     nsems,
                     perms);
}
#endif /* ACE_HAS_WCHAR */

ASYS_INLINE int
ACE_SV_Semaphore_Simple::control (int cmd, 
				  semun arg, 
				  u_short n) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Simple::control");
  return this->internal_id_ == -1 ? 
    -1 : ACE_OS::semctl (this->internal_id_, n, cmd, arg);
}

// Close a ACE_SV_Semaphore, marking it as invalid for subsequent
// operations...

ASYS_INLINE int 
ACE_SV_Semaphore_Simple::close (void)
{
  ACE_TRACE ("ACE_SV_Semaphore_Simple::close");
  return this->init ();
}

// General ACE_SV_Semaphore operation on an array of SV_Semaphores. 
     
ASYS_INLINE int 
ACE_SV_Semaphore_Simple::op (sembuf op_vec[], u_short n) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Simple::op");
  return this->internal_id_ == -1 
    ? -1 : ACE_OS::semop (this->internal_id_, op_vec, n);
}

// Wait until a ACE_SV_Semaphore's value is greater than 0, the
// decrement it by 1 and return. Dijkstra's P operation, Tannenbaums
// DOWN operation.

ASYS_INLINE int 
ACE_SV_Semaphore_Simple::acquire (u_short n, int flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Simple::acquire");
  return this->op (-1, n, flags);
}

ASYS_INLINE int 
ACE_SV_Semaphore_Simple::acquire_read (u_short n, int flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Simple::acquire_read");
  return this->acquire (n, flags);
}

ASYS_INLINE int 
ACE_SV_Semaphore_Simple::acquire_write (u_short n, int flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Simple::acquire_write");
  return this->acquire (n, flags);
}

// Non-blocking version of acquire(). 

ASYS_INLINE int 
ACE_SV_Semaphore_Simple::tryacquire (u_short n, int flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Simple::tryacquire");
  return this->op (-1, n, flags | IPC_NOWAIT);
}

// Non-blocking version of acquire(). 

ASYS_INLINE int 
ACE_SV_Semaphore_Simple::tryacquire_read (u_short n, int flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Simple::tryacquire_read");
  return this->tryacquire (n, flags);
}

// Non-blocking version of acquire(). 

ASYS_INLINE int 
ACE_SV_Semaphore_Simple::tryacquire_write (u_short n, int flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Simple::tryacquire_write");
  return this->tryacquire (n, flags);
}

// Increment ACE_SV_Semaphore by one. Dijkstra's V operation,
// Tannenbaums UP operation.

ASYS_INLINE int 
ACE_SV_Semaphore_Simple::release (u_short n, int flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Simple::release");
  return this->op (1, n, flags);
}

ASYS_INLINE int
ACE_SV_Semaphore_Simple::get_id (void) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Simple::get_id");
  return this->internal_id_;
}

