// 5-15.cpp

#include <iostream.h>
#include "5-14.h"

void printClass(const char *name)
{
	int code = getCode(name);

	if	( code/30 )		cout << "µµ";
	else if ( code/20 )		cout << "±¤¿ª½Ã";
	else if ( code/10 )		cout << "Æ¯º°½Ã";
	else			cout << "??";
}

void main()
{
	cout << NAME[0]; printClass(NAME[0]); cout << endl;
	cout << NAME[3]; printClass(NAME[3]); cout << endl;
	cout << NAME[8]; printClass(NAME[8]); cout << endl;
	cout << "È«Ãµ"; printClass("È«Ãµ");  cout << endl;
}