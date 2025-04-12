// 3-3.cpp

#include <iostream.h>

int max(int a, int b) { 	return (a>b)? a : b;  }	// 전역 함수

class C {
	int a, b;
public:
	C(int a, int b);
	int max();
};

C::C(int a, int b)	// 클래스 범위 지정
{
	C::a = a;	// 클래스 멤버와 형식 인자를 구별
	C::b = b;
}

int C::max() 		// 클래스 범위 지정
{
	return ::max(a, b);	// 전역 함수 max(행 5) 지정, a, b는 클래스 멤버
}

void main()
{
	C	obj(10, 20);	// C 타입의 객체 obj 생성
	cout << obj.max() << endl;
}