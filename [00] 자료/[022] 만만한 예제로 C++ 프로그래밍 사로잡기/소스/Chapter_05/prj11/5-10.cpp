// 5-10.cpp

extern const double PI = 3.141592;	 /* ���  PI ���� */
// 5-11.cpp

#include <iostream.h>

extern const double PI;	 /* ��� ����(extern ���� ����) */
double f(double);

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

double f(double deg)
{
	return PI*deg/180.;
}