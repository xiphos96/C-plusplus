// 4-2-1.cpp 

#include <iostream.h>

extern int a;		// �������� ����(4-2.cpp�� ���ǵǾ� ����)
static int b = 10;		// ��������(4-2.cpp�� ���������� ����)
extern int f();		// �����Լ� ����(4-2.cpp�� ���ǵǾ� ����)
int g();			// �����Լ� ����(4-2.cpp�� ���ǵǾ� ����)

static int h() {  return ++b; };	//�����Լ� ����

void main()
{
	cout << a << ' ' << b << endl;
	cout << f() << ' ' << g() << ' ' << h() << endl;
	cout << f() << ' ' << g() << ' ' << h() << endl;
}