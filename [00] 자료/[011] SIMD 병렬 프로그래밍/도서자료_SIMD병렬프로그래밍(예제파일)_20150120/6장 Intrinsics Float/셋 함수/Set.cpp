// Set.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{

	__declspec(align(16)) float R[4] = {0};
	
	
	__m128 xmmR = _mm_set_ps(4.0, 3.0, 2.0, 1.0);		//set 입력
	
	_mm_store_ps(R,xmmR);		//결과 출력
	printf("Set : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);

	xmmR = _mm_set1_ps(5.0);		//set1 입력
	
	_mm_store_ps(R,xmmR);		//결과 출력
	printf("Set1 : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);

	
	xmmR = _mm_setr_ps(9.0,8.0,7.0,6.0);		//setr 입력
	
	_mm_store_ps(R,xmmR);		//결과 출력
	printf("Setr : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);

	xmmR = _mm_setzero_ps();		//set zero
	
	_mm_store_ps(R,xmmR);		//결과 출력
	printf("Set zero : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);

	return 0;
}
