// 5-17.cpp

#include <iostream.h>
#include "5-16.h"

void printClass(const char *name)
{
	int code = getCode(name);

	if	( code/30 )	cout << "��";
	else if ( code/20 )		cout << "������";
	else if ( code/10 )		cout << "Ư����";
	else			cout << "??";
}

void main()
{
	cout << NAME[2]; printClass(NAME[2]); cout << endl;
	cout << NAME[5]; printClass(NAME[5]); cout << endl;
	cout << NAME[11]; printClass(NAME[11]); cout << endl;
}