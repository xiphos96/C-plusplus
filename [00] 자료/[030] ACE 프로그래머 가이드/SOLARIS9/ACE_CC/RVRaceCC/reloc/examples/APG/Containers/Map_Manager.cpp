#include "ace/Map_Manager.h"
#include "ace/Synch.h" // Needed for the lock.
#include "DataElement.h"

// Listing 1 code/ch05
// Forward declaration.
class KeyType;
bool operator == (const KeyType&, const KeyType&);

class KeyType
{
public:
  friend bool operator == (const KeyType&, const KeyType&);

  KeyType () {}
  KeyType (int i) : val_(i) {}
  KeyType (const KeyType& kt) { this->val_ = kt.val_; };
  operator int() { return val_; };

private:
  int val_;
};

bool operator == (const KeyType& a, const KeyType& b)
{
  return (a.val_ == b.val_);
}
// Listing 1

class Map_Example
{
public:
  // Illustrate the ACE_Map_Manager.
  int run (void);

private:
  // Iterate in the forward direction.
  void iterate_forward (void);

  // Iterate in the other direction.
  void iterate_reverse (void);

  // Remove all elements from the map.
  void remove_all (void);

private:
  ACE_Map_Manager<KeyType,DataElement,ACE_Null_Mutex> map_;
};

// Listing 2 code/ch05
int Map_Example::run (void)
{
  ACE_TRACE (ACE_TEXT ("Map_Example::run"));

  // Corresponding KeyType objects are created on the fly.
  for (int i = 0; i < 100; i++)
    {
      map_.bind (i, DataElement (i));
    }

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Map has \n")));
  for (int j = 0; j < 100; j++)
    {
      DataElement d;
      map_.find (j,d);
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%d:"), d.getData ()));
    }
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));

  // Iterate in the forward direction.
  this->iterate_forward ();

  // Iterate in the other direction.
  this->iterate_reverse ();

  // Remove all elements from the map.
  this->remove_all ();

  // Iterate in the forward direction.
  this->iterate_forward ();

  return 0;
}
// Listing 2
// Listing 3 code/ch05
void Map_Example::iterate_forward (void)
{
  ACE_TRACE (ACE_TEXT ("Map_Example::iterate_forward"));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Forward iteration\n")));
  for (ACE_Map_Manager<KeyType,
                       DataElement,
                       ACE_Null_Mutex>::iterator
       iter = map_.begin ();
       iter != map_.end ();
       iter++)
    {
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%d:"),
                  (*iter).int_id_.getData ()));
    }
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));
}


void Map_Example::iterate_reverse (void)
{
  ACE_TRACE (ACE_TEXT ("Map_Example::iterate_reverse"));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Reverse iteration\n")));
  for (ACE_Map_Manager<KeyType,
                       DataElement,
                       ACE_Null_Mutex>::reverse_iterator
       iter = map_.rbegin ();
       iter != map_.end ();
       iter++)
    {
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%d:"),
                  (*iter).int_id_.getData ()));
    }
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));
}
// Listing 3
// Listing 4 code/ch05
void Map_Example::remove_all (void)
{
  ACE_TRACE (ACE_TEXT ("Map_Example::remove_all"));

  // Note that we can't use the iterators here as they
  // are invalidated after deletions or insertions.
  map_.unbind_all ();
}
// Listing 4

int ACE_TMAIN (int, ACE_TCHAR *[])
{
  Map_Example me;
  return  me.run ();
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Map_Manager<KeyType,DataElement,ACE_Null_Mutex>
;
template class ACE_Map_Iterator<KeyType,DataElement,ACE_Null_Mutex>
;
template class ACE_Map_Entry<KeyType,DataElement>
;
template class ACE_Map_Iterator_Base<KeyType,DataElement,ACE_Null_Mutex>
;
template class ACE_Map_Reverse_Iterator<KeyType,DataElement,ACE_Null_Mutex>
;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Map_Manager<KeyType,DataElement,ACE_Null_Mutex>
#pragma instantiate ACE_Map_Iterator<KeyType,DataElement,ACE_Null_Mutex>
#pragma instantiate ACE_Map_Reverse_Iterator<KeyType,DataElement,ACE_Null_Mutex>
#pragma instantiate ACE_Map_Entry<KeyType,DataElement>
#pragma instantiate ACE_Map_Iterator_Base<KeyType,DataElement,ACE_Null_Mutex>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

