#include "String.h"
#include <iostream>
using std::cout; using std::endl;

int main()
{
	String str1("eum");
	const char* name = "doohun";
	// �⺻ ������ Ÿ�Կ��� Ŭ���� Ÿ������ ��ȯ �� ����
	String str2 = name;       // str2 = String(name);
	// Ŭ���� Ÿ�Կ��� �⺻ ������ Ÿ������ ��ȯ
	char* c1 = str1;
	char* c2 = str2;
	cout << c1 << c2 << endl;
	String str3 = "kimyoungmi";
	if (str3 == String("kimyoungmi"))
		cout << str3 << endl;

	return 0;
}