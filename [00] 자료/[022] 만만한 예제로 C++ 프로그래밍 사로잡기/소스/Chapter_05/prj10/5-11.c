/* 5-11.c */

#include <stdio.h>

extern const double PI;	 /* ��� ���� */
double f(double);

/* ������ ������ */
double g(double rad)
{
	return rad*180./PI;
}

void main()
{
	double rad = f(30);
	double deg = g(PI);

	printf("30 �� = %g ����\n", rad);
	printf("PI ���� = %g ��\n", deg);
}