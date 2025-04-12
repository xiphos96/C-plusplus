// FloatAdd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>
	
int main(int argc, char* argv[])
{
	__declspec(align(16)) float A[4] = {1.0,2.0,3.0,4.0};
	__declspec(align(16)) float B[4] = {4.0,3.0,2.0,1.0};
	__declspec(align(16)) float R[4] = {0};
	
	
	__m128 xmmA = _mm_load_ps(A);		//Align �Է�
	__m128 xmmB = _mm_load_ps(B);		//Align �Է�
	
	__m128 xmmR = _mm_add_ps(xmmA,xmmB);	//����
	
	_mm_store_ps(R,xmmR);		//��� ���
	printf("Add : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_sub_ps(xmmA,xmmB);	//����
	
	_mm_store_ps(R,xmmR);		//��� ���
	printf("Sub : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_mul_ps(xmmA,xmmB);	//����
	
	_mm_store_ps(R,xmmR);		//��� ���
	printf("Mul : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_div_ps(xmmA,xmmB);	//������
	
	_mm_store_ps(R,xmmR);		//��� ���
	printf("Div : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);

    xmmR = _mm_max_ps(xmmA,xmmB);	//�ִ�
	
	_mm_store_ps(R,xmmR);		//��� ���
	printf("Max : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);

    xmmR = _mm_min_ps(xmmA,xmmB);	//�ּڰ�
	
	_mm_store_ps(R,xmmR);		//��� ���
	printf("Min : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);
	
	return 0;
}
