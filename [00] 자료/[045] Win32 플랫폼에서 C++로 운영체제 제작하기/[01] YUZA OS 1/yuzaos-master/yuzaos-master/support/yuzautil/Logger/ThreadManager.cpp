
#include "Thread.h"
#include "ThreadManager.h"

HANDLE CThreadManager::Run(CThread* lpThread) 
{
	unsigned int nThreadID = 0;
HANDLE hThread = reinterpret_cast<HANDLE>(_beginthreadex(0,
	0, CThread::ThreadFunc, lpThread, 0, &nThreadID));

lpThread->SetHandle(hThread);
return hThread;
}

BOOL CThreadManager::Stop(CThread* lpThread, unsigned long dwTimeout)
{
	if (0 == lpThread)
	{
		return FALSE;
	}

	HANDLE hThread = lpThread->GetHandle();
	if (INVALID_HANDLE_VALUE == hThread)
	{
		return FALSE;
	}

	lpThread->SetHandle(INVALID_HANDLE_VALUE);
	lpThread->End();
	WaitForSingleObject(hThread, dwTimeout);
	return (TRUE == CloseHandle(hThread));
}

CThreadManager::CThreadManager() : m_nThreadNum(0), m_bUnRegStarted(FALSE)
{
	for (int i = 0; i < MAX_THREAD_NUM; ++i)
	{
		m_lpThreads[i] = NULL;
		m_hThreads[i] = NULL;
	}
}

CThreadManager::~CThreadManager()
{
	UnRegister();
}

BOOL CThreadManager::Register(CThread* llpThread)
{
	unsigned int nThreadID = 0;
	unsigned int nThreadIndex = 0;

	if (0 == llpThread)
	{
		return FALSE;
	}

	//	Lock
	{
		CSyncLock Sync(&m_ThreadLock);

		if (MAX_THREAD_NUM <= m_nThreadNum || TRUE == m_bUnRegStarted)
		{
			return FALSE;
		}

		nThreadIndex = m_nThreadNum;
		++m_nThreadNum;
	}

	m_lpThreads[nThreadIndex] = llpThread;

	m_hThreads[nThreadIndex] = reinterpret_cast<HANDLE>(_beginthreadex(0, 0,
		CThread::ThreadFunc, llpThread, 0, &nThreadID));

	return (0 != m_hThreads[nThreadIndex]);
}

BOOL CThreadManager::UnRegister()
{
	{
		CSyncLock Sync(&m_ThreadLock);

		if (0 == m_nThreadNum)
		{
			return TRUE;
		}

		// ������ ���۵Ǹ�, ���̻��� ������ ���� �� ����� ������.
		m_bUnRegStarted = TRUE;
	}

	// ������ ���� ���� & ���.
	for (int i = 0; i < (int)m_nThreadNum; ++i)
	{
		if (m_lpThreads[i])
		{
			m_lpThreads[i]->End();
		}
	}

	WaitForMultipleObjects(m_nThreadNum, m_hThreads, TRUE, INFINITE);

	// ������ �Ҹ�.
	for (int i = 0; i < MAX_THREAD_NUM; ++i)
	{
		if (m_lpThreads[i])
		{
			delete m_lpThreads[i];
			m_lpThreads[i] = 0;
		}

		if(m_hThreads[i])
		{
			CloseHandle(m_hThreads[i]);
			m_hThreads[i] = NULL;
		}
	}

	{
		// ������ ���� �� ���� ���� ����.
		CSyncLock Sync(&m_ThreadLock);

		m_nThreadNum = 0;
		m_bUnRegStarted = FALSE;
	}

	return TRUE;
}
