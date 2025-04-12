// 4-1.cpp

#include <iostream.h>

int a=1;		// 파일 범위

int f(int a);	// 함수 원형 범위 	

class C {
	int a;		// 클래스 범위
public:
	C()	{ a = 10; }
	void g();		// 클래스 범위
};

void C::g()		// 클래스 멤버 함수
{
	cout << a << ' ' << ::a << ' ' << f(C::a) << endl;
}

int f(int n)	// 일반(전역) 함수
{
	return	n;
}

void main()
{
	int b = 2;	// 지역 범위(main 함수)
	cout << a << ' ' << b << endl;
	
	{
		int c = 3;	// 지역 범위(안쪽 블록)
		cout << a << ' ' << b << ' ' << c << endl;
		goto L;
		cout << "여기는 절대로 호출되지 않음";
	}

L:		// 함수 범위
	C obj;
	obj.g();
	cout << f(5) << endl;
}