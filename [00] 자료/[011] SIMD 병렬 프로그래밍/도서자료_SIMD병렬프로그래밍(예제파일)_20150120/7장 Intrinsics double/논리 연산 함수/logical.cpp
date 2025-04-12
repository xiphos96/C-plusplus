// logical.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) double A[2] = {0.0,1.0};
	__declspec(align(16)) double B[2] = {1.0,0.0};
	
	__declspec(align(16)) double R[2] = {0};
	
	__m128d xmmA = _mm_load_pd( A );		//A 읽기
	__m128d xmmB = _mm_load_pd( B );		//B 읽기
	
	__m128d xmmR = _mm_and_pd( xmmA, xmmB);		//and
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("AND : %.3f, %.3f\n"	,R[1],R[0]);
	
	xmmR = _mm_or_pd( xmmA, xmmB);		//or
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("OR : %.3f, %.3f\n"	,R[1],R[0]);
	
	xmmR = _mm_xor_pd( xmmA, xmmB);		//xor
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("XOR : %.3f, %.3f\n"	,R[1],R[0]);
	
	xmmR = _mm_andnot_pd( xmmA, xmmB);		//andnot
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("AND NOT : %.3f, %.3f\n"	,R[1],R[0]);
	
	return 0;
}

