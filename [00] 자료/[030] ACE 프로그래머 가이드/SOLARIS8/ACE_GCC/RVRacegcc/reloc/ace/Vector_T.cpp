// Vector_T.cpp,v 1.3 2003/09/04 16:56:31 shuston Exp
// Vector_T.cpp,v 4.5 2002/10/20 03:02:07 kitty Exp

#ifndef ACE_VECTOR_T_C
#define ACE_VECTOR_T_C

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Vector_T.h"

#if !defined (__ACE_INLINE__)
#include "ace/Vector_T.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, Vector_T, "Vector_T.cpp,v 1.3 2003/09/04 16:56:31 shuston Exp")

ACE_ALLOC_HOOK_DEFINE(ACE_Vector)

template <class T, size_t DEFAULT_SIZE>
void ACE_Vector<T, DEFAULT_SIZE>::resize (const size_t new_size,
					  const T& t)
{
  ACE_Array<T>::size (new_size);
  if (new_size > length_)
    for (size_t i = length_; i < new_size; ++i)
      (*this)[i]=t;

  curr_max_size_ = this->max_size ();
  length_ = new_size;
}

template <class T, size_t DEFAULT_SIZE>
void ACE_Vector<T, DEFAULT_SIZE>::push_back (const T& elem)
{
  if (length_ == curr_max_size_)
    {
      ACE_Array<T>::size (curr_max_size_ * 2);
      curr_max_size_ = this->max_size ();
    }
  ++length_;
  (*this)[length_-1] = elem;
}

template <class T, size_t DEFAULT_SIZE>
void ACE_Vector<T, DEFAULT_SIZE>::dump (void) const
{
#if 0
  // Can't do this unless the vector is an object with a dump
  // function.
  for (size_t i = 0; i < this->size (); ++i)
    (*this)[i].dump ();
#endif /* 0 */
}

#if 0
template<class T>
int compare(const ACE_Vector<T>& v1,
	     const ACE_Vector<T>& v2,
             const size_t from_ndx,
	     const size_t to_ndx)
{
  size_t last1 = v1.size () - 1;
  size_t last2 = v2.size () - 1;
  if (last1 < from_ndx || last1 < to_ndx)
    {
      return false;
    }
  if (last2 < from_ndx || last2 < to_ndx)
    {
      return false;
    }
  if (last1 != last2)
    {
      return false;
    }

  //  cout<<"compare() <================="<<endl;
  for (size_t i = from_ndx; i <= to_ndx; ++i)
    {
      //     cout<<"V1["<<i<<"]="<<v1[i];
      //     cout<<", V2["<<i<<"]="<<v2[i];
      //     cout<<": NOT EQUAL == "<<(v1[i]!=v2[i])<<endl;
      if (v1[i] != v2[i])
	{
	  return false;
	}
    }
  //  cout<<"compare() ====================>"<<endl;
  return true;
}

template<class T>
int partial_compare(const ACE_Vector<T>& v1,
		     const ACE_Vector<T>& v2,
                     const size_t from_ndx,
		     const size_t to_ndx)
{
  size_t last1 = v1.size () - 1;
  size_t last2 = v2.size () - 1;
  if (last1 < from_ndx || last1 < to_ndx)
    {
      return false;
    }
  if (last2 < from_ndx || last2 < to_ndx)
    {
      return false;
    }
  //  cout<<"partial_compare() <================="<<endl;
  for (size_t i = from_ndx; i <= to_ndx; ++i)
    {
      //     cout<<"V1["<<i<<"]="<<v1[i];
      //     cout<<", V2["<<i<<"]="<<v2[i];
      //     cout<<": NOT EQUAL == "<<(v1[i]!=v2[i])<<endl;
      if (v1[i] != v2[i])
	{
	  return false;
	}
    }
  //  cout<<"partial_compare() ====================>"<<endl;
  return true;
}
#endif

// ****************************************************************

template <class T> int
ACE_Vector_Iterator<T>::next (T *&item)
{
  // ACE_TRACE ("ACE_Vector_Iterator<T>::next");

  if (this->done ())
    {
      item = 0;
      return 0;
    }
  else
    {
      item = &vector_[current_];
      return 1;
    }
}

#endif /* ACE_VECTOR_T_C */
