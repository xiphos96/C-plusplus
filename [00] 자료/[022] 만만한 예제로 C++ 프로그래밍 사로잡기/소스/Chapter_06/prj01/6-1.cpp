// 6-1.cpp

#include <iostream.h>

void main()
{
	int a = 123, b = 456;
	int &r = a; 

	cout <<  a << ' ' <<  r << endl;

	a++;	// a를 하나 증가
	cout <<  a << ' ' <<  r << endl;

	r++;	// r을 하나 증가
	cout <<  a << ' ' <<  r << endl;

	r = b;	// r에 b 대입
	cout <<  a << ' ' <<  r << endl;

	cout << &a << ' ' << &r << endl;   // 주소 출력
}