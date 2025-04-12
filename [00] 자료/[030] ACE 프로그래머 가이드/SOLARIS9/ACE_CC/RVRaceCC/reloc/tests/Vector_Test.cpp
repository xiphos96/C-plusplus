// Vector_Test.cpp,v 1.3 2003/09/04 16:57:03 shuston Exp
// Vector_Test.cpp,v 4.7 2002/03/06 21:48:04 nanbor Exp

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Vector_Test.cpp
//
// = DESCRIPTION
//     This is a simple test of the ACE_Vector class and its iterators.
//
// = AUTHOR
//    Gonzalo A. Diethelm <gonzalo.diethelm@aditiva.com>
//
// ============================================================================

#include "test_config.h"

ACE_RCSID(tests, Vector_Test, "Vector_Test.cpp,v 1.3 2003/09/04 16:57:03 shuston Exp")

#include "ace/Vector_T.h"

typedef size_t DATA;
typedef ACE_Vector<DATA> VECTOR;
typedef ACE_Vector<DATA>::Iterator ITERATOR;

const size_t TOP = 100;
const size_t LEFT = 10;
const size_t RESIZE = 20;

int ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE_START_TEST (ACE_TEXT ("Vector_Test"));

  VECTOR vector;
  size_t i;

  for (i = 0; i < TOP; ++i)
    vector.push_back (i);

  ACE_ASSERT (vector.size () == TOP);
  ACE_DEBUG ((LM_DEBUG,
	      ACE_TEXT ("Size: %d\n"),
	      vector.size ()));

  for (i = 0; i < TOP; ++i)
    ACE_ASSERT (vector[i] == i);

  // Test to be sure the iterator gets the correct count and entries.
  ITERATOR iter (vector);
  DATA *p_item = 0 ;
  size_t iter_count = 0;
  while (!iter.done ())
    {
      if (iter.next (p_item) == 0)
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Fail to get value on iter pass %d\n"),
                    iter_count));
      if (*p_item != iter_count)
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Iter pass %d got %d\n"),
                    iter_count, *p_item));
      iter_count++;
      iter.advance();
    }
  if (iter_count != TOP)
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("Iterated %d elements; expected %d\n"),
                iter_count, TOP));

  for (i = 0; i < (TOP - LEFT); ++i)
    vector.pop_back ();

  ACE_ASSERT (vector.size () == LEFT);
  ACE_DEBUG ((LM_DEBUG,
	      ACE_TEXT ("Size: %d\n"),
	      vector.size ()));

  for (i = 0; i < LEFT; ++i)
    {
      ACE_ASSERT (vector[i] == i);
      ACE_DEBUG ((LM_DEBUG,
            ACE_TEXT ("vector[%d]:%d\n"),
            i, vector[i]));
    }

  vector.resize(RESIZE, 0);
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("After resize\n")));

  for (i = 0; i < RESIZE ; ++i)
    {
      // The original vector of size LEFT must have the same original contents
      // the new elements should have the value 0 (this value is passed as
      // second argument of the resize() call.
      if (i < LEFT)
        {
          ACE_ASSERT (vector[i] == i);
        }
      else
        {
          ACE_ASSERT (vector[i] == 0);
        }
      ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("vector[%d]:%d\n"),
              i, vector[i]));
    }

  vector.clear ();
  ACE_ASSERT (vector.size () == 0);
  ACE_DEBUG ((LM_DEBUG,
	      ACE_TEXT ("Size: %d\n"),
	      vector.size ()));

  ACE_END_TEST;

  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Vector<DATA>;
template class ACE_Array<DATA>;
template class ACE_Array_Base<DATA>;
template class ACE_Array_Iterator<DATA>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Vector<DATA>
#pragma instantiate ACE_Array<DATA>
#pragma instantiate ACE_Array_Base<DATA>
#pragma instantiate ACE_Array_Iterator<DATA>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
