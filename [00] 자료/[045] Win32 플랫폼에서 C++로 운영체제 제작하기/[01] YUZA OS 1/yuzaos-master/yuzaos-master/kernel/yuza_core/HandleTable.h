#pragma once

#include "Mutex.h"
#include "ktypes.h"
#include "memory.h"

const int kLevel1Size = 1024;
const int kLevel2Size = 1024;
const int kSerialNumberCount = 2048;

class Resource;

// HandleTable�� ���ҽ� ������ ���� ������Ʈ�� ���� �ĺ��ڴ�. 
// HandleTable�� 2�ܰ� ���̺�� �����ȴ�.
class HandleTable {
public:
	HandleTable();
	~HandleTable();

	// ���ҽ��� ���̺� ����Ѵ�. �׸��� �� ���ҽ��� ���� �ĺ��ڸ� ��ȯ�Ѵ�.
	int Open(Resource*);

	// ���̺��� �־��� ���ҽ��� �����Ѵ�.
	// @param id Open �Լ��� ��ȯ�ߴ� ���ҽ��� ���� �ĺ���
	void Close(int id);

	// ���̺��� �־��� id�� ���ҽ��� ã�´�.
	Resource* GetResource(int id, int matchType = OBJ_ANY) const;

	// �� ���̺� �ִ� ��� �ڵ��� ����Ѵ�.
	void Print() const;

private:
	struct SubTable *fMainTable[kLevel1Size];
	mutable RWLock fLock;
	int fFreeHint;
};
