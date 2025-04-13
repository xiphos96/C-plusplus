#include "InterruptManager.h"
#include "systemcall_impl.h"
#include "intrinsic.h"
#include <stdio.h>
#include <SystemAPI.h>

InterruptHandler* InterruptManager::s_handlers[kMaxInterrupts] = { 0, };

void InterruptManager::ObserveInterrupt(int vectorNum, InterruptHandler* pHandler)
{
	kprintf("ObserveInterrupt %x\n", vectorNum);
	
	if (vectorNum < 0 || vectorNum > kMaxInterrupts)
		Syscall_Panic("Wrong Interrupt vectorNum\n");

	int st = DisableInterrupts();
	
//���� �� ���ͷ�Ʈ�� ������ ���� �ڵ鷯�� �ϳ��� �����ٸ�
//�ش� ���ͷ�Ʈ�� �߻��ϵ��� �Ѵ�..
	if (s_handlers[vectorNum] == 0)
		EnableIrq(vectorNum);

//�ڵ鷯 �߰��� �� �ڵ鷯�� �ڵ鷯 ����Ʈ���� ���ο� �´�.
	pHandler->m_pNext = s_handlers[vectorNum];
	s_handlers[vectorNum] = pHandler;
	pHandler->m_vectorNum = vectorNum;

	RestoreInterrupts(st);

	
}

void InterruptManager::IgnoreInterrupts(InterruptHandler* pHandler)
{
	if(pHandler == nullptr)
		Syscall_Panic("Interrupt Handler is nullptr");

	int vectorNum = pHandler->GetVectorNum();

	if (vectorNum < 0 || vectorNum >= kMaxInterrupts)
		Syscall_Panic("Attempt to handler that isn't registered");

	int st = DisableInterrupts();

	if (s_handlers[vectorNum] == 0)
		Syscall_Panic("Attempt to remove interrupt handler that is not installed");

	if (s_handlers[vectorNum] == pHandler)
		s_handlers[vectorNum] = pHandler->m_pNext;
	else
	{
		for (InterruptHandler* handler = s_handlers[vectorNum];; handler = handler->m_pNext)
		{
			if (handler->m_pNext == 0)
				Syscall_Panic("Interrupt handler is registered, but is not in list");

			if (handler->m_pNext == pHandler) 
			{
				handler->m_pNext = handler->m_pNext->m_pNext;
				break;
			}
		}
	}

//��Ʈ��Ʈ �ڵ鷯�� �ڵ鷯 ����Ʈ���� ���ŵǾ���. ���� ���ŵ� �ڵ鷯�� ������ ������
//���ͷ�Ʈ�� ���� ������ ������ �ٸ� �ڵ鷯�� �ϳ��� �������� �ʴ´ٸ�
//���� �ش� ���ͷ�Ʈ�� �߻����� �ʰ� �Ѵ�.
	if (s_handlers[vectorNum] == 0)
		DisableIrq(vectorNum);

	pHandler->m_vectorNum = -1;
	RestoreInterrupts(st);
}

InterruptStatus InterruptManager::Dispatch(int vectorNum)
{
	InterruptStatus result = InterruptStatus::kUnhandledInterrupt;
	for (InterruptHandler* handler = s_handlers[vectorNum]; handler != 0 ; handler = handler->m_pNext)
	{
		if (handler->m_Active)
			Syscall_Panic("Interrupt handler called reentrantly");

		handler->m_Active = true;
//  �� ���ͷ�Ʈ�� ������ �ִ� ��� �ڵ鷯�� HandleInterrupt�� ȣ���Ѵ�.
		result = handler->HandleInterrupt();
		handler->m_Active = false;

//���� �ڵ鷯�� �� ���ͷ�Ʈ�� ������ ������ �ִ� �ϴ��� ���ͷ�Ʈ�� �ϳ��� �ڵ鷯���� ��ȿ�� ���̴�.
//�׷��� ���ͷ�Ʈ ó���� �����ߴٸ� ���� ������ �ڵ鷯�� ���ؼ� ���ͷ�Ʈ ó���� �� �ʿ䰡 ����. 
		if (result != InterruptStatus::kUnhandledInterrupt)
			break;
	}

	if (result == InterruptStatus::kUnhandledInterrupt)
		kprintf("Unhandled Dispatch %x\n", vectorNum);

	return result;
}