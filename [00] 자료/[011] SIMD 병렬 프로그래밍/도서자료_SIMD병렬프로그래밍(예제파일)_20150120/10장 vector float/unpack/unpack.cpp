// unpack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) short A[8] = {1,2,3,4,5,6,7,8};
	__declspec(align(16)) short B[8] = {0};
	__declspec(align(16)) int R[4] = {0};
	
	__m128i xmmA = _mm_load_si128((__m128i*)A);
	__m128i xmmB = _mm_load_si128((__m128i*)B);
	
	__m128i xmmR = _mm_unpackhi_epi16(xmmA,xmmB);	//pack 연산
	
	_mm_store_si128((__m128i*)R,xmmR);		//결과 출력
	printf("Unpack High : %d, %d, %d, %d\n"
		,R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_unpacklo_epi16(xmmA,xmmB);	//pack 연산
	
	_mm_store_si128((__m128i*)R,xmmR);		//결과 출력
	printf("Unpack Low : %d, %d, %d, %d\n"
		,R[3],R[2],R[1],R[0]);
	
	return 0;
}
