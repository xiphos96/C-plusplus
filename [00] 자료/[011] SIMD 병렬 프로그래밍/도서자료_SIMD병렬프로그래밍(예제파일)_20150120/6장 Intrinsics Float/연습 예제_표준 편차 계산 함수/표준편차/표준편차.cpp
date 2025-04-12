// stdev.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include <emmintrin.h>
#include "fvec.h"
#include <omp.h>
#include "StopWatch.h"

float GetStdev(float* Array, int Size)
{
	float Sum = 0;
	//총합을 구한다.
	int i = 0;
	for(  i = 0; i < Size; i++)
	{
		Sum += Array[i];
	}
	//평균값을 계산한다.
	float Average = Sum / Size;

	float DistValue = 0;
	float SumDist = 0;

	//(평균-요소)의 제곱 합을 구한다.
	for( i = 0; i < Size; i++)
	{
		DistValue = Average-Array[i];
		SumDist += DistValue*DistValue;
	}
	//제곱근 값을 리턴
	return sqrt(SumDist/Size);
}

float GetStdevIntrinsic(float* Array, int Size)
{
	int LoopSize = (Size/4)*4;

	float Sum = 0;
	float result = 0;
	
	__m128 xmmSum = _mm_setzero_ps();
	__m128 xmmCur = _mm_setzero_ps();
	__m128 xmmResult = _mm_setzero_ps();

	int i = 0;

	for( i = 0; i < LoopSize; i+=4)
	{
		xmmCur = _mm_loadu_ps( Array+i );	//4개씩 연속으로 읽어 들인다.
		xmmSum = _mm_add_ps( xmmSum, xmmCur );	//4개씩 누적합을 구한다.
	}
	
	//병렬 4개의 합을 하나로 구한다.
	xmmResult = _mm_shuffle_ps(xmmResult, xmmSum, 0x40);
	xmmSum = _mm_add_ps(xmmSum, xmmResult);
	xmmResult = _mm_shuffle_ps(xmmResult, xmmSum, 0x30);
	xmmSum = _mm_add_ps(xmmSum, xmmResult);
	xmmSum = _mm_shuffle_ps(xmmSum, xmmSum, 2);
	_mm_store_ss (&Sum, xmmSum);

	//4배수 값 이외의 나머지 값을 더한다.
	for( i = LoopSize ; i < Size; i++)
	{
		Sum += Array[i];
	}

	float Average = Sum/Size;

	//편차 계산을 위해 4개 평균 데이터를 만든다.
	__m128 xmmAVG = _mm_set1_ps( Average );
	
	__m128 xmmDistribution = _mm_setzero_ps();
	__m128 xmmSumDist = _mm_setzero_ps();
	
	for(  i = 0; i < LoopSize; i+=4)
	{
		xmmCur = _mm_loadu_ps( Array+i );	//4개씩 연속으로 읽어 들인다.
		xmmDistribution = _mm_sub_ps( xmmAVG, xmmCur );	//평균값에서 뺀다.
		xmmDistribution = _mm_mul_ps(xmmDistribution,xmmDistribution);	//제곱을 구한다.
		xmmSumDist = _mm_add_ps(xmmSumDist,xmmDistribution);	//편차 누적합을 구한다.
	}

	xmmResult = _mm_setzero_ps();
	Sum = 0;

	//병렬 4개의 합을 하나로 구한다.
	xmmResult = _mm_shuffle_ps(xmmResult, xmmSumDist, 0x40);
	xmmSumDist = _mm_add_ps(xmmSumDist, xmmResult);
	xmmResult = _mm_shuffle_ps(xmmResult, xmmSumDist, 0x30);
	xmmSumDist = _mm_add_ps(xmmSumDist, xmmResult);
	xmmSumDist = _mm_shuffle_ps(xmmSumDist, xmmSumDist, 2);
	_mm_store_ss (&Sum, xmmSumDist);

	//나머지 값을 구한다.
	for( i = LoopSize; i < Size; i++)
	{
		Sum += (Average-Array[i])*(Average-Array[i]);
	}

	//제곱근을 리턴한다.
	return sqrt(Sum/Size);
}

#define ARRAYSIZE 10000
int main(int argc, char* argv[])
{
	CStopWatch StopWatch;
	__declspec(align(16)) float Array[ARRAYSIZE+4] = {0};

	int i =0;

	for(i = 0; i < ARRAYSIZE; i++)
		Array[i] = i;

	float Result = 0;

	StopWatch.Start();
	for(i = 0; i < 10; i++)
		Result = GetStdev(Array,ARRAYSIZE);
	StopWatch.End();

    printf("C Stdev Result : %.3f, %f : Time\n",Result, StopWatch.GetDurationMilliSecond());

	StopWatch.Start();
	for(i = 0; i < 10; i++)
		Result = GetStdevIntrinsic(Array,ARRAYSIZE);
	StopWatch.End();

	printf("Instrinsic Stdev : %.3f, %f : Time\n",Result, StopWatch.GetDurationMilliSecond());

	return 0;
}

