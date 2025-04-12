// FloatScalarSquare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "emmintrin.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) float A[4] = {4,3,2,1};
	__declspec(align(16)) float B[4] = {1,2,1,2};
	
	__declspec(align(16)) float Result[4] = {0};
	
	__m128 mA =	_mm_load_ps(A);
	__m128 mB =	_mm_load_ps(B);
	
	__m128 mResult = _mm_sqrt_ss(mA);
	
	_mm_store_ps(Result,mResult);
	
	printf("Sqrt Result : %f, %f, %f, %f \n", 
		Result[0], Result[1], Result[2], Result[3]);
	
	mResult = _mm_rcp_ss(mA);
	
	_mm_store_ps(Result,mResult);
	
	printf("Rcp Result : %f, %f, %f, %f \n", 
		Result[0], Result[1], Result[2], Result[3]);
	
	mResult = _mm_rsqrt_ss(mA);
	
	_mm_store_ps(Result,mResult);
	
	printf("rsqrt Result : %f, %f, %f, %f \n", 
		Result[0], Result[1], Result[2], Result[3]);
	
	mResult = _mm_min_ss(mA,mB);
	
	_mm_store_ps(Result,mResult);
	
	printf("Min Result : %f, %f, %f, %f \n", 
		Result[0], Result[1], Result[2], Result[3]);
	
	mResult = _mm_max_ss(mA,mB);
	
	_mm_store_ps(Result,mResult);
	
	printf("Max Result : %f, %f, %f, %f \n", 
		Result[0], Result[1], Result[2], Result[3]);
	
	return 0;
}
