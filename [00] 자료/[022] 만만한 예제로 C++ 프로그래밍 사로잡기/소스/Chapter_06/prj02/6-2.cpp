// 6-2.cpp

#include <iostream.h>

int max(int a, int b)
{
	return (a > b) ? a: b;
}

void main()
{
	int a = 123, b = 456;
	int (&f)(int, int) = max;

	cout << max(a, b) << ' ' << f(a, b) << endl;	// �Լ� ȣ��
	cout << &max << ' ' << &f << endl;		// �Լ� �ּ�
}