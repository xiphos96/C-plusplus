// shuffle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) int A[4] = {1,2,3,4};
	__declspec(align(16)) int R[4] = {0};
	
	__m128i xmmA = _mm_load_si128((__m128i*)A);
	
	__m128i xmmR = _mm_shuffle_epi32(xmmA,157);
	//shuffle 연산 157 == 10011101b;
	
	_mm_store_si128((__m128i*)R,xmmR);		//결과 출력
	printf("Shuffle : %d, %d, %d, %d\n"
		,R[3],R[2],R[1],R[0]);
	
	return 0;
}