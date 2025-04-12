// math.cpp : Defines the entry point for the console application.
//
#include "StdAfx.h"
#include "fvec.h"

int main(int argc, char* argv[])
{
	float pA[4] = {1.0,2.0,3.0,4.0};
	float pR[4] = {0};
	
	F32vec4 A;
	F32vec4 R;
	
	loadu(A, pA);		//pA �޸� �б�
	
	R = sqrt( A );			//��Ʈ �� ���
	
	storeu(pR,R);		// ��� ���
	printf("Square Root : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	R = rcp( A );			//�� �м� ���
	
	storeu(pR,R);		// ��� ���
	printf("Reciprocal : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	R = rsqrt( A );			//��Ʈ ���м� �� ���
	
	storeu(pR,R);		// ��� ���
	printf("Reciprocal Square Root : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	R = rcp_nr( A );			//Newton Raphson�� ���м� ���
	
	storeu(pR,R);		// ��� ���
	printf("Reciprocal Newton Raphson : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	R = rsqrt_nr( A );			//Newton Raphson�� ��Ʈ ���м� ���
	
	storeu(pR,R);		// ��� ���
	printf("Reciprocal Square Root Newton Raphson : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	R = add_horizontal( A );			//���� ���� ���
	
	storeu(pR,R);		// ��� ���
	printf("Horizontal Add : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);
	return 0;
}
