// 3-3.cpp

#include <iostream.h>

int max(int a, int b) { 	return (a>b)? a : b;  }	// ���� �Լ�

class C {
	int a, b;
public:
	C(int a, int b);
	int max();
};

C::C(int a, int b)	// Ŭ���� ���� ����
{
	C::a = a;	// Ŭ���� ����� ���� ���ڸ� ����
	C::b = b;
}

int C::max() 		// Ŭ���� ���� ����
{
	return ::max(a, b);	// ���� �Լ� max(�� 5) ����, a, b�� Ŭ���� ���
}

void main()
{
	C	obj(10, 20);	// C Ÿ���� ��ü obj ����
	cout << obj.max() << endl;
}