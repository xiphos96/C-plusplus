// 5-5.cpp

#include <iostream.h>

void swap(int*, int*);
void swap(char*, char*);
void swap(double*, double*);

void main()
{
	int  i=123, j=456;
	char a='A', b='B';
	double x=123.45, y=678.90;

	cout << "swap() 이전 \n";
	cout << "i = " << i << ", j = " << j << endl;
	cout << "a = " << a << ", b = " << b << endl;
	cout << "x = " << x << ", y = " << y << endl;

	swap(&i, &j);
	swap(&a, &b);
	swap(&x, &y);
	
	cout << "swap() 이후 \n";
	cout << "i = " << i << ", j = " << j << endl;
	cout << "a = " << a << ", b = " << b << endl;
	cout << "x = " << x << ", y = " << y << endl;
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void swap(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

void swap(double *a, double *b)
{
	double t = *a;
	*a = *b;
	*b = t;
}