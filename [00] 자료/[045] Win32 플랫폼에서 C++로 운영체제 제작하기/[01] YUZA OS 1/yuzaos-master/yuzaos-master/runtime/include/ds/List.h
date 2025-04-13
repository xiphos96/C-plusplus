#pragma once


#include "windef.h"
#include <assert.h>

struct ListNode {
public:
	inline ListNode();
	virtual ~ListNode() {}
	inline void RemoveFromList();

private:
	ListNode *fNext;
	ListNode *fPrev;
	friend class List;
	friend class _Queue;
};

class List {
public:
	inline List();
	inline ListNode* AddToTail(ListNode*);
	inline ListNode* AddToHead(ListNode*);
	inline ListNode* AddBefore(ListNode *next, ListNode *newEntry);
	inline ListNode* AddAfter(ListNode *prev, ListNode *newEntry);
	inline ListNode* Remove(ListNode*);
	inline ListNode* GetHead() const;
	inline ListNode* GetTail() const;
	inline ListNode* GetNext(const ListNode*) const;
	inline ListNode* GetPrevious(const ListNode*) const;
	inline bool IsEmpty() const;
	inline int CountItems() const;

protected:

	// The nodes are stored in a doubly-linked circular list
	// of entries, with this dummy node as the head.
	ListNode fDummyHead;

};

inline ListNode::ListNode()
	:	fNext(0),
		fPrev(0)
{
}

inline void ListNode::RemoveFromList()
{
	fPrev->fNext = fNext;
	fNext->fPrev = fPrev;
	fNext = 0;
	fPrev = 0;  
}

inline List::List()
{
	fDummyHead.fNext = &fDummyHead;
	fDummyHead.fPrev = &fDummyHead;
}

inline ListNode* List::AddToTail(ListNode *node)
{
	ASSERT(!node->fPrev);
	node->fNext = &fDummyHead;
	node->fPrev = fDummyHead.fPrev;
	node->fNext->fPrev = node;
	node->fPrev->fNext = node;
	return node;
}

inline ListNode* List::AddToHead(ListNode *node)
{
	ASSERT(!node->fPrev);
	node->fPrev = &fDummyHead;
	node->fNext = fDummyHead.fNext;
	node->fNext->fPrev = node;
	node->fPrev->fNext = node;
	return node;
}

inline ListNode* List::Remove(ListNode *node)
{
	node->RemoveFromList();
	return node;
}

inline ListNode* List::GetHead() const
{
	if (fDummyHead.fNext == &fDummyHead)
		return 0;

	return fDummyHead.fNext;
}

inline ListNode* List::GetTail() const
{
	if (fDummyHead.fPrev == &fDummyHead)
		return 0;

	return fDummyHead.fPrev;
}

inline ListNode* List::GetNext(const ListNode *node) const
{
	if (node->fNext == &fDummyHead)
		return 0;

	return node->fNext;
}

inline ListNode* List::GetPrevious(const ListNode *node) const
{
	if (node->fPrev == &fDummyHead)
		return 0;

	return node->fPrev;
}

inline ListNode* List::AddBefore(ListNode *nextEntry, ListNode *newEntry)
{
	ASSERT(!newEntry->fPrev);
	newEntry->fNext = nextEntry;
	newEntry->fPrev = nextEntry->fPrev;
	newEntry->fPrev->fNext = newEntry;
	newEntry->fNext->fPrev = newEntry;

	return newEntry;
}

inline ListNode* List::AddAfter(ListNode *previousEntry, ListNode *newEntry)
{
	ASSERT(!newEntry->fPrev);
	newEntry->fNext = previousEntry->fNext;
	newEntry->fPrev = previousEntry;
	newEntry->fPrev->fNext = newEntry;
	newEntry->fNext->fPrev = newEntry;

	return newEntry;
}

inline bool List::IsEmpty() const
{
	return fDummyHead.fNext == &fDummyHead;
}

inline int List::CountItems() const
{
	int count = 0;
	for (ListNode *node = fDummyHead.fNext; node != &fDummyHead; node = node->fNext)
		count++;

	return count;
}
