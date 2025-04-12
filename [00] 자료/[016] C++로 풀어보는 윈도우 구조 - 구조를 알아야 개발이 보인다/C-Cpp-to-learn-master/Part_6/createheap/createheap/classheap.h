#pragma once
class classheap
{
	static int s_iObject;
	static HANDLE s_hHeap;
private:
	int i_Data[1000]; //4 Kilobyte 크기의 변수
public:
	void* operator new(size_t size);
	void SetData(int value); // 인스턴스에 값을 넣을 수 있는 노출 함수
	static void DestoryAll();
};

