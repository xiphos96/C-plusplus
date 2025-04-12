// 5-13.cpp

#include <iostream.h>
#include "5-12.h"    // 상수 정의 헤더 파일 포함 

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