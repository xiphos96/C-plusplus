// mov.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{

	__declspec(align(16)) double A[2] = {1.0,2.0};
	__declspec(align(16)) double R[2] = {0};
	
	__m128d xmmA = _mm_load_pd( A );		//A 읽기
	__m128d xmmR = xmmA;
	_mm_store_pd(R, xmmR);		//결과 출력

	printf("aligned Memory : %.3f, %.3f\n"	,R[1],R[0]);

	double B[2] = {3.0,4.0};
	double uR[2] = {0};

	__m128d xmmB = _mm_loadu_pd( B );		//B 읽기
	xmmR = xmmB;
	_mm_storeu_pd(uR, xmmR);		//결과 출력

	printf("Unligned Memory : %.3f, %.3f\n", uR[1], uR[0]);
		
	
	
	return 0;
}

