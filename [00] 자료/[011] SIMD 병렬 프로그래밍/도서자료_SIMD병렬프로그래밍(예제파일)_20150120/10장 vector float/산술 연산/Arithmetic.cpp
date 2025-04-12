// Arithmetic.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <fvec.h>

int main(int argc, char* argv[])
{
	float pA[4] = {1.1,2.2,3.3,4.4};
	float pB[4] = {4.4,3.3,2.2,1.1};
	float pR[4] = {0};
	
	F32vec4 A;
	F32vec4 B;
	F32vec4 R;
	
	loadu(A, pA);		//pA �޸� �б�
	loadu(B, pB);		//pB �޸� �б�

	R = A + B;			//���� ���
	
	storeu(pR,R);		// ��� ���
	printf("Add : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	R = A - B;			// ���� ���
	
	storeu(pR,R);		// ��� ���
	printf("Sub : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	R = A * B;			// ���� ���
	
	storeu(pR,R);		// ��� ���
	printf("Mul : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	R = A / B;			// ������ ���
	
	storeu(pR,R);		// ��� ���
	printf("Div : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	

	return 0;
}


