// 6-1.cpp

#include <iostream.h>

void main()
{
	int a = 123, b = 456;
	int &r = a; 

	cout <<  a << ' ' <<  r << endl;

	a++;	// a�� �ϳ� ����
	cout <<  a << ' ' <<  r << endl;

	r++;	// r�� �ϳ� ����
	cout <<  a << ' ' <<  r << endl;

	r = b;	// r�� b ����
	cout <<  a << ' ' <<  r << endl;

	cout << &a << ' ' << &r << endl;   // �ּ� ���
}