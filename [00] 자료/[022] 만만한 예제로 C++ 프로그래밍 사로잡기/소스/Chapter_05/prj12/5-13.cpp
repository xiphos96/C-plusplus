// 5-13.cpp

#include <iostream.h>
#include "5-12.h"    // ��� ���� ��� ���� ���� 

double g(double rad)
{
	return rad*180./PI;
}

void main()
{
	double rad = f(30); 
	double deg = g(PI);

	cout << "30 �� = " << rad << " ����" << endl;
	cout << "PI ���� = " << deg << " ��" << endl;
}