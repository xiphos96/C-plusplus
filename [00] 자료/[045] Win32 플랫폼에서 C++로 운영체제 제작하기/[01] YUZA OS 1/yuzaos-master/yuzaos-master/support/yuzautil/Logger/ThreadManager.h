/** 
*  @file		NFThreadManager.h
*  @brief		Auto ThreadManager Ŭ����
*  @remarks	
*  @author		������(edith2580@gmail.com)
*  @date		2009-04-02
*/

#pragma once

#define WINDOWS_LEAN_AND_MEAN


#include "Sync.h"
#include "Thread.h"
#include "Singleton.h" 
/** 
*  @class        NFThreadManager
*  @brief        ������ �Ŵ���
*  @remarks      
*                1) NFThread �� ��ӹ��� �༮				\r\n
*															\r\n
*                Nave::NFThreadManager::Run(this);			\r\n
*                Nave::NFThreadManager::Stop(this, 2000);	\r\n
*															\r\n
*                2) ������ �Ŵ����� ����Ϸ���				\r\n
*                Nave::NFThreadManager::GetInstance().Register( new CTest(this) );	\r\n
*															\r\n
*                // �Ҹ�� �ڵ����� UnRegister�� ȣ��Ǿ�޸𸮿��� ������..		\r\n
*                
*  @par          
*  @author  Edith
*  @date    2009-04-05
*/
class CThreadManager : public CSingleton<CThreadManager>
{
public:
	/// NFThreadManager ������
	CThreadManager();
	/// NFThreadManager �Ҹ���
	virtual ~CThreadManager();

	/// �����带 ����Ѵ�. �ִ� 32������ ����� �� �ִ�.
	BOOL Register(CThread* lpThread);	
	/// ��� �����带 �����Ų��.
	BOOL UnRegister();					

	/// �Ŵ����� ������� �ʰ�, �׳� ���� ��Ų��.
	static HANDLE	Run(CThread* lpThread);
	/// �Ŵ����� ������� �ʰ�, �׳� ���� ��Ų��.
	static BOOL		Stop(CThread* lpThread, unsigned long dwTimeout = INFINITE);

private:
	enum { 
		MAX_THREAD_NUM = 32 /// �ִ� ������ ����
	};

	/// ������ ��ü ������
	CThread*			m_lpThreads[MAX_THREAD_NUM];
	/// ������ �ڵ�
	HANDLE				m_hThreads[MAX_THREAD_NUM];

	/// ������ Lock
	CSync		m_ThreadLock;

	/// ������ ����
	DWORD		m_nThreadNum;
	/// UnRegister�� ���࿩��
	DWORD		m_bUnRegStarted;
};