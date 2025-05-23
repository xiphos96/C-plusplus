#include "ace/Containers.h"
#include "DataElement.h"

class QueueExample
{
public:
  // Illustrate the various ACE Queues.
  int run (void);

private:
  // Illustrate the ACE unbounded queue
  // that has copies of the data elements.
  int runStackUnboundedQueue (void);

  // Illustrate the ACE unbounded queue
  // with pointers to elements on the heap.
  int runHeapUnboundedQueue (void);
};

int QueueExample::run (void)
{
  ACE_TRACE (ACE_TEXT ("QueueExample::run"));

  // Illustrate the queue with elements on the stack.
  if (this->runStackUnboundedQueue () != 0)
    {
      return -1;
    }

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n# of live objects %d\n"),
              DataElement::numOfActiveObjects ()));

  // Illustrate the queue with elements on the heap.
  if (this->runHeapUnboundedQueue () != 0)
    {
      return -1;
    }

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n# of live objects %d\n"),
              DataElement::numOfActiveObjects ()));

  return 0;
}

// Listing 1 code/ch05
int QueueExample::runStackUnboundedQueue (void)
{
  ACE_TRACE (ACE_TEXT ("QueueExample::runStackUnboundedQueue"));

  ACE_Unbounded_Queue<DataElement> queue;
  int i;
  for (i = 0; i < 10; i++)
    {
      DataElement elem[10];
      elem[i].setData (9-i);
      queue.enqueue_head (elem[i]);
    }

  for (i = 0; i< 10; i++)
    {
      DataElement elem[10];
      elem[i].setData (i+10);
      queue.enqueue_tail (elem[i]);
    }

  for (ACE_Unbounded_Queue_Iterator<DataElement> iter (queue);
       !iter.done ();
       iter.advance ())
    {
      DataElement *elem;
      iter.next (elem);
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%d:"), elem->getData ()));
    }

  return 0;
}
// Listing 1
// Listing 2 code/ch05
int QueueExample::runHeapUnboundedQueue (void)
{
  ACE_TRACE (ACE_TEXT ("QueueExample::runHeapUnboundedQueue"));

  ACE_Unbounded_Queue<DataElement*> queue;
  for (int i = 0; i < 20; i++)
    {
      DataElement *elem;
      ACE_NEW_RETURN(elem, DataElement (i), -1);
      queue.enqueue_head (elem);
    }

  for (ACE_Unbounded_Queue_Iterator<DataElement*> iter
         = queue.begin ();
       !iter.done ();
       iter.advance ())
    {
      DataElement **elem;
      iter.next(elem);
      ACE_DEBUG
        ((LM_DEBUG, ACE_TEXT ("%d:"), (*elem)->getData ()));
      delete (*elem);
    }

  return 0;
}
// Listing 2
int ACE_TMAIN (int, ACE_TCHAR *[])
{
  QueueExample que;
  return que.run ();
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Unbounded_Queue<DataElement*>
;
template class ACE_Unbounded_Queue_Iterator<DataElement*>
;
template class ACE_Unbounded_Queue<DataElement>
;
template class ACE_Unbounded_Queue_Iterator<DataElement>
;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Unbounded_Queue<DataElement*>
#pragma instantiate ACE_Unbounded_Queue_Iterator<DataElement*>
#pragma instantiate ACE_Unbounded_Queue<DataElement>
#pragma instantiate ACE_Unbounded_Queue_Iterator<DataElement>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION*/
