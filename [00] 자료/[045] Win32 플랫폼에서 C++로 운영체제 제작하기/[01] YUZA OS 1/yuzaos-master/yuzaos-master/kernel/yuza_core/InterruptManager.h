#pragma once
#include <InterruptHandler.h>

class InterruptManager
{
public:
	/// Begin watching an interrupt with the given interrupt vector.  If other InterruptHandlers
	/// are already watching this interrupt, this handler will be chained with them.
	/// @bug The behavior is undefined if you try to watch the same interrupt twice.  Should assert.
	static void ObserveInterrupt(int vector, InterruptHandler* pHandler);
	
	// Ư�� ���ͷ�Ʈ�� �����Ѵ�.
	static void IgnoreInterrupts(InterruptHandler* pHandler);

	/// ���ͷ�Ʈ �߻��� ����̽� �������� ���ͷ�Ʈ �ڵ鷯 ȣ��
	static InterruptStatus Dispatch(int vectorNum);

private:
	static InterruptHandler* s_handlers[kMaxInterrupts];
};