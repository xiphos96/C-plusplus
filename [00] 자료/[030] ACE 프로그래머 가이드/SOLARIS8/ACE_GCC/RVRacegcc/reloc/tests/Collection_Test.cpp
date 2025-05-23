// Collection_Test.cpp,v 4.17 2002/03/06 21:48:03 nanbor Exp

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Collection_Test.cpp
//
// = DESCRIPTION
//     This is a simple test of the ACE collection classes and its
//     iterators.
//
// = AUTHOR
//    Irfan Pyarali <irfan@cs.wustl.edu>
//
// ============================================================================

#include "test_config.h"

ACE_RCSID(tests, Collection_Test, "Collection_Test.cpp,v 4.17 2002/03/06 21:48:03 nanbor Exp")

#include "ace/Containers.h"
#include "Collection_Test.h"

UglyThing::UglyThing (void* alloc, deletion_func dfunc)
  : alloc_ (alloc)
  , dfunc_ (dfunc)
{
}

int
UglyThing::operator== (const UglyThing& r) const
{
  return this->alloc_ == r.alloc_;
}

typedef UglyThing DATA;
typedef ACE_Unbounded_Set<DATA> UNBOUNDED_SET;
typedef ACE_Unbounded_Set_Iterator<DATA> UNBOUNDED_SET_ITERATOR;
typedef ACE_Unbounded_Set_Const_Iterator<DATA> UNBOUNDED_SET_CONST_ITERATOR;

typedef int ARRAY_DATA;
typedef ACE_Array<ARRAY_DATA> ARRAY;
typedef ACE_Array_Iterator<ARRAY_DATA> ARRAY_ITERATOR;

void iterate_const(const UNBOUNDED_SET& set)
{
  {
    UNBOUNDED_SET_CONST_ITERATOR iterator (set);
    while (!iterator.done ())
    {
      DATA *data = 0;
      iterator.next (data);

      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%x,%x\n"),
                  data->alloc_, data->dfunc_));

      DATA data_second = *iterator;
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%x,%x\n"),
                  data_second.alloc_, data_second.dfunc_));

      iterator.advance ();
    }
  }
}

int dummyfunc() { return 0; }

int ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE_START_TEST (ACE_TEXT ("Collection_Test"));

  deletion_func NO_DFUNC = (deletion_func)0;
  {
    UNBOUNDED_SET unbounded_set;

    unbounded_set.insert (UglyThing ((void*)&unbounded_set, NO_DFUNC));
    unbounded_set.insert (UglyThing ((void*)&dummyfunc, NO_DFUNC));

    {
      for (UNBOUNDED_SET::iterator iterator = unbounded_set.begin ();
           iterator != unbounded_set.end ();
           ++iterator)
        {
          ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%x,%x\n"),
                      (*iterator).alloc_, (*iterator).dfunc_));
        }
    }

    unbounded_set.insert (UglyThing (0, NO_DFUNC));
    unbounded_set.remove (UglyThing ((void*)&dummyfunc, NO_DFUNC));

    {
      UNBOUNDED_SET_ITERATOR iterator (unbounded_set);
      while (!iterator.done ())
        {
          DATA *data = 0;
          iterator.next (data);
          ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%x,%x\n"),
                      data->alloc_, data->dfunc_));
          iterator.advance ();
        }
    }
    iterate_const (unbounded_set);

    unbounded_set.reset ();
    
    {
      DATA *data;
      UNBOUNDED_SET_ITERATOR i (unbounded_set);

      while (i.next (data) != 0)
        {
          ACE_DEBUG ((LM_DEBUG, "%x,%x\n", data->alloc_, data->dfunc_));
          i.advance ();
        }
    }
    iterate_const (unbounded_set);
  }

  {
    ARRAY array;
  }

  {
    ARRAY array (0);
  }

  {
    ARRAY array1;
    array1.size (2);
    array1[0] = 4;
    array1[1] = 4;

    ARRAY array2 (2, 4);

    ARRAY array3 (array2);

    ARRAY array4;
    array4 = array2;

    ACE_ASSERT (array1 == array2);
    ACE_ASSERT (array1 == array3);
    ACE_ASSERT (array1 == array4);

    {
      for (size_t i = 0;
           i != array1.size ();
           ++i)
        {
          ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%d\n"),
                      array1[i]));
          ACE_ASSERT (array1[i] == 4);
        }
    }

    {
      ARRAY_ITERATOR iterator (array1);
      while (!iterator.done ())
        {
          ARRAY_DATA *data = 0;
          iterator.next (data);
          ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%d\n"),
                      (*data)));
          ACE_ASSERT (*data == 4);
          iterator.advance ();
        }
    }
  }


  ACE_END_TEST;

  return 0;
}


#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Unbounded_Set<DATA>;
template class ACE_Unbounded_Set_Iterator<DATA>;
template class ACE_Unbounded_Set_Const_Iterator<DATA>;

template class ACE_Node<DATA>;
#if (ACE_SIZEOF_INT != 4)
// These might be already instantiated in ace/stats.cpp
// (if ACE_INT32 == int)
ptemplate class ACE_Node<DATA>;
#endif /* ACE_SIZEOF_INT != 4 */

template class ACE_Array<ARRAY_DATA>;
template class ACE_Array_Base<ARRAY_DATA>;
template class ACE_Array_Iterator<ARRAY_DATA>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Unbounded_Set<DATA>
#pragma instantiate ACE_Unbounded_Set_Iterator<DATA>
#pragma instantiate ACE_Unbounded_Set_Const_Iterator<DATA>
#pragma instantiate ACE_Node<DATA>
#pragma instantiate ACE_Array<ARRAY_DATA>
#pragma instantiate ACE_Array_Base<ARRAY_DATA>
#pragma instantiate ACE_Array_Iterator<ARRAY_DATA>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
