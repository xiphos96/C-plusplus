// Factorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>
#include "StopWatch.h"

double FactorialC( int Input)
{
	double Result = 1;
	for(int i = 1; i <= Input; i++)
		Result *= i;
	return Result;
}

double Factorialintrinsic( int Input)
{
	__declspec(align(16)) double Result[2] = {0};
	__m128d CurValue;
	__m128d SumValue = _mm_set1_pd(1);
	int Looplimit = (Input/2)*2;
	for(int i = 1; i <= Looplimit; i+=2)
	{
		CurValue = _mm_set_pd(i,i+1);
		SumValue = _mm_mul_pd(CurValue,SumValue);
	}
	_mm_store_pd(Result,SumValue);

	if(0==(Input%2))
		return Result[0]*Result[1];
	else
	{
		Result[0]*= Input;
		return Result[0]*Result[1];
	}
}

int main(int argc, char* argv[])
{
	CStopWatch watch;
	int Input = 51;
	double R = 0;
	watch.Start();
	R = Factorialintrinsic(Input);
	watch.End();
	printf("Result : %.f\nIntrinsic Time : %f\n", R, watch.GetDurationMilliSecond());

	watch.Start();
	R = FactorialC(Input);
	watch.End();
	printf("Result : %.f\nC Time : %f\n", R, watch.GetDurationMilliSecond());

	return 0;
}

