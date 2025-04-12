// comp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>
	
int main(int argc, char* argv[])
{
	__declspec(align(16)) float A[4] = {1.0,2.0,3.0,4.0};
	__declspec(align(16)) float B[4] = {2.0,2.0,2.0,2.0};
	__declspec(align(16)) float R[4] = {0};
	
	
	__m128 xmmA = _mm_load_ps(A);		//Align �Է�
	__m128 xmmB = _mm_load_ps(B);		//Align �Է�
	
	__m128 xmmR = _mm_cmpeq_ps(xmmA,xmmB);	//equality
	
	_mm_store_ps(R,xmmR);		//��� ���
	printf("equality : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_cmpgt_ps(xmmA,xmmB);	//greater than
	
	_mm_store_ps(R,xmmR);		//��� ���
	printf("greater than : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_cmplt_ps(xmmA,xmmB);	//less than
	
	_mm_store_ps(R,xmmR);		//��� ���
	printf("less than : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);
	
	return 0;
}
