#pragma once
#include "HandleTable.h"
#include "Resource.h"
#include <ThreadContext.h>
#include <kmalloc.h>
#include <list>

class AddressSpace;
class Thread;
class Image;

// Team Ŭ������ �����带 ��Ƶ� �׷��̸� ���μ����� ������ �����̴�.
// Team Ŭ������ ������ �׷�� �ּҰ����� ������ �ִ�.
class Team : public Resource, public ListNode 
{
	friend class TeamManager;
public:
	Team(const char* name, int teamId);
	virtual ~Team();
	inline AddressSpace* GetAddressSpace() const;

	// �����尡 �����ɶ� ȣ��ȸ� ���� ������ ����Ʈ�� ������ �����带 �߰��Ѵ�.
	void ThreadCreated(Thread*);

	// �����尡 ����ɶ� ȣ��ȴ�. ������ ����Ʈ���� �ش� �����带 �����Ѵ�.
	void ThreadTerminated(Thread*);

	// ������ ���� �ڽŸ��� �ڵ� ���̺��� �����Ѵ�.
	inline const HandleTable *GetHandleTable() const;
	inline HandleTable* GetHandleTable();

	bool CreateHeap();

	int GetTeamId() { return m_teamId; }

	int StartMainThread(ThreadParam* pParam);
	bool MapDLL(void* image);

	void SetWindowId(QWORD windowId) { m_windowId = windowId; };
	QWORD GetWindowId() { return m_windowId; }

	HANDLE GetUserHeap() { return m_heapHandle; }
	LPVOID AllocateMemory(DWORD dwSize);
	bool DeallocateMemory(LPVOID lpAddress);

	char m_szCWD[MAXPATH];
	char m_currentDrive;
	std::list<void*> m_loadedDllList;
	HANDLE m_moduleHandle;

private:
	Team(const char* name, AddressSpace* addressSpace, int teamId);
	
	Thread* m_pThreadList;	
	Image* m_image;
	HandleTable m_handleTable;
	AddressSpace* m_addressSpace;
	int m_teamId;
	QWORD m_windowId;
	HANDLE m_heapHandle;
	
	//heap_t* m_userHeap;
};

inline AddressSpace* Team::GetAddressSpace() const
{
	return m_addressSpace;
}

inline const HandleTable* Team::GetHandleTable() const
{
	return &m_handleTable;
}

inline HandleTable* Team::GetHandleTable()
{
	return &m_handleTable;
}