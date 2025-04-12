// createheap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //
#include "classheap.h"

using namespace std;
int main()
{
	cout << "Heap Create Start" << endl;
	while (true)
	{
		cout << "How many heap to allocate?(0:destroy a heap, -1:quit): ";
		int i_Heapcount;
		cin >> i_Heapcount;
		if (i_Heapcount < 0) break;
		if (i_Heapcount == 0)
		{
			classheap::DestoryAll();
		}
		else
		{
			for (int i = 0; i < i_Heapcount; i++)
			{
				auto p = new classheap; // 생성된 힙에 인스턴스를 동적으로 선언하여 할당합니다.
				p->SetData(i_Heapcount); // 각 인스턴스에 값을 넣습니다.
			}
		}
	}
	classheap::DestoryAll();
    return 0;
}

