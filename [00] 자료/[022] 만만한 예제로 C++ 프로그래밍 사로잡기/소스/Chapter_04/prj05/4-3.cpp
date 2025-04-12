// 4-3.cpp

#include <iostream.h>

void main()
{
	double a[2*2] = { 1, 2, 3, 4 }, b[2*2] = { 5, 6, 7, 8 }, c[2*2];

	for (int i=0; i<2; i++)
	{
		for (int j=0; j<2; j++)
		{
			double sum = 0;
			for (int k=0; k<2; k++)
			{
				sum += a[i*2+k]*b[k*2+j];
			}
			int pos = i*2+j;
			c[pos] = sum;
		}
	}

	cout << "Çà·ÄÀÇ °ö:\n";

	for (i=0; i<4; i++)
		cout << c[i] << ' ';
}