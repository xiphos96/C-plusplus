// 3-4.cpp

#include <iostream.h>

int a = 123;				// 전역 범위 변수

void main()
{
	int a = 456;			// main 함수 범위 변수
	cout << a << ' ' << ::a << endl;
	{
		int a = 789;		// 지역 블록 범위 변수
		cout << a << ' ' << ::a << endl;
	}
}