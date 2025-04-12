// 4-2-1.cpp 

#include <iostream.h>

extern int a;		// 전역변수 선언(4-2.cpp에 정의되어 있음)
static int b = 10;		// 정적변수(4-2.cpp의 정적변수와 무관)
extern int f();		// 전역함수 선언(4-2.cpp에 정의되어 있음)
int g();			// 전역함수 선언(4-2.cpp에 정의되어 있음)

static int h() {  return ++b; };	//정적함수 정의

void main()
{
	cout << a << ' ' << b << endl;
	cout << f() << ' ' << g() << ' ' << h() << endl;
	cout << f() << ' ' << g() << ' ' << h() << endl;
}