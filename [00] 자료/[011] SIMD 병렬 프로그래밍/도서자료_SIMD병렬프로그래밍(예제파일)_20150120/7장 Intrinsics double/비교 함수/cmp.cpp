// cmp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) double A[2] = {1.0,2.0};
	__declspec(align(16)) double B[2] = {1.0,1.0};
	__declspec(align(16)) double C[2] = {1.0,3.0};
	
	__declspec(align(16)) double R[2] = {0};
	
	__m128d xmmA = _mm_load_pd( A );		//A 읽기
	__m128d xmmB = _mm_load_pd( B );		//B 읽기
	__m128d xmmC = _mm_load_pd( C );		//B 읽기
	
	__m128d xmmR = _mm_cmpeq_pd( xmmA, xmmB);		//add
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("equality : %.3f, %.3f\n"	,R[1],R[0]);
	
	xmmR = _mm_cmpgt_pd( xmmA, xmmB);		//sub
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("less than : %.3f, %.3f\n"	,R[1],R[0]);
	
	xmmR = _mm_cmplt_pd( xmmA, xmmC);		//mul
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("greater than : %.3f, %.3f\n"	,R[1],R[0]);
	
	return 0;
}
