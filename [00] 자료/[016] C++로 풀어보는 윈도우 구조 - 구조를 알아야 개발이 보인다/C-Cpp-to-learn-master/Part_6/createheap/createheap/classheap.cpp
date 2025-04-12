#include "stdafx.h"
#include "classheap.h"

int classheap::s_iObject = 0;
HANDLE classheap::s_hHeap = nullptr;

void* classheap::operator new(size_t size)
{
	if (s_iObject == 0)
	{
		s_hHeap = HeapCreate(0, 1 << 16, 1 << 20);// ó�� ������ ��û�� ��� ���� �������� �����Ƿ� HeapCreate�� �̿��Ͽ� ���� �����մϴ�.
	}	
	s_iObject++;

	return(HeapAlloc(s_hHeap, 0, size)); // ��û�� ũ�� ��ŭ �Ҵ��Ͽ� ȸ���մϴ�.
}

void classheap::SetData(int value)
{
	// ������ ���� �����ϰ�, ũ�⸦ �ʱ�ȭ �մϴ�.
	for (int i = 0; i < 1000; i++)
	{
		i_Data[i] = value;
	}
}

void classheap::DestoryAll()
{
	// ������ ���� �����ϰ�, ũ�⸦ �ʱ�ȭ �մϴ�.
	HeapDestroy(s_hHeap); 
	s_iObject = 0;
}


