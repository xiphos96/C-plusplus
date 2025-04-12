// set.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) double R[2] = {0};
		
	__m128d xmmR = _mm_set_pd( 2.0, 1.0);		//set 입력
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("Set : %.3f, %.3f\n"	,R[1],R[0]);
	
	xmmR = _mm_set1_pd(3.0);		//set1 입력
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("Set1 : %.3f, %.3f\n" ,R[1],R[0]);
	
	xmmR = _mm_setr_pd(5.0, 4.0);		//setr 입력
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("SetR : %.3f, %.3f\n" ,R[1],R[0]);
	
	xmmR = _mm_setzero_pd();		//set zero
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("SetZero : %.3f, %.3f\n" ,R[1],R[0]);
	;
	
	return 0;
}
