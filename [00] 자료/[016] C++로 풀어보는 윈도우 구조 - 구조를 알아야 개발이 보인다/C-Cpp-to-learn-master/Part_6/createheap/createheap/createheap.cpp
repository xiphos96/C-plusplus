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
				auto p = new classheap; // ������ ���� �ν��Ͻ��� �������� �����Ͽ� �Ҵ��մϴ�.
				p->SetData(i_Heapcount); // �� �ν��Ͻ��� ���� �ֽ��ϴ�.
			}
		}
	}
	classheap::DestoryAll();
    return 0;
}

