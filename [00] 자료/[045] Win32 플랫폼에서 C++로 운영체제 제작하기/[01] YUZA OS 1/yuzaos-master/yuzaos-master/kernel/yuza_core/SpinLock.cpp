#include "SpinLock.h"
#include "cpu_asm.h"
#include "Thread.h"
#include "intrinsic.h"

#define LOCK_FALSE 0
#define LOCK_TRUE 1

//��Ƽ�ھ�� Ȯ���Ҷ� �̵���ų ��
DWORD GetAPICID()
{
	return 0;
}

SpinLock::SpinLock() : Resource(OBJ_SPINLOCK, "")
{
	fHolder = nullptr;
	teamId = 0;

	m_dwLockCount = 0;
	m_APICID = 0xff;

	m_lockFlag = LOCK_FALSE;
}

SpinLock::~SpinLock()
{
}

int SpinLock::Lock()
{
	int fl = DisableInterrupts();
	
	//�Ӱ迵�� ����
	if (cmpxchg32(&(m_lockFlag), 0, 1) == false)
	{
	
		if (m_APICID == GetAPICID() && fHolder == Thread::GetRunningThread())
		{
			RestoreInterrupts(fl);
			m_dwLockCount++;
			return E_NO_ERROR;
		}

		while (cmpxchg32(&(m_lockFlag), 0, 1) == false)
		{			
			while (m_lockFlag == LOCK_TRUE)
			{
				__asm
				{
					pause
				}
			}
		}
	}
	
	//�Ӱ迵�� ����. ���� �����尡 ���� Unlock�� ���� �ʴ��� 
	//�ٸ� ������� ���ɶ��� ������ �� ������ ������ ������ ���� ����Ѵ�.	
	m_dwLockCount = 1;
	m_APICID = GetAPICID();
	fHolder = Thread::GetRunningThread();

	RestoreInterrupts(fl);

	return E_NO_ERROR;
}

void SpinLock::Unlock()
{
	int fl = DisableInterrupts();

	//���ɶ��� ��� �½�ũ�� �ƴϸ� ����
	if ((m_lockFlag == false) || (m_APICID != GetAPICID()) || fHolder != Thread::GetRunningThread())
	{
		RestoreInterrupts(fl);
		return;
	}
	
	if (m_dwLockCount > 1)
	{
		m_dwLockCount--;
		RestoreInterrupts(fl);
		return;
	}

	m_APICID = 0xFF;
	m_dwLockCount = 0;
	m_lockFlag = LOCK_FALSE;
	fHolder = 0;

	RestoreInterrupts(fl);
}