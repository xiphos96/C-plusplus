#include "stdafx.h"
#include "classheap.h"

int classheap::s_iObject = 0;
HANDLE classheap::s_hHeap = nullptr;

void* classheap::operator new(size_t size)
{
	if (s_iObject == 0)
	{
		s_hHeap = HeapCreate(0, 1 << 16, 1 << 20);// 처음 생성을 요청한 경우 힙이 존재하지 않으므로 HeapCreate을 이용하여 힙을 생성합니다.
	}	
	s_iObject++;

	return(HeapAlloc(s_hHeap, 0, size)); // 요청한 크기 만큼 할당하여 회신합니다.
}

void classheap::SetData(int value)
{
	// 생성한 힙을 제거하고, 크기를 초기화 합니다.
	for (int i = 0; i < 1000; i++)
	{
		i_Data[i] = value;
	}
}

void classheap::DestoryAll()
{
	// 생성한 힙을 제거하고, 크기를 초기화 합니다.
	HeapDestroy(s_hHeap); 
	s_iObject = 0;
}


