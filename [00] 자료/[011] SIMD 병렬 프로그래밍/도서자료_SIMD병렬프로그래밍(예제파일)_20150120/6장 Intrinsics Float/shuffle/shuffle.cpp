// shuffle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>
	
int main(int argc, char* argv[])
{
	__declspec(align(16)) float A[4] = {1.0,2.0,3.0,4.0};
	__declspec(align(16)) float B[4] = {5.0,6.0,7.0,8.0};

	__declspec(align(16)) float R[4] = {0};
	
	
	__m128 xmmA = _mm_load_ps(A);		//Align 입력
	__m128 xmmB = _mm_load_ps(B);		//Align 입력

	__m128 xmmR = _mm_shuffle_ps(xmmA,xmmB,_MM_SHUFFLE(1,0,3,2));	//Shuffle
	
	_mm_store_ps(R,xmmR);		//결과 출력
	printf("Shuffle : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);

	xmmR = _mm_unpacklo_ps(xmmA, xmmB);

	_mm_store_ps(R,xmmR);		//결과 출력
	printf("unpack low : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);

	xmmR = _mm_unpackhi_ps(xmmA, xmmB);
	
	_mm_store_ps(R,xmmR);		//결과 출력
	printf("unpack high : %.3f, %.3f, %.3f, %.3f\n"
		,R[3],R[2],R[1],R[0]);
	
	return 0;
}
