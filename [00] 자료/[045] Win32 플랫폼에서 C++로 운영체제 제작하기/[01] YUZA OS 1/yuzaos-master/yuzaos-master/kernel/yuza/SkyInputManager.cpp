#include "SkyInputManager.h"
#include "SystemAPI.h"

SkyInputManager::SkyInputManager()
	: m_mutex(0),
	m_pKeyQueue(0),
    m_pMouseQueue(0)
{
	memset(m_keyQueueBuffer, 0, sizeof(KEYDATA) * KEY_MAXQUEUECOUNT);
	memset(m_mouseQueueBuffer, 0, sizeof(MOUSEDATA) * MOUSE_MAXQUEUECOUNT);
}

SkyInputManager::~SkyInputManager()
{
}

bool SkyInputManager::Initialize()
{ 
	m_pKeyQueue = new SkyQueue();
	m_pKeyQueue->Initialize(m_keyQueueBuffer, KEY_MAXQUEUECOUNT, sizeof(KEYDATA));

	m_pMouseQueue = new SkyQueue();
	m_pMouseQueue->Initialize(m_mouseQueueBuffer, MOUSE_MAXQUEUECOUNT, sizeof(MOUSEDATA));

	m_mutex = kCreateMutex("SkyInputManager");

	return true;
}

bool SkyInputManager::GetKeyFromKeyQueue(KEYDATA* pstData)
{
	bool bResult;
	
	kLockMutex(m_mutex);
	bResult = m_pKeyQueue->GetQueue(pstData);
	kUnlockMutex(m_mutex);
	
	return bResult;
}

bool SkyInputManager::PutKeyQueue(KEYDATA* pstData)
{
	bool bResult;

	kLockMutex(m_mutex);
	bResult = m_pKeyQueue->PutQueue(pstData);
	kUnlockMutex(m_mutex);

	return bResult;
}

bool SkyInputManager::PutMouseueue(MOUSEDATA* pstData)
{
	bool bResult;

	kLockMutex(m_mutex);
	bResult = m_pMouseQueue->PutQueue(pstData);
	kUnlockMutex(m_mutex);

	return bResult;
}

bool SkyInputManager::GetMouseDataFromMouseQueue(BYTE& buttonStatus, int& xpos, int& ypos)
{
	MOUSEDATA stData;
	bool bResult;

	if (m_pMouseQueue->IsQueueEmpty() == true)
	{
		return false;
	}

	kLockMutex(m_mutex);
	bResult = m_pMouseQueue->GetQueue(&stData);
	kUnlockMutex(m_mutex);

	if (bResult == false)
	{
		return false;
	}

	// ���콺 ������ �м�
	// ���콺 ��ư �÷��״� ù ��° ����Ʈ�� ���� 3��Ʈ�� ������
	buttonStatus = stData.bButtonStatusAndFlag & 0x7;

	xpos = stData.bXMovement;
	ypos = stData.bYMovement;
	return true;
}

