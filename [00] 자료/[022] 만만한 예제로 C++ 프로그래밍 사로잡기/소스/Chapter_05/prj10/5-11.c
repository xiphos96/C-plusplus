/* 5-11.c */

#include <stdio.h>

extern const double PI;	 /* 상수 선언 */
double f(double);

/* 라디안을 각도로 */
double g(double rad)
{
	return rad*180./PI;
}

void main()
{
	double rad = f(30);
	double deg = g(PI);

	printf("30 도 = %g 라디안\n", rad);
	printf("PI 라디안 = %g 도\n", deg);
}