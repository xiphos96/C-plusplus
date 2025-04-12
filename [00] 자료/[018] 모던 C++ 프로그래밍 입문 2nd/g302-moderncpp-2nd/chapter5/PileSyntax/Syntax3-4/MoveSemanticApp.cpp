#include "String.h"
#include <iostream>
using std::cout; using std::endl;

int main()
{
	String str1("eum");
	String str2;
	// 이동 배정 연산자
	str2 = "doohun";
	// operator+, 이동 배정 연산자
	str1 = str1 + str2;
	cout << str1 << endl;

	return 0;
}