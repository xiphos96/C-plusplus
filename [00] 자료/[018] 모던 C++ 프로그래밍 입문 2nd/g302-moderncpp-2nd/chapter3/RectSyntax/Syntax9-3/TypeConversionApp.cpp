#include "String.h"
#include <iostream>
using std::cout; using std::endl;

int main()
{
	String str1("eum");
	const char* name = "doohun";
	// 기본 데이터 타입에서 클래스 타입으로 변환 후 배정
	String str2 = name;       // str2 = String(name);
	// 클래스 타입에서 기본 데이터 타입으로 변환
	char* c1 = str1;
	char* c2 = str2;
	cout << c1 << c2 << endl;
	String str3 = "kimyoungmi";
	if (str3 == String("kimyoungmi"))
		cout << str3 << endl;

	return 0;
}