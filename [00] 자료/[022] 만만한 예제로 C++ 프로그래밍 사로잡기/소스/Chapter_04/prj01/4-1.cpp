// 4-1.cpp

#include <iostream.h>

int a=1;		// ���� ����

int f(int a);	// �Լ� ���� ���� 	

class C {
	int a;		// Ŭ���� ����
public:
	C()	{ a = 10; }
	void g();		// Ŭ���� ����
};

void C::g()		// Ŭ���� ��� �Լ�
{
	cout << a << ' ' << ::a << ' ' << f(C::a) << endl;
}

int f(int n)	// �Ϲ�(����) �Լ�
{
	return	n;
}

void main()
{
	int b = 2;	// ���� ����(main �Լ�)
	cout << a << ' ' << b << endl;
	
	{
		int c = 3;	// ���� ����(���� ���)
		cout << a << ' ' << b << ' ' << c << endl;
		goto L;
		cout << "����� ����� ȣ����� ����";
	}

L:		// �Լ� ����
	C obj;
	obj.g();
	cout << f(5) << endl;
}