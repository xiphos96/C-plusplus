#include "Log.h"
#include "LogManager.h"
#include "gzip.h"
#include "ThreadManager.h"
#include <string.h>
#include <minwinconst.h>
#include <stat_def.h>

CLogThread::CLogThread() : m_pLogHandle(NULL), m_bCompress(TRUE),
m_hFlush(CreateEvent(0, TRUE, FALSE, 0)),
m_hFile(INVALID_HANDLE_VALUE), m_dwTotalWritten(0),
m_dwMaxFileSize(MAX_FILE_SIZE)
{
	InterlockedExchange(&m_bEnd, FALSE);
}

CLogThread::~CLogThread()
{
	if(INVALID_HANDLE_VALUE != m_hFile)
	{ 
		CloseHandle(m_hFile);
		m_hFile = INVALID_HANDLE_VALUE;
	}

	if(0 != m_hFlush) 
	{
		CloseHandle(m_hFlush); 
		m_hFlush = 0;
	}	
}

void CLogThread::Initialize(CLogManager* pLog, BOOL bCompress)
{
	m_bCompress = bCompress;
	m_pLogHandle = pLog;
}

unsigned int CLogThread::Run()
{
	// ���⼭ m_bEnd�� TRUE�� �ƴϸ� �����尡 �۵��ϰ� �ִ�.
	for(;TRUE != InterlockedCompareExchange(&m_bEnd, TRUE, TRUE);)
	{
		// ���� �̺�Ʈ�� ������̸� 1�ʰ� ����� �ٽ� Ȯ��.
		if(WAIT_TIMEOUT == WaitForSingleObject(m_hFlush, 1000))
		{
			continue;
		}

		WriteLog();
	};

	WriteLog();
	return 0;
}

BOOL CLogThread::End()
{
	InterlockedExchange(&m_bEnd, TRUE);
	SetEvent(m_hFlush);

	return TRUE;
}

BOOL CLogThread::WriteLog()
{
	// �α׿��� ���۸� �о�´�.
	if(!m_pLogHandle)
		return FALSE;

	m_pLogHandle->SpliceInWriteBuffer(m_WriteBufferList);

	if(m_WriteBufferList.empty())
		return TRUE;

	if(INVALID_HANDLE_VALUE == m_hFile)
	{
		SetLogFileName();
		m_hFile = CreateFile(m_szLogFileName, GENERIC_WRITE,
			FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

		if(INVALID_HANDLE_VALUE == m_hFile)
		{
			return FALSE;
		}
	}

	unsigned long dwWritten = 0;

	for(CLogBuffer::List::iterator itr = m_WriteBufferList.begin();
		itr != m_WriteBufferList.end(); ++itr)
	{
		CLogBuffer* pLogBuffer = *itr;
		if(FALSE == WriteFile(m_hFile, pLogBuffer->m_Buffer, pLogBuffer->m_dwUsage, &dwWritten, 0))
		{
			LOG_ERROR(("�α� ���� ��Ͽ� �����߽��ϴ�. ErrorNum : %d, FileHandle:0x%p, ���� ũ��:%d",
				GetLastError(), m_hFile, pLogBuffer->m_dwUsage));
		}

		m_dwTotalWritten += dwWritten;
	}

	m_pLogHandle->SpliceInFreeBuffer(m_WriteBufferList);

	// ������ ��� ������´�.
	if(m_dwTotalWritten > m_dwMaxFileSize)
	{
		if(INVALID_HANDLE_VALUE != m_hFile) { CloseHandle(m_hFile); m_hFile = INVALID_HANDLE_VALUE; }	// ���� �ݰ�...

		if(m_bCompress)
			Compress();

		m_dwTotalWritten = 0;
	}

	return TRUE;
}

BOOL CLogThread::Compress()
{
	HANDLE hFile = CreateFile(m_szLogFileName, GENERIC_READ, 
		FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if(INVALID_HANDLE_VALUE == hFile)
	{
		LOG_ERROR(("���� �α׸� ������ �� �����ϴ�."));
		return FALSE;
	}

	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);

	unsigned long dwSpinCount = 0;
	char szCompressedLogFileName[MAX_PATH*2];

	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	splitpath(m_szLogFileName, drive, dir, fname, ext);

	while (TRUE) 
	{		
		snprintf(szCompressedLogFileName, MAX_PATH*2, "%s\\%s-%04d%02d%02d-%02d%02d%02d-%04d.log.gz",
			dir, fname, sysTime.wYear, sysTime.wMonth, sysTime.wDay, 
			sysTime.wHour, sysTime.wMinute, sysTime.wSecond, dwSpinCount);

		struct stat info;

		int result = stat(szCompressedLogFileName, &info);
		if (result != 0)
		{
			break;
		}

		++dwSpinCount;
	}

	// ���� �˰��� �߰�.
	SDK::CGZip gzip;

	if (!gzip.Open(szCompressedLogFileName, SDK::CGZip::ArchiveModeWrite))
	{
		LOG_ERROR(("���� ������ ������ �����߽��ϴ�."));
		CloseHandle(hFile);
		return FALSE;
	}

	unsigned long	dwRead = 0;
	char	szBuffer[4096];
	int nError = 0;
	while(FALSE != ReadFile(hFile, szBuffer, 4096, &dwRead, 0))
	{
		if(0 == dwRead)
		{
			break;
		}

		if(!gzip.WriteBuffer(szBuffer, dwRead))
		{
			LOG_ERROR(("������ ���� ���� ���Ͽ� ����� �� �����ϴ�."));
			nError = -1;
			break;
		}
	}

	gzip.Close();

	CloseFile(hFile);

	//int nError = GetLastError();
	if(0 != nError)
	{
		LOG_ERROR(("%d ������ ���� �α� ���� ������ �����߽��ϴ�.", nError));
		return FALSE;
	}

	// �α����� ����
	if(0 != rmdir(m_szLogFileName))
	{
		LOG_ERROR(("%d ������ ���� �����ϰ� �� �α׸� �������� ���߽��ϴ�.", nError));
		return FALSE;
	}	

	return TRUE;
}

BOOL CLogThread::SetLogFileName()
{
	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);

	unsigned long dwSpinCount = 0;
	char szProgramName[MAX_PATH] = "temp";
	char szLogFilePrefix[MAX_PATH];

	// ���α׷��̸��� ������ ���������� �����Ѵ�.
	//GetProgramName(szProgramName, MAX_PATH);

	if(m_pLogHandle)
		snprintf(szLogFilePrefix, MAX_PATH - 1, "%s", m_pLogHandle->GetLogFilePrefix());
	else
		strcpy(szLogFilePrefix, szProgramName);

	struct stat info;

	int result = stat(szProgramName, &info);
	if (result != 0)
	{
		if (0 != mkdir(szProgramName, 0))
		{			
			return FALSE;
		}
	}

	while (TRUE) 
	{
		int LogLen = snprintf(m_szLogFileName, MAX_PATH, 
			"%s\\%s-%04d%02d%02d-%02d%02d%02d-%04d.log", 
			szProgramName, szLogFilePrefix, sysTime.wYear, sysTime.wMonth, sysTime.wDay,
			sysTime.wHour, sysTime.wMinute, sysTime.wSecond, dwSpinCount);

		if(LogLen <= 0)
		{
			LOG_ERROR(("�� �α׸� ���� ���� �̸��� ������ �� �����ϴ�."));
			return FALSE;
		}
		struct stat info;

		int result = stat(szProgramName, &info);
		if (result != 0)
		{
			break;
		}

		++dwSpinCount;
	}

	return TRUE;
}

CLogManager::CLogManager(void) : m_lpDetailBuffer(0)
{
}

CLogManager::~CLogManager(void)
{
	Destroy();
}

BOOL CLogManager::Initialize(BOOL bCompress, const char* szLogFilePrefix)
{
	char strName[MAX_PATH] = "temp";
	//GetProgramName(strName, MAX_PATH);
	strcpy(m_szLogFilePrefix, strName);

	if(szLogFilePrefix != 0)
	{
		strcat(m_szLogFilePrefix, szLogFilePrefix);
	}

	// ó���� �������� ������ŭ �����.
	for(int nCount = 0; nCount < DEFAULT_FREE_LOG_BUFFER_NUM; ++nCount)
	{
		CLogBuffer* pDetailBuffer = new CLogBuffer;
		if(0 == pDetailBuffer)
		{
			LOG_ERROR(("Fail to Allocate Detail Log Buffer!!"));
			Destroy();
			return FALSE;
		}

		m_FreeList.push_back(pDetailBuffer);
	};

	// ���۰� ������ �켱 1�� ������.
	if(m_lpDetailBuffer == 0)
	{
		m_lpDetailBuffer = GetBuffer();
	}

	m_LogSaveThread.Initialize(this, bCompress);

	if(INVALID_HANDLE_VALUE == CThreadManager::Run(&m_LogSaveThread))
	{
		LOG_ERROR(("Flush�����带 �����ϴ� �� �����߽��ϴ�"));
		return FALSE;
	}

	return TRUE;
}

BOOL CLogManager::Destroy()
{
	Flush();
	CThreadManager::Stop(&m_LogSaveThread, INFINITE);

	// ��ũ�Ǵ�.
	CSyncLock CL(&m_LogSync);

	CLogBuffer* pDetailBuffer;
	for(CLogBuffer::List::iterator itr = m_FreeList.begin(); itr != m_FreeList.end(); ++itr)
	{
		pDetailBuffer = (*itr);
		_DELETE(pDetailBuffer);
	}
	m_FreeList.clear();

	for(CLogBuffer::List::iterator itr = m_WriteList.begin(); itr != m_WriteList.end(); ++itr)
	{
		pDetailBuffer = (*itr);
		_DELETE(pDetailBuffer);
	}
	m_WriteList.clear();

	return TRUE;
}

void CLogManager::SetLogMaxSize(DWORD dwSize)
{
	m_LogSaveThread.SetLogMaxSize(dwSize);
}

CLogBuffer* CLogManager::GetBuffer()
{
	// ��ũ�Ǵ�.
	CSyncLock CL(&m_LogSync);

	CLogBuffer*	pLogBuffer = 0;
	if(m_FreeList.empty())
	{
		// ���� ���۰� ������ �ǽð����� �����ع�����. ��¿������.
		pLogBuffer = new CLogBuffer;
	}
	else
	{
		pLogBuffer = m_FreeList.front();
		m_FreeList.pop_front();
	}

	if(0 == pLogBuffer)
	{
		LOG_ERROR(("�� �α� ���۸� �Ҵ��� �� �����ϴ�."));
		return 0;
	}

	pLogBuffer->Initialize();
	return pLogBuffer;
};

BOOL CLogManager::Flush()
{
	// ���۸� �ִ´�.
	PushBuffer(&m_lpDetailBuffer);
	return m_LogSaveThread.FlushSignal();
}

char* CLogManager::ReserveBuffer(unsigned short usReserve)
{
	CSyncLock CL(&m_LogSync);

	if(0 == m_lpDetailBuffer)
	{
		m_lpDetailBuffer = GetBuffer();
	}

	if(CLogBuffer::MAX_LOG_BUFFER < m_lpDetailBuffer->m_dwUsage + usReserve)
	{
		Flush();	// ���۰� ��á���� �����ض�.
		m_lpDetailBuffer = GetBuffer();		
	}

	if(0 == m_lpDetailBuffer)
	{
		LOG_ERROR(("�α� ���۰� 0�Դϴ�."));
		return 0;
	}

	// ���ø�Ʈ�� �����ؼ� �ش翵���� Ȯ���Ѵ�.
	char* pPoint = &m_lpDetailBuffer->m_Buffer[m_lpDetailBuffer->m_dwUsage];
	Complete(usReserve);
	return pPoint;
}

void CLogManager::SpliceInWriteBuffer(CLogBuffer::List& logBufferList)
{
	CSyncLock CL(&m_LogSync);

	if(m_WriteList.empty())
		return;

	// WriteBuffer �� �����´�.
	logBufferList.splice(logBufferList.end(), m_WriteList);
}

void CLogManager::SpliceInFreeBuffer(CLogBuffer::List& logBufferList)
{
	CSyncLock CL(&m_LogSync);

	if(logBufferList.empty())
		return;

	m_FreeList.splice(m_FreeList.end(), logBufferList);
}

void CLogManager::PushBuffer(CLogBuffer** ppDetailBuffer)
{
	if(0 == *ppDetailBuffer) { return; }

	CSyncLock CL(&m_LogSync);

	if(0 == (*ppDetailBuffer)->m_dwUsage)
	{
		// ����� 0�̴� �ٽ� Free�� ����.
		m_FreeList.push_back(*ppDetailBuffer);
	}
	else
	{
		m_WriteList.push_back(*ppDetailBuffer);
	}

	// �̺κ� �빮�� ���������ͷ� ������ ������.
	*ppDetailBuffer = 0;
}
