#include "ace/RB_Tree.h"
#include "DataElement.h"

// Little helper class.
template<class EXT_ID, class INT_ID>
class Tree : public ACE_RB_Tree<EXT_ID, INT_ID,
                                ACE_Less_Than<EXT_ID>,
                                ACE_Null_Mutex>
{};

class Tree_Example
{
public:
  // Illustrate the tree.
  int run (void);

private:
  // Use the forward iterator.
  void iterate_forward (void);

  // Use the reverse iterator.
  void iterate_reverse (void);

  // Remove all elements from the tree.
  int remove_all (void);

private:
  Tree<int, DataElement*> tree_;
};

// Listing 1 code/ch05
int Tree_Example::run (void)
{
  ACE_TRACE (ACE_TEXT ("Tree_Example::run"));

  DataElement *d  = 0;
  for (int i = 0; i < 100; i++)
    {
      ACE_NEW_RETURN (d, DataElement (i), -1);
      int result = tree_.bind (i, d);
      if (result!= 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("%p\n"),
                             ACE_TEXT ("Bind")),
                            -1);
        }
    }

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Using find: \n")));
  for (int j = 0; j < 100; j++)
    {
      tree_.find (j, d);
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%d:"), d->getData ()));
    }
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));

  // Use the forward iterator.
  this->iterate_forward ();

  // Use the reverse iterator.
  this->iterate_reverse ();

  // Remove all elements from the tree.
  ACE_ASSERT (this->remove_all ()!= -1);

  // Iterate through once again.
  this->iterate_forward ();

  return 0;
}

void Tree_Example::iterate_forward (void)
{
  ACE_TRACE (ACE_TEXT ("Tree_Example::iterate_forward"));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Forward Iteration: \n")));
  for (Tree<int, DataElement*>::iterator iter = tree_.begin ();
       iter != tree_.end (); iter++)
    {
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%d:"),
                  (*iter).item ()->getData ()));
    }
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));
}

void Tree_Example::iterate_reverse (void)
{
  ACE_TRACE (ACE_TEXT ("Tree_Example::iterate_reverse"));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Reverse Iteration: \n")));
  for (Tree<int, DataElement*>::reverse_iterator iter
         = tree_.rbegin ();
       iter != tree_.rend (); iter++)
    {
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%d:"),
                  (*iter).item ()->getData ()));
    }
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));
}

int Tree_Example::remove_all (void)
{
  ACE_TRACE (ACE_TEXT ("Tree_Example::remove_all"));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Removing elements\n")));

  // Note that we can't use the iterators here as they are
  // invalidated after deletions or insertions.
  for (int i = 0; i < 100; i++)
    {
      DataElement * d = 0;
      int result = tree_.unbind (i, d);
      if (result != 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("%p\n"),
                             ACE_TEXT ("Unbind")),
                            -1);
        }
      ACE_ASSERT (d!= 0);
      delete d;
    }

  return 0;
}
// Listing 1

int ACE_TMAIN (int, ACE_TCHAR *[])
{
  Tree_Example te;
  return te.run ();
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_RB_Tree <int, DataElement*,
ACE_Less_Than<int>, ACE_Null_Mutex>
;
template class Tree <int, DataElement*>
;
template class ACE_RB_Tree_Iterator_Base<int, DataElement*, ACE_Less_Than<int>, ACE_Null_Mutex>
;
template class ACE_RB_Tree_Iterator<int, DataElement*, ACE_Less_Than<int>, ACE_Null_Mutex>
;
template class ACE_RB_Tree_Reverse_Iterator<int, DataElement*, ACE_Less_Than<int>, ACE_Null_Mutex>
;
template class ACE_RB_Tree_Node<int, DataElement*>
;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_RB_Tree <int, DataElement*,ACE_Less_Than<int>, ACE_Null_Mutex>
#pragma instantiate ACE_Less_Than <int>
#pragma instantiate Tree <int, DataElement*>
#pragma instantiate ACE_RB_Tree_Iterator_Base<int, DataElement*, ACE_Less_Than<int>, ACE_Null_Mutex>
#pragma instantiate ACE_RB_Tree_Iterator<int, DataElement*, ACE_Less_Than<int>, ACE_Null_Mutex>
#pragma instantiate ACE_RB_Tree_Reverse_Iterator<int, DataElement*, ACE_Less_Than<int>, ACE_Null_Mutex>
#pragma instantiate ACE_RB_Tree_Node<int, DataElement*>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION*/
