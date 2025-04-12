// extr.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) short A[8] = {1,2,3,4,5,6,7,8};
	__declspec(align(16)) short R[8] = {0};
	
	__m128i xmmA = _mm_load_si128((__m128i*)A);

	__m128i xmmR = _mm_insert_epi16(xmmA, 10, 3);

	_mm_store_si128((__m128i*)R,xmmR);		//결과 출력
	printf("Result : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);

	int r = _mm_extract_epi16(xmmA, 6);

	printf("Extract Result : %d\n"	,r);

	__declspec(align(16)) char B[16] = {0xff,0,0xff,0,0,0,0,0,0,0,0,0,0,0,0,0};

	__m128i xmmB = _mm_load_si128((__m128i*)B);

	int mask = _mm_movemask_epi8(xmmB);

	printf("Mask = %d\n", mask);

	
	return 0;
}


