// DIV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	short nA = 149;
	short nB = 9;
	short nR = nA / nB;
	
	printf("C Div : %d / %d = %d \n", nA, nB, nR);
	
	__declspec(align(16)) short A[8] = {149,149,149,149,149,149,149,149};

	__declspec(align(16)) short R[8] = {0};
	
	__m128i xmmA = _mm_load_si128((__m128i*)A);
	__m128i xmmB = _mm_set1_epi16(256/9);

	xmmA = _mm_mullo_epi16(xmmA,xmmB);
		
	__m128i xmmR = _mm_srai_epi16(xmmA,8);	//shitf 연산
	
	_mm_store_si128((__m128i*)R,xmmR);		//결과 출력
	printf("intrinsic Div : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);

	return 0;
}

