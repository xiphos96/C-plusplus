#include "String.h"
#include <iostream>
using std::cout; using std::endl;

int main()
{
	String str1("eum");
	String str2;
	// �̵� ���� ������
	str2 = "doohun";
	// operator+, �̵� ���� ������
	str1 = str1 + str2;
	cout << str1 << endl;

	return 0;
}