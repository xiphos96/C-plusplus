// 5-2.cpp

#include <iostream.h>

int max(int, int);	// ������ �Լ� ���� 

void main()
{
	int i=10, j=20;
	cout << "max = " << max(i, j) << endl;	// ���� ���� ��ġ
}

int max(int a, int b)	// C++ ��Ÿ��
{
	if (a > b)		return	a;
	else			return	b;
}