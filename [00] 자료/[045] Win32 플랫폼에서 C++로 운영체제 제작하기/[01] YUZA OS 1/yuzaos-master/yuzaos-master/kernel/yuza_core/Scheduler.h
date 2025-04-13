#pragma once
#include "Timer.h"
#include "ktypes.h"

const int kMaxPriority = 31;

class Thread;

//�����췯 Ŭ����. ������ ����� �����带 �����Ѵ�.
class _Scheduler : public Timer
{
public:
	_Scheduler();

	//����� ���� �����带 �����ϰ� SwichTo �޼ҵ带 ȣ���ؼ� �ش� ������ ���ؽ�Ʈ�� ��ȯ�Ѵ�.
	void Reschedule();

	// ���� �غ� �� �����带 ���� ť�� �ִ´�.
	// kThreadReady
	void EnqueueReadyThread(Thread* pThread);

private:
	Thread* PickNextThread();
    virtual InterruptStatus HandleTimeout() override;

	int fReadyThreadCount;
	int fHighestReadyThread;
	_Queue fReadyQueue[kMaxPriority + 1];
};

extern _Scheduler gScheduler;