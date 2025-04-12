// 5-9.cpp

#include <iostream.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
inline int max(int x, int y) { return (x > y) ? x: y; }

void main()
{
	int i, j, M;
	
	i = 123;
	j = 456;
	M = MAX(i++, j++);
	cout << i << ' ' << j << ' ' << M << endl;
	
	i = 123;
	j = 456;
	M = max(i++, j++);
	cout << i << ' ' << j << ' ' << M << endl;
}