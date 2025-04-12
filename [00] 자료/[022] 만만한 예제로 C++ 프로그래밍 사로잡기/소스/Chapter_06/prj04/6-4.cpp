// 6-4.cpp

#include <iostream.h>

void swapVal(int, int);
void swapPtr(int*, int*);
void swapRef(int&, int&);

void main()
{
	int  i, j;

	i = 123; j = 456;
	cout << "swapVal() ����\n";
	cout << "i = " << i << ", j = " << j << endl;
	swapVal(i, j);
	cout << "swapVal() ����\n";
	cout << "i = " << i << ", j = " << j << endl;

	i = 123; j = 456;
	cout << "swapPtr() ���� \n";
	cout << "i = " << i << ", j = " << j << endl;
	swapPtr(&i, &j);
	cout << "swapPtr() ���� \n";
	cout << "i = " << i << ", j = " << j << endl;

	i = 123; j = 456;
	cout << "swapRef() ���� \n";
	cout << "i = " << i << ", j = " << j << endl;
	swapRef(i, j);
	cout << "swapRef() ���� \n";
	cout << "i = " << i << ", j = " << j << endl;

}

void swapVal(int a, int b)
{
	int t = a;
	a = b;
	b = t;
}

void swapPtr(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void swapRef(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}