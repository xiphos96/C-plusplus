// 3-2.cpp

#include <iostream.h>		// ����� ��Ʈ�� Ŭ������ ���� ��� ����

void main( )
{
	int i = 10;
	long l = 123456789L;
	float f = 3.141592F;
	double d = 1.0e-15;
	char c = 'C';
	char *cpp = "C++";

	cout << i << ' ' << l << ' ' << f << ' ' << d << ' ' << endl;
	cout << cpp << " is better than " << c << endl;
	cout << "���� �ϳ��� �Է��ϼ���? ";
	cin  >> i;
	cout << "�Է��� ���� " << i << " �Դϴ�.\n" << flush;
}