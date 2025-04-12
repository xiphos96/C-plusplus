// FloatLogical.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "emmintrin.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) float A[4] = {1,1,0,0};
	__declspec(align(16)) float B[4] = {1,0,1,0};
	
	__declspec(align(16)) float Result[4] = {0};
	
	printf("SourceA : %.3f, %.3f, %.3f, %.3f \n",	
		A[3], A[2], A[1], A[0]);

	printf("SourceB : %.3f, %.3f, %.3f, %.3f \n",	
		B[3], B[2], B[1], B[0]);

	__m128 mA =	_mm_load_ps(A);
	__m128 mB =	_mm_load_ps(B);
	
	__m128 mResult = _mm_and_ps(mA,mB);	//AND 연산
	
	_mm_store_ps(Result,mResult);	//결과 출력
	printf("AND Result : %.3f, %.3f, %.3f, %.3f \n",	
		Result[3], Result[2], Result[1], Result[0]);

	mResult = _mm_andnot_ps(mA,mB);	//AND NOT 연산
	
	_mm_store_ps(Result,mResult);	//결과 출력
	printf("ANDNOT Result : %.3f, %.3f, %.3f, %.3f \n", 
		Result[3], Result[2], Result[1], Result[0]);
	
	mResult = _mm_or_ps(mA,mB);	//OR 연산
	
	_mm_store_ps(Result,mResult);	//결과 출력
	printf("OR Result : %.3f, %.3f, %.3f, %.3f \n", 
		Result[3], Result[2], Result[1], Result[0]);
	
	mResult = _mm_xor_ps(mA,mB);	//XOR 연산
	
	_mm_store_ps(Result,mResult);	//결과 출력
	printf("XOR Result : %.3f, %.3f, %.3f, %.3f \n", 
		Result[3], Result[2], Result[1], Result[0]);
		
	return 0;
}


