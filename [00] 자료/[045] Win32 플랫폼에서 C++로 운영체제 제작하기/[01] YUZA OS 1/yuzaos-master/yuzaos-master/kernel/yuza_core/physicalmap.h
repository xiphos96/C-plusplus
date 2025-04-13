#pragma once
#include <memory.h>
#include <List.h>
#include "Mutex.h"
#include "ktypes.h"


class LockedPage;

const int kLockedPageHashSize = 2048;

const int kUncacheablePage = 64; // private PageProtection flag

class PhysicalMap : private ListNode {
public:
	PhysicalMap();
	virtual ~PhysicalMap();
	void Map(unsigned int va, unsigned int pa, PageProtection);
	void Unmap(unsigned int base, unsigned int size);
	unsigned int GetPhysicalAddress(unsigned int va);
	int CountMappedPages() const;
	unsigned int GetPageDir() const;
	static char* LockPhysicalPage(unsigned int pa);
	static void UnlockPhysicalPage(const void *va);
	static void CopyPage(unsigned int destpa, unsigned int srcpa);
	static void Bootstrap();
	static PhysicalMap* GetKernelPhysicalMap();

	unsigned int fPageDirectory;

private:
	PhysicalMap(unsigned int pageDirAddress);
	static void PrintStats(int, const char**);
	
	int fMappedPageCount;
	RecursiveLock fLock;
	static List fPhysicalMaps;
	static LockedPage *fLockedPageHash[kLockedPageHashSize];
	static _Queue fInactiveLockedPages;
	static LockedPage *fLockedPages;
	static PhysicalMap *fKernelPhysicalMap;
	static int fLockPageHits;
	static int fLockPageRequests;
};
