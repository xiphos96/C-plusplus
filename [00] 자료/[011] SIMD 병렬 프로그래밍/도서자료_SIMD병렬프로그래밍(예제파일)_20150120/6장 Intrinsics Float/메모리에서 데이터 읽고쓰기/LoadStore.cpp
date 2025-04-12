// LoadStore.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) float A[4] = {1.0,2.0,3.0,4.0};
	__declspec(align(16)) float R[4] = {0};
	
	
	__m128 xmmA = _mm_load_ps(A);		//Align 입력
	
	_mm_store_ps(R,xmmA);		//결과 출력
	printf("Align Store : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);
	
	float B[4] = {5.0,6.0,7.0,8.0};
	float R2[4] = {0};
	
	__m128 xmmB = _mm_loadu_ps(B);		//Unalign 입력
	
	_mm_storeu_ps(R2,xmmB);		//결과 출력
	printf("Unalign Store : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);
	
	return 0;
}
