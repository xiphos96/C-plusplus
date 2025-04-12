// 3-2.cpp

#include <iostream.h>		// 입출력 스트림 클래스를 위한 헤더 파일

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
	cout << "정수 하나를 입력하세요? ";
	cin  >> i;
	cout << "입력한 값은 " << i << " 입니다.\n" << flush;
}