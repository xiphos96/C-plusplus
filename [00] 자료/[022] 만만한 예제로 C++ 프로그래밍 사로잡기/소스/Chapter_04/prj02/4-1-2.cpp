// 4-1-2.cpp 

#include <iostream.h>

class C {
	int id;
public:
	C(int i);
	~C();
};

C::C(int i)
{
	id = i;
	cout << "객체(" << id << ") 생성\n";
}

C::~C()
{
	cout << "객체(" << id << ") 소멸\n";
}

C gobj(1);		// 전역 객체

void f()
{
	cout << "	함수 f() 시작\n";
	static C sobj(2);				
	C fobj(3);
	cout << "	&sobj = " << (unsigned long)(&sobj) << endl;
	cout << "	&fobj = " << (unsigned long)(&fobj) << endl;
	cout << "	함수 f() 끝\n";
}

void main()
{
	cout << "	함수 main() 시작\n";
	C mobj(4);
	C *pobj = new C(5);
	cout << "	&main = " << (unsigned long)(&main) << endl;
	cout << "	&f    = " << (unsigned long)(&f) << endl;
	cout << "	&gobj = " << (unsigned long)(&gobj) << endl;
	cout << "	&mobj = " << (unsigned long)(&mobj) << endl;
	cout << "	&pobj = " << (unsigned long)(&pobj) << endl;
	cout << "	pobj  = " << (unsigned long)(pobj) << endl;
	f();
	delete pobj;
	cout << "	함수 main() 끝\n";
}