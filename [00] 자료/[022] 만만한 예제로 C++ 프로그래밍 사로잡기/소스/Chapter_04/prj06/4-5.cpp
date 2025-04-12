// 4-5.cpp

#include <iostream.h>
#include "4-5.h"
#include "4-4.h"

D::D(int n)
{
	m = n;
}

void D::g(C c)
{
	cout << "D::g()\n";
	D temp(m);
	c.f(temp);
}

void main()
{
	C cobj("Hi");
	D dobj(5);
 	dobj.g(cobj);
}