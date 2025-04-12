// 5-10.cpp

extern const double PI = 3.141592;	 /* 상수  PI 선언 */
// 5-11.cpp

#include <iostream.h>

extern const double PI;	 /* 상수 선언(extern 예약어에 조심) */
double f(double);

double g(double rad)
{
	return rad*180./PI;
}

void main()
{
	double rad = f(30); 
	double deg = g(PI);

	cout << "30 도 = " << rad << " 라디안" << endl;
	cout << "PI 라디안 = " << deg << " 도" << endl;
}

double f(double deg)
{
	return PI*deg/180.;
}