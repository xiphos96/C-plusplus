#pragma once
#include <ds/queue.h>

// �񵿱� ���ν��� ��
// �Լ��� Ŀ�ο��� ����Ǵ� �����带 ����Ͽ� Ŀ�� ��忡�� ȣ��ȴ�.
struct APC : public _QueueNode {
	/// �񵿱� ���ν��� ���� �߻��Ҷ� ����Ǵ� �Լ�
	/// �� �Լ��� �������� �Ǵ� Ŀ�� ������ ���� �� �ִ�.
	void (*fCallback)(void *data);

	/// �ݹ� �Լ��� ���޵Ǵ� ������
	void *fData;

	/// �� �Լ��� Ŀ�� ��忡���� APC�� true �׷��� �ʰ� ���� ���� false
	bool fIsKernel;
};
