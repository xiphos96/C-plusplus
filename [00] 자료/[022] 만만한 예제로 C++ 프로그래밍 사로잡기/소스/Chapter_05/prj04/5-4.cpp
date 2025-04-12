// 5-4.cpp

#include <iostream.h>

int max(int a, int b) {	return a > b ? a : b; }

int min(int a, int b) {	return a < b ? a : b; }

void main()
{
	int a = 100, b = 200;
	int (*pf)(int, int);		// 함수에 대한 포인터

	pf = &max;
	cout << pf(a, b) << ' ' << (*pf)(a, b) << endl;
	
	pf = max;
	cout << pf(a, b) << ' ' << (*pf)(a, b) << endl;
	
	pf = &min;
	cout << pf(a, b) << ' ' << (*pf)(a, b) << endl;
	
	pf = min;
	cout << pf(a, b) << ' ' << (*pf)(a, b) << endl;

	int (*apf[])(int, int) = { max, min };
	
	cout << apf[0](a, b) << ' ' << apf[1](a,b) << endl;
	cout << (*apf[0])(a, b) << ' ' << (*apf[1])(a,b) << endl;
}