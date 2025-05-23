// Benchmark_Base.cpp,v 1.3 2001/12/24 21:35:27 schmidt Exp

#define  SYNCHLIB_BUILD_DLL
#include "Benchmark_Base.h"

ACE_RCSID(Synch_Benchmarks, Benchmark_Base, "Benchmark_Base.cpp,v 1.3 2001/12/24 21:35:27 schmidt Exp")

#if defined (ACE_HAS_THREADS)

// Initialize the static variables.
/* static */

Benchmark_Base::Benchmark_Base (int type)
  : benchmark_type_ (type)
{
}

int
Benchmark_Base::benchmark_type (void)
{
  return this->benchmark_type_;
}

int
Benchmark_Base::thr_id (void)
{
#if defined (ACE_HAS_PTHREADS) || defined (ACE_HAS_DCETHREADS) || defined (VXWORKS)
  // This invokes the thread-specific storage smart pointer.
  return this->id_->thr_id ();
#else
  return ACE_Thread::self ();
#endif /* ACE_HAS_PTHREADS || ACE_HAS_DCETHREADS || VXWORKS */
}

Benchmark_Method_Base::Benchmark_Method_Base (void)
  : Benchmark_Base (Benchmark_Base::METHOD)
{
}

int
Benchmark_Method_Base::exec (ACE_Service_Repository_Iterator *sri)
{
  sri->advance ();
  for (const ACE_Service_Type *sr;
       sri->next (sr) != 0;
       sri->advance ())
    {
      // This would greatly benefit from RTTI typesafe downcasting...
      const ACE_Service_Type_Impl *type = sr->type ();
      const void *obj = type->object ();
      ACE_Service_Object *so = (ACE_Service_Object *) obj;
      Benchmark_Base *bp = (Benchmark_Base *) so;

      if (this->valid_test_object (bp))
        {

          ACE_DEBUG ((LM_DEBUG, "\nstarting up %s\n", sr->name ()));

          int notused = this->pre_run_test (bp) == 0 && this->run_test () == 0 &&
            this->post_run_test () == 0;
          notused = notused;
        }
      else
        return 0;
    }
  return 0;
}

#if defined (ACE_HAS_PTHREADS) || defined (ACE_HAS_DCETHREADS) || defined (VXWORKS)
/* static */
MT_INT Thr_ID::thread_id_ (0);

Thr_ID::Thr_ID (void)
  : thr_id_ (++Thr_ID::thread_id_)
{
}

int
Thr_ID::thr_id (void)
{
  return this->thr_id_;
}

void
Thr_ID::thr_id (int i)
{
  this->thr_id_ = i;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_TSS<Thr_ID>;
template class ACE_Atomic_Op<ACE_Thread_Mutex, int>;
template class ACE_Atomic_Op_Ex<ACE_Thread_Mutex, int>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_TSS<Thr_ID>
#pragma instantiate ACE_Atomic_Op<ACE_Thread_Mutex, int>
#pragma instantiate ACE_Atomic_Op_Ex<ACE_Thread_Mutex, int>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /* ACE_HAS_PTHREADS || ACE_HAS_DCETHREADS || VXWORKS */
#endif /* ACE_HAS_THREADS */
