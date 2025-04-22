#pragma once
// Copyright Idaho O Edokpayi 2008
// Code is governed by Code Project Open License 

//#include <exception>
#include <minwindef.h>
#include <algorithm>

using namespace std;

/////////////////////////
// Array based lock free
// queue 
/////////////////////////
template<class T>
class ArrayQ
{
private:
	T* pData;
	volatile LONG nWrite;
	volatile LONG nRead;
	volatile LONG nSize;
	// size of array at creation
	enum SizeEnum{ InitialSize=240 };
	// Lock pData to copy
	void Resize()
	{
		// Declare temporary size variable
		LONG nNewSize = 0;		
		CRITICAL_SECTION cs;

		// double the size of our queue
		InterlockedExchangeAdd(&nNewSize,2 * nSize);

		// allocate the new array
		T* pNewData = new T[nNewSize];
		const ULONG uiTSize = sizeof(T);

		// Initialize the critical section to protect the copy
		InitializeCriticalSection(&cs);

		// Enter the critical section
		EnterCriticalSection(&cs);

		// copy the old data
		memcpy_s((void*)pNewData,nNewSize*uiTSize,(void*)pData,nSize*uiTSize);		

		// dump the old array
		delete[] pData;

		// save the new array
		pData = pNewData;

		// save the new size
		nSize = nNewSize;

		// Leave the critical section
		LeaveCriticalSection(&cs);

		// Delete the critical section
		DeleteCriticalSection(&cs);
	}
public:
	ArrayQ()	: nWrite(0), nRead(0), pData(new T[InitialSize]), nSize(InitialSize)
	{

	}

	~ArrayQ()
	{
		delete[] pData;
	}


	void enqueue( const T& t ) 
	{
		// temporary write index and size
		volatile LONG nTempWrite, nTempSize;

		// atomic copy of the originals to temporary storage
		InterlockedExchange(&nTempWrite,nWrite);
		InterlockedExchange(&nTempSize,nSize);

		// increment before bad things happen
		InterlockedIncrement(&nWrite);

		// check to make sure we haven't exceeded our storage 
		if(nTempWrite == nTempSize)
		{
			// we should resize the array even if it means using a lock
			Resize();			
		}

		pData[nTempWrite] = t;		
	}

	// returns false if queue is empty
	bool dequeue( T& t ) 
	{
		// temporary write index and size
		volatile LONG nTempWrite, nTempRead;

		// atomic copy of the originals to temporary storage
		InterlockedExchange(&nTempWrite,nWrite);
		InterlockedExchange(&nTempRead,nRead);

		// increment before bad things happen
		InterlockedIncrement(&nRead);

		// check to see if queue is empty
		if(nTempRead == nTempWrite)
		{
			// reset both indices
			InterlockedCompareExchange(&nRead,0,nTempRead+1);
			InterlockedCompareExchange(&nWrite,0,nTempWrite);
			return false;
		}

		t = pData[nTempRead];
		return true;
	}

};



template< class T >
class CLockFreeQueue
{
private:

	// pointer structure
	struct node_t;

	struct pointer_t 
	{
		node_t* ptr;
		LONG count;
		// default to a null pointer with a count of zero
		pointer_t(): ptr(NULL),count(0){}
		pointer_t(node_t* node, const LONG c ) : ptr(node),count(c){}
		pointer_t(const pointer_t& p)
		{
			InterlockedExchange(&count,p.count);
			InterlockedExchangePointer((PVOID volatile*)&ptr,p.ptr);
		}

		pointer_t(const pointer_t* p): ptr(NULL),count(0)
		{
			if(NULL == p)
				return;

			InterlockedExchange(&count,const_cast< LONG >(p->count));
			InterlockedExchangePointer(ptr,const_cast< node_t* >(p->ptr));			
		}

	};

	// node structure
	struct node_t 
	{
		T value;
		pointer_t next;
		// default constructor
		node_t(){}
	};

	pointer_t Head;
	pointer_t Tail;
	bool CAS(pointer_t& dest,pointer_t& compare, pointer_t& value)
	{
		if(compare.ptr==InterlockedCompareExchangePointer((PVOID volatile*)&dest.ptr,value.ptr,compare.ptr))
		{
			InterlockedExchange(&dest.count,value.count);
			return true;
		}

		return false;
	}
public:	
	// default constructor
	CLockFreeQueue()
	{
		node_t* pNode = new node_t();
		Head.ptr = Tail.ptr = pNode;
	}
	~CLockFreeQueue()
	{
		// remove the dummy head
		delete Head.ptr;
	}

	// insert items of class T in the back of the queue
	// items of class T must implement a default and copy constructor
	// Enqueue method
	void Enqueue(const T& t)
	{
		// Allocate a new node from the free list
		node_t* pNode = new node_t(); 

		// Copy enqueued value into node
		pNode->value = t;

		// Keep trying until Enqueue is done
		bool bEnqueueNotDone = true;

		while(bEnqueueNotDone)
		{
			// Read Tail.ptr and Tail.count together
			pointer_t tail(Tail);

			bool nNullTail = (NULL==tail.ptr); 
			// Read next ptr and count fields together
			pointer_t next( // ptr 
							(nNullTail)? NULL : tail.ptr->next.ptr,
							// count
							(nNullTail)? 0 : tail.ptr->next.count
							) ;


			// Are tail and next consistent?
			if(tail.count == Tail.count && tail.ptr == Tail.ptr)
			{
				if(NULL == next.ptr) // Was Tail pointing to the last node?
				{
					// Try to link node at the end of the linked list										
					if(CAS( tail.ptr->next, next, pointer_t(pNode,next.count+1) ) )
					{
						bEnqueueNotDone = false;
					} // endif

				} // endif

				else // Tail was not pointing to the last node
				{
					// Try to swing Tail to the next node
					CAS(Tail, tail, pointer_t(next.ptr,tail.count+1) );
				}

			} // endif

		} // endloop
	}

	// remove items of class T from the front of the queue
	// items of class T must implement a default and copy constructor
	// Dequeue method
	bool Dequeue(T& t)
	{
		pointer_t head;
		// Keep trying until Dequeue is done
		bool bDequeNotDone = true;
		while(bDequeNotDone)
		{
			// Read Head
			head = Head;
			// Read Tail
			pointer_t tail(Tail);

			if(head.ptr == NULL)
			{
				// queue is empty
				return false;
			}

			// Read Head.ptr->next
			pointer_t next(head.ptr->next);

			// Are head, tail, and next consistent
			if(head.count == Head.count && head.ptr == Head.ptr)
			{
				if(head.ptr == tail.ptr) // is tail falling behind?
				{
					// Is the Queue empty
					if(NULL == next.ptr)
					{
						// queue is empty cannot deque
						return false;
					}
					CAS(Tail,tail, pointer_t(next.ptr,tail.count+1)); // Tail is falling behind. Try to advance it
				} // endif

				else // no need to deal with tail
				{
					// read value before CAS otherwise another deque might try to free the next node
					t = next.ptr->value;

					// try to swing Head to the next node
					if(CAS(Head,head, pointer_t(next.ptr,head.count+1) ) )
					{
						bDequeNotDone = false;
					}
				}

			} // endif

		} // endloop
		
		// It is now safe to free the old dummy node
		delete head.ptr;

		// queue was not empty, deque succeeded
		return true;
	}
};

////////////////////////////////////////////////////////////////////////////////
/// \file LockFreeQueue.h
/// \author excel96
/// \date 2006.9.29
////////////////////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////////////////////
/// \class cLockFreeQueue
/// \brief ���� ���� ������� �ʴ� ť. 98 �̻󿡼��� ��� �����ϴ�.
////////////////////////////////////////////////////////////////////////////////

/*template 
<
    typename T,
    template <typename> class AL = std::allocator
>
class cLockFreeQueue
{
private:
#pragma pack(push)
#pragma pack(MEMORY_ALLOCATION_ALIGNMENT)
    struct NODE
    {
        NODE* Next;
        T     Data;
    };
#pragma pack(pop)

    NODE*    m_Head;      ///< ť ���.
    NODE*    m_Tail;      ///< ť ����.
    AL<NODE> m_Allocator; ///< �޸� �Ҵ���.


public:
    /// \brief ������.
    cLockFreeQueue()
    {
        m_Head = m_Allocator.allocate(1);
        m_Allocator.construct(m_Head, NODE());

        m_Tail = m_Head;
        m_Head->Next = NULL;
        m_Tail->Next = NULL;
    }

    /// \brief �Ҹ���.
    ~cLockFreeQueue()
    {
        Clear();
        m_Allocator.destroy(m_Head);
        m_Allocator.deallocate(m_Head, 0);
    }


public:
    /// \brief �����͸� �߰��Ѵ�.
    /// \param data �߰��� ������.
    void Push(const T& data)
    {
        NODE* oldTail = NULL;
        NODE* oldNext = NULL;

        // ���ο� ��带 �Ҵ��Ѵ�.
        NODE* node = m_Allocator.allocate(1);
        m_Allocator.construct(node, NODE());
        node->Next = NULL;
        node->Data = data;

        // ���� ���� Next ��ũ�� ���ο� ��带 ����ų ������ ������ ����.
        bool addedNewNode = false;
        while (!addedNewNode) 
        {
            // �����͵��� ī�Ǹ� �����.
            // �ٸ� �����忡�� ���� �����͸� ������ �� �ֱ� �����̴�.
            oldTail = m_Tail;         
            oldNext = oldTail->Next; 

            // ���� �����Ͱ� ������� �ʾҴٸ�...
            if (m_Tail == oldTail) 
            {
                // ������ Next �����Ͱ� NULL�̶��...
                if (oldNext == NULL) 
                {
                    // ������ Next ������ ������ �õ��Ѵ�.
                    addedNewNode = CAS(&(m_Tail->Next), NULL, node);
                }
                // ������ Next �����Ͱ� NULL�� �ƴ϶�� ����, 
                // �ٸ� �����忡�� ��带 �߰��ϰ� �ִ� ���̶�� ���̴�. 
                // �׷��Ƿ� ���� ������ ������ �õ��Ѵ�.
                else 
                {
                    CAS(&m_Tail, oldTail, oldNext);
                }
            }
        }

        // ���� �����Ͱ� ���ο� ��带 ����Ű���� �����Ѵ�. ������ ���� �ִµ�,
        // �ٸ� �����忡�� ó������ ���̹Ƿ� ������ �ʿ� ����.
        CAS(&m_Tail, oldTail, node);
    }

    /// \brief �����͸� �̾Ƴ���.
    /// \param data �̾Ƴ� �����͸� �� ����.
    /// \return bool �����͸� �̾Ƴ� ��쿡�� true�� ��ȯ�ϰ�, 
    /// �����Ͱ� ���� ��쿡�� false�� ��ȯ�Ѵ�.
    bool Pop(T& data)
    {
        NODE* oldHead = NULL;
        NODE* oldTail = NULL;
        NODE* oldHeadNext = NULL;

        // ��� �����Ͱ� ���� ��带 ����ų ������ ������ ����.
        bool advancedHead = false;
        while (!advancedHead) 
        {
            // �����͵��� ī�Ǹ� �����.
            // �ٸ� �����忡�� ���� �����͸� ������ �� �ֱ� �����̴�.
            oldHead = m_Head;
            oldTail = m_Tail;
            oldHeadNext = oldHead->Next;

            // ��� �����Ͱ� ������� �ʾҴٸ�...
            if (oldHead == m_Head) 
            {
                // ��� �����Ͱ� ���� �����Ϳ� ���ٸ�...
                if (oldHead == oldTail) 
                {
                    // ����� Next �����Ͱ� NULL�̶��...
                    if (oldHeadNext == NULL) 
                    {
                        // �̾Ƴ� �������� �������� �ʴ´�.
                        return false;
                    }

                    // ����� Next �����Ͱ� NULL�� �ƴϰ�, 
                    // ��尡 ���ϰ� ���� �ʴٴ� ����,
                    // �ٸ� �����忡�� ���Ͽ��� ��带 �߰��ϰ� �ִٴ� ���̴�. 
                    // ���� �����͸� ������Ʈ�Ѵ�.
                    CAS(&m_Tail, oldTail, oldHeadNext);
                }
                // ��� �����Ͱ� ���� �����Ϳ� �ٸ��ٸ�...
                else 
                {
                    // �̾Ƴ� �������� �����ϰ�, ��� �����͸� �ڷ� �ű��.
                    data = oldHeadNext->Data;
                    advancedHead = CAS(&m_Head, oldHead, oldHeadNext);
                }
            }
        }

        m_Allocator.destroy(oldHead);
        m_Allocator.deallocate(oldHead, 0);

        return true;
    }

    /// \brief ��� �����͸� �����Ѵ�.
    void Clear()
    {
        T data;
        while (Pop(data))
            ;
    }


private:
    /// Compare and Swap
    bool CAS(NODE** location, NODE* comperand, NODE* newValue)
    {
        return comperand == InterlockedCompareExchangePointer(
            reinterpret_cast<volatile PVOID*>(location), newValue, comperand
            );
    }

    /// \brief ���� ���� ����.
    cLockFreeQueue(const cLockFreeQueue&) {}

    /// \brief ���� ����.
    cLockFreeQueue& operator = (const cLockFreeQueue&) { return *this; }
};*/