// convert.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <emmintrin.h>
	
int main(int argc, char* argv[])
{
	__declspec(align(16)) double DoubleA[2] = {1.0,2.0};
	__declspec(align(16)) float FloatA[4] = {3.0,4.0,5.0,6.0};
	__declspec(align(16)) int   IntA[4] = {7,8,9,10};

	__declspec(align(16)) double DoubleR[2] = {-1,-1};
	__declspec(align(16)) float FloatR[4] = {-1,-1,-1,-1};
	__declspec(align(16)) int IntR[4] = {-1,-1,-1,-1};
	
	__m128d dxmmA = _mm_load_pd(DoubleA);		//align 입력

	__m128 fxmmR = _mm_cvtpd_ps(dxmmA);		//double --> float
	
	_mm_store_ps(FloatR,fxmmR);		//결과 출력
	printf("Convert double to float : %.3f, %.3f, %.3f, %.3f\n"
		,FloatR[3],FloatR[2],FloatR[1],FloatR[0]);

	__m128 fxmmA = _mm_load_ps(FloatA);		//align 입력
	
	__m128d dxmmR = _mm_cvtps_pd(fxmmA);	//float --> double
	
	_mm_store_pd(DoubleR,dxmmR);		//결과 출력
	printf("Convert float to double : %.3f, %.3f\n"
		,DoubleR[1],DoubleR[0]);

	
	__m128i ixmmR = _mm_cvtpd_epi32(dxmmA);	//double --> integer
	
	_mm_store_si128((__m128i*)IntR,ixmmR);		//결과 출력
	printf("Convert double to integer : %d, %d, %d, %d\n"
		,IntR[3],IntR[2],IntR[1],IntR[0]);
		
	
	__m128i ixmmA = _mm_load_si128((__m128i*)IntA);		//align 입력

	dxmmR = _mm_cvtepi32_pd(ixmmA);	//integer --> double
	
	_mm_store_pd(DoubleR,dxmmR);		//결과 출력
	printf("Convert integer to double : %.3f, %.3f\n"
		,DoubleR[1],DoubleR[0]);

	;
	return 0;
}


