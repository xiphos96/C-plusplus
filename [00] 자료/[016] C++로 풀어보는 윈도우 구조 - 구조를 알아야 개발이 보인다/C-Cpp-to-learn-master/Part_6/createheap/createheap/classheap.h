#pragma once
class classheap
{
	static int s_iObject;
	static HANDLE s_hHeap;
private:
	int i_Data[1000]; //4 Kilobyte ũ���� ����
public:
	void* operator new(size_t size);
	void SetData(int value); // �ν��Ͻ��� ���� ���� �� �ִ� ���� �Լ�
	static void DestoryAll();
};

