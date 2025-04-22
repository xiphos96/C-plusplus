#pragma once
#include <memory.h>
#include "Mutex.h"
#include <ds/queue.h>

// ���� ������ �����ӿ� ���� ��Ű��ó �������� �߻�ȭ
class Page : public _QueueNode 
{
public:
	// Ư�� ���� �ּҿ� �ش��ϴ� �������� ��´�. �׸��� �ٸ� �����忡 ���� ���ҵ��� �ʵ��� ��ŷ�Ѵ�.
	// ���� ����ؼ� ��ŷ�� �� �ʿ�� ���� ������ ���¸� �����ؼ� �ٸ� �����尡 �� �������� �������ΰ� �Ѵ�.
	static Page* LockPage(unsigned int pa);

	/// �� �������� ����Ʈ���� ���� �ּҸ� ����.
	unsigned int GetPhysicalAddress() const;

	/// ������� ���� �������� �Ҵ��Ѵ�. 	
	/// @param clear �� ���� true�̸� �������� 0���� �ʱ�ȭ �ȴ�.
	static Page* Alloc(bool clear = false);

	/// �� �������� ��밡���� ����Ʈ�� �̵��Ѵ�.
	void Free();

	/// �� �������� �۾����̶�� ��ŷ(IO�� ���� ������)
	void SetBusy();

	/// �� �������� �۾��� �Ϸ�Ǿ��ٰ� ��ŷ(IO�� ����)
	void SetNotBusy();

	/// @returns �� �������� �۾��߿� �ִٸ� true�� ��ȯ
	inline bool IsBusy() const;

	// �������� ���ҵ��� �ʵ��� ��ٴ�.
	void Wire();

	// ��Ȳ�� ���� ���ҵǵ��� ����� �����Ѵ�. ��Ȯ���� ���¸� �����Ѵ�.
	void Unwire();

	/// �̿� ������ ������ ��ü ���� ��´�.
	static int CountFreePages();

	// ����Ʈ ũ��� ��ü �޸� ����� ��´�.
	static inline unsigned int GetMemSize();

	// �ڷᱸ���� �ʱ�ȭ�ϱ� ���� ��Ʈ �ð��� ȣ��
	static void Bootstrap();

	/// �������� �ʱ�ȭ�ϴ� ���� �켱������ �����带 ����
	static void StartPageEraser();

	// Ư�� ���� �ּҸ� ����� ������ ��ũ�Ѵ�.
	// ��Ʈ�δ��� ���� ���� �̸� �Ҵ�� ���������� �ʱ�ȭ�ϴ� ���� ��ŷ�ϱ� ���� ���ȴ�.
	static void MarkUsed(unsigned int pa);

private:
	enum PageState {
		kPageFree,
		kPageTransition,
		kPageActive,
		kPageWired,
		kPageClear
	};

	void MoveToQueue(PageState);
	static int PageEraser(void*);
	static void PrintStats(int, const char**);

	Page *fHashNext;
	class PageCache *fCache;
	off_t fCacheOffset;
	Page *fCacheNext;
	Page **fCachePrev;
	volatile PageState m_state;

	static class Semaphore s_freePagesAvailable;
	static Page *fPages;
	static _Queue s_freeQueue;
	static _Queue fActiveQueue;
	static _Queue fClearQueue;
	static int s_pageCount;
	static int s_freeCount;
	static int fTransitionCount;
	static int fActiveCount;
	static int fWiredCount;
	static int fClearCount;

	// Page erase statistics
	static int64 fPagesCleared;
	static int64 fPagesRequested;
	static int64 fClearPagesRequested;
	static int64 fClearPageHits;
	static int64 fClearPagesUsedAsFree;


	friend class PageCache;
};

inline unsigned int Page::GetMemSize()
{
	return s_pageCount * PAGE_SIZE;
}

inline bool Page::IsBusy() const
{
	return m_state == kPageTransition;
}
