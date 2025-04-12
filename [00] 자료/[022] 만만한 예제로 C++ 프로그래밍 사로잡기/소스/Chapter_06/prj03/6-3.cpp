// 6-3.cpp

#include <iostream.h>

void main()
{
	int a = 123, b = 456;
	int *const p = &a; 

	cout <<  a << ' ' <<  *p << endl;

	a++;	// a를 하나 증가
	cout <<  a << ' ' <<  *p << endl;

	(*p)++;	// *p를 하나 증가
	cout <<  a << ' ' <<  *p << endl;

	*p = b;	// *p에 b 대입
	cout <<  a << ' ' <<  *p << endl;

	cout << &a << ' ' << p << endl;   // 주소 출력
}