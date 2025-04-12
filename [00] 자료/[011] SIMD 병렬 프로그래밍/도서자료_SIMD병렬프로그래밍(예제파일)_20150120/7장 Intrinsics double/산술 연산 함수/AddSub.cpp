// AddSub.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	
	__declspec(align(16)) double A[2] = {1.0,2.0};
	__declspec(align(16)) double B[2] = {3.0,4.0};
	
	__declspec(align(16)) double R[2] = {0};
	
	__m128d xmmA = _mm_load_pd( A );		//A 읽기
	__m128d xmmB = _mm_load_pd( B );		//B 읽기
	
	__m128d xmmR = _mm_add_pd( xmmA, xmmB);		//add
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("Add : %.3f, %.3f\n"	,R[1],R[0]);
	
	xmmR = _mm_sub_pd( xmmA, xmmB);		//sub
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("Sub : %.3f, %.3f\n"	,R[1],R[0]);
	
	xmmR = _mm_mul_pd( xmmA, xmmB);		//mul
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("Mul : %.3f, %.3f\n"	,R[1],R[0]);
	
	xmmR = _mm_div_pd( xmmA, xmmB);		//div
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("Div : %.3f, %.3f\n"	,R[1],R[0]);
	
	xmmR = _mm_min_pd( xmmA, xmmB);		//min
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("Min : %.3f, %.3f\n"	,R[1],R[0]);
	
	xmmR = _mm_max_pd( xmmA, xmmB);		//max
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("Max : %.3f, %.3f\n"	,R[1],R[0]);
	
	xmmR = _mm_sqrt_pd( xmmA);		//sqrt
	
	_mm_store_pd(R,xmmR);		//결과 출력
	printf("sqrt : %.3f, %.3f\n"	,R[1],R[0]);
	
	
	
	return 0;
}


