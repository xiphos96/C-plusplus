// 6-6.cpp
	
#include <iostream.h>

int a = 123;		// 전역 변수
	
int& f()			// 레퍼런스에 의한 리턴
{
	return	a;
}
	
void main()
{
	int i;

	i = f();				// 우변값으로 쓰임
	cout << f() << endl;		// 우변값으로 쓰임
	f() = 5;				// 좌변값으로 쓰임
	cout << f() << endl;		// 우변값으로 쓰임
}