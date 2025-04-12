// 5-2.cpp

#include <iostream.h>

int max(int, int);	// 완전한 함수 원형 

void main()
{
	int i=10, j=20;
	cout << "max = " << max(i, j) << endl;	// 인자 개수 일치
}

int max(int a, int b)	// C++ 스타일
{
	if (a > b)		return	a;
	else			return	b;
}