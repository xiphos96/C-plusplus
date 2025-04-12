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
	cout << "��ü(" << id << ") ����\n";
}

C::~C()
{
	cout << "��ü(" << id << ") �Ҹ�\n";
}

C gobj(1);		// ���� ��ü

void f()
{
	cout << "	�Լ� f() ����\n";
	static C sobj(2);				
	C fobj(3);
	cout << "	&sobj = " << (unsigned long)(&sobj) << endl;
	cout << "	&fobj = " << (unsigned long)(&fobj) << endl;
	cout << "	�Լ� f() ��\n";
}

void main()
{
	cout << "	�Լ� main() ����\n";
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
	cout << "	�Լ� main() ��\n";
}