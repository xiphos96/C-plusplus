// 3-4.cpp

#include <iostream.h>

int a = 123;				// ���� ���� ����

void main()
{
	int a = 456;			// main �Լ� ���� ����
	cout << a << ' ' << ::a << endl;
	{
		int a = 789;		// ���� ��� ���� ����
		cout << a << ' ' << ::a << endl;
	}
}