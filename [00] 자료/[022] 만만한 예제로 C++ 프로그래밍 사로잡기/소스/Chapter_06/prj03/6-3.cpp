// 6-3.cpp

#include <iostream.h>

void main()
{
	int a = 123, b = 456;
	int *const p = &a; 

	cout <<  a << ' ' <<  *p << endl;

	a++;	// a�� �ϳ� ����
	cout <<  a << ' ' <<  *p << endl;

	(*p)++;	// *p�� �ϳ� ����
	cout <<  a << ' ' <<  *p << endl;

	*p = b;	// *p�� b ����
	cout <<  a << ' ' <<  *p << endl;

	cout << &a << ' ' << p << endl;   // �ּ� ���
}