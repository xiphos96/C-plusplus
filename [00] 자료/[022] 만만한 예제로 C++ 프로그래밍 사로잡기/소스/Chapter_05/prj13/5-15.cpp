// 5-15.cpp

#include <iostream.h>
#include "5-14.h"

void printClass(const char *name)
{
	int code = getCode(name);

	if	( code/30 )		cout << "��";
	else if ( code/20 )		cout << "������";
	else if ( code/10 )		cout << "Ư����";
	else			cout << "??";
}

void main()
{
	cout << NAME[0]; printClass(NAME[0]); cout << endl;
	cout << NAME[3]; printClass(NAME[3]); cout << endl;
	cout << NAME[8]; printClass(NAME[8]); cout << endl;
	cout << "ȫõ"; printClass("ȫõ");  cout << endl;
}