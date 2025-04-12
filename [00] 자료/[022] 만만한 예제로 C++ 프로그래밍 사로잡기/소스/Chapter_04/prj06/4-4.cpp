// 4-4.cpp

#include <string.h>
#include <iostream.h>
#include "4-4.h"
#include "4-5.h"

C::C(char *str)
{
	strcpy(name, str);
}

void C::f(D d)
{
	cout << "C::f()\n";
	cout << name << '-' << d.h() << endl;
}