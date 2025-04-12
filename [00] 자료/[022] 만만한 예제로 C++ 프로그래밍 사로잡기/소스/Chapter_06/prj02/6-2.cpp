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

	cout << max(a, b) << ' ' << f(a, b) << endl;	// 함수 호출
	cout << &max << ' ' << &f << endl;		// 함수 주소
}