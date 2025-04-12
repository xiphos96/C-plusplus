// Logical.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) short A[8] = {1,0,1,0,1,0,1,0};
	__declspec(align(16)) short B[8] = {1,1,1,1,0,0,0,0};
	__declspec(align(16)) short R[8] = {0};

	printf("Source A : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,A[7],A[6],A[5],A[4],A[3],A[2],A[1],A[0]);
	printf("Source B : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,B[7],B[6],B[5],B[4],B[3],B[2],B[1],B[0]);

	
	__m128i xmmA = _mm_load_si128((__m128i*)A);
	__m128i xmmB = _mm_load_si128((__m128i*)B);

	__m128i xmmR = _mm_and_si128(xmmA,xmmB);	//AND 연산

	_mm_store_si128((__m128i*)R,xmmR);		//결과 출력
	printf("AND : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_or_si128(xmmA,xmmB);	//OR 연산
	
	_mm_store_si128((__m128i*)R,xmmR);		//결과 출력
	printf("OR : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_xor_si128(xmmA,xmmB);	//XOR 연산
	
	_mm_store_si128((__m128i*)R,xmmR);		//결과 출력
	printf("XOR : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_andnot_si128(xmmA,xmmB);	//ANDNOT 연산
	
	_mm_store_si128((__m128i*)R,xmmR);		//결과 출력
	printf("ANDNOT : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);

	return 0;
}
