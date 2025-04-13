#pragma once

enum class InterruptStatus
{
	kUnhandledInterrupt,
	kHandledInterrupt,
	kReschedule
};

const int kMaxInterrupts = 32;

/// �ϵ���� ���ͷ�Ʈ�� �ٷ�� ��� Ŭ������ �⺻ Ŭ����
class InterruptHandler
{
public:
	InterruptHandler(int vector, char* deviceName);
	virtual ~InterruptHandler();

	//���ͷ�Ʈ�� �߻��Ҷ� ȣ��Ǵ� �޼ҵ�. �Ļ� Ŭ������ �� �޼ҵ带 �������̵忡�� �޼ҵ带 �����ؾ� �Ѵ�.
	// ��ȯ�� : InterruptStatus, ���ͷ�Ʈ ü�� ȣ���� ���� ���
	// - kUnhandledInterrupt 
	// �ش� ����̽��� �� ���ͷ�Ʈ�� �߻���Ű�� �ʾҴ�. �� ���ͷ�Ʈ�� �ٷ� �� �ֵ��� ���� ���ͷ�Ʈ �ڵ鷯�� �����϶�.
	// - kHandledInerrupt 
	// �� ����̹��� ���ͷ�Ʈ�� ó���ߴ�. �ٸ� ���ͷ�Ʈ �ڵ鷯�� ���� ȣ���� �ʿ䰡 ����.
	// - kReschedule 
	// �� ����̹��� ���ͷ�Ʈ�� ó���ߴ�. �׸��� �� ���ͷ�Ʈ�� �ϳ� �̻��� �����带 ������·� �����ߴ�.
	// ��������� �������� ���ƾ� �ϹǷ� ���ͷ�Ʈ�� �����Ŀ� �½�ũ�� �����층�Ѵ�.
	virtual InterruptStatus HandleInterrupt(void* arg = nullptr);

	int GetVectorNum() { return m_vectorNum; }

	InterruptHandler* m_pNext;
	int m_vectorNum;
	bool m_Active;
	char m_deviceName[32];
};