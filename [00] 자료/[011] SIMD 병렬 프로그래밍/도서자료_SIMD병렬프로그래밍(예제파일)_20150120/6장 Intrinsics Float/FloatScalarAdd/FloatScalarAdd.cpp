// FloatScalarAdd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "emmintrin.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) float A[4] = {1,2,3,4};
	__declspec(align(16)) float B[4] = {2,1,2,1};
	
	__declspec(align(16)) float Result[4] = {0};
	
	__m128 mA =	_mm_load_ps(A);
	__m128 mB =	_mm_load_ps(B);
	
	__m128 mResult = _mm_add_ss(mA,mB);
	
	_mm_store_ps(Result,mResult);
	
	printf("Scalar Add Result : %f, %f, %f, %f \n", Result[0], Result[1], Result[2], Result[3]);
	
	mResult = _mm_sub_ss(mA,mB);
	
	_mm_store_ps(Result,mResult);
	
	printf("Scalar Sub Result : %f, %f, %f, %f \n", Result[0], Result[1], Result[2], Result[3]);
	
	mResult = _mm_mul_ss(mA,mB);
	
	_mm_store_ps(Result,mResult);
	
	printf("Scalar Mul Result : %f, %f, %f, %f \n", Result[0], Result[1], Result[2], Result[3]);
	
	mResult = _mm_div_ss(mA,mB);
	
	_mm_store_ps(Result,mResult);
	
	printf("Scalar Div Result : %f, %f, %f, %f \n", Result[0], Result[1], Result[2], Result[3]);
	
	return 0;
}

