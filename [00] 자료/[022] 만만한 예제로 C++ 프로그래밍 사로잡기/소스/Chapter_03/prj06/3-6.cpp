// 3-6.cpp

#include <iostream.h>

class C {
public:
	int m;
	void f(int i) { m += i; }; 
};

int C::*pm = &C::m;
typedef void (C::*ptr2memberFunc)(int);
ptr2memberFunc pf = &C::f;

void main()
{
	C obj;
	obj.*pm = 100;
	(obj.*pf)(200);
	cout << obj.m << endl;

	C *pt = new C;
	pt->*pm = 300;
	(pt->*pf)(400);
	cout << pt->m << endl;
}