// convert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>
	
int main(int argc, char* argv[])
{
	__declspec(align(16)) float FloatA[4] = {1.0,2.0,3.0,4.0};
	__declspec(align(16)) int IntR[4] = {0};

	__declspec(align(16)) int   IntA[4] = {1,2,3,4};
	__declspec(align(16)) float FloatR[4] = {0};
	
	__m128 xmmA = _mm_load_ps(FloatA);		//Align 입력

	__m128i ixmmR = _mm_cvtps_epi32(xmmA);	//float --> integer
	
	_mm_store_si128((__m128i*)IntR,ixmmR);		//결과 출력
	printf("Convert Float to integer : %d, %d, %d, %d\n"
		,IntR[3],IntR[2],IntR[1],IntR[0]);
	
	__m128i ixmmA = _mm_loadu_si128((__m128i*)IntA);		//Align 입력
	
	__m128 xmmR = _mm_cvtepi32_ps(ixmmA);	//integer --> float
	
	_mm_store_ps(FloatR,xmmR);		//결과 출력
	printf("Convert integer to float : %.3f, %.3f, %.3f, %.3f\n"
		,FloatR[3],FloatR[2],FloatR[1],FloatR[0]);

	return 0;
}

