// comp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) short A[8] = {1,0,1,0,1,0,1,0};
	__declspec(align(16)) short B[8] = {1,1,2,1,0,0,0,-1};
	__declspec(align(16)) short R[8] = {0};
	
	__m128i xmmA = _mm_load_si128((__m128i*)A);
	__m128i xmmB = _mm_load_si128((__m128i*)B);
	
	__m128i xmmR = _mm_cmpeq_epi16(xmmA,xmmB);	//Equality 연산 ==
	
	_mm_store_si128((__m128i*)R,xmmR);		//결과 출력
	printf("Equality : %x, %x, %x, %x, %x, %x, %x, %x\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_cmpgt_epi16(xmmA,xmmB);	//Greater Than 연산 >
	
	_mm_store_si128((__m128i*)R,xmmR);		//결과 출력
	printf("Greater Than : %x, %x, %x, %x, %x, %x, %x, %x\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_cmplt_epi16(xmmA,xmmB);	//Less Than 연산 <
	
	_mm_store_si128((__m128i*)R,xmmR);		//결과 출력
	printf("Less Than : %x, %x, %x, %x, %x, %x, %x, %x\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	
	return 0;
}

