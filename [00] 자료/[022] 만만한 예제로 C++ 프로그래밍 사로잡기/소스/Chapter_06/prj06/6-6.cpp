// 6-6.cpp
	
#include <iostream.h>

int a = 123;		// ���� ����
	
int& f()			// ���۷����� ���� ����
{
	return	a;
}
	
void main()
{
	int i;

	i = f();				// �캯������ ����
	cout << f() << endl;		// �캯������ ����
	f() = 5;				// �º������� ����
	cout << f() << endl;		// �캯������ ����
}