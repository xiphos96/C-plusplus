// Pack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) int A[4] = {1,2,3,4};
	__declspec(align(16)) int B[4] = {5,6,7,8};
	__declspec(align(16)) short R[8] = {0};
	
	__m128i xmmA = _mm_load_si128((__m128i*)A);
	__m128i xmmB = _mm_load_si128((__m128i*)B);
	
	__m128i xmmR = _mm_packs_epi32(xmmA,xmmB);	//pack 연산
	
	_mm_store_si128((__m128i*)R,xmmR);		//결과 출력
	printf("Pack : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	
	return 0;
}
