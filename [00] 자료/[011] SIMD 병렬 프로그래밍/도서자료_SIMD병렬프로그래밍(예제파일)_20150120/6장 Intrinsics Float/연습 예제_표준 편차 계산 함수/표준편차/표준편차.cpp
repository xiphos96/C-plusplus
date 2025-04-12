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
	//������ ���Ѵ�.
	int i = 0;
	for(  i = 0; i < Size; i++)
	{
		Sum += Array[i];
	}
	//��հ��� ����Ѵ�.
	float Average = Sum / Size;

	float DistValue = 0;
	float SumDist = 0;

	//(���-���)�� ���� ���� ���Ѵ�.
	for( i = 0; i < Size; i++)
	{
		DistValue = Average-Array[i];
		SumDist += DistValue*DistValue;
	}
	//������ ���� ����
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
		xmmCur = _mm_loadu_ps( Array+i );	//4���� �������� �о� ���δ�.
		xmmSum = _mm_add_ps( xmmSum, xmmCur );	//4���� �������� ���Ѵ�.
	}
	
	//���� 4���� ���� �ϳ��� ���Ѵ�.
	xmmResult = _mm_shuffle_ps(xmmResult, xmmSum, 0x40);
	xmmSum = _mm_add_ps(xmmSum, xmmResult);
	xmmResult = _mm_shuffle_ps(xmmResult, xmmSum, 0x30);
	xmmSum = _mm_add_ps(xmmSum, xmmResult);
	xmmSum = _mm_shuffle_ps(xmmSum, xmmSum, 2);
	_mm_store_ss (&Sum, xmmSum);

	//4��� �� �̿��� ������ ���� ���Ѵ�.
	for( i = LoopSize ; i < Size; i++)
	{
		Sum += Array[i];
	}

	float Average = Sum/Size;

	//���� ����� ���� 4�� ��� �����͸� �����.
	__m128 xmmAVG = _mm_set1_ps( Average );
	
	__m128 xmmDistribution = _mm_setzero_ps();
	__m128 xmmSumDist = _mm_setzero_ps();
	
	for(  i = 0; i < LoopSize; i+=4)
	{
		xmmCur = _mm_loadu_ps( Array+i );	//4���� �������� �о� ���δ�.
		xmmDistribution = _mm_sub_ps( xmmAVG, xmmCur );	//��հ����� ����.
		xmmDistribution = _mm_mul_ps(xmmDistribution,xmmDistribution);	//������ ���Ѵ�.
		xmmSumDist = _mm_add_ps(xmmSumDist,xmmDistribution);	//���� �������� ���Ѵ�.
	}

	xmmResult = _mm_setzero_ps();
	Sum = 0;

	//���� 4���� ���� �ϳ��� ���Ѵ�.
	xmmResult = _mm_shuffle_ps(xmmResult, xmmSumDist, 0x40);
	xmmSumDist = _mm_add_ps(xmmSumDist, xmmResult);
	xmmResult = _mm_shuffle_ps(xmmResult, xmmSumDist, 0x30);
	xmmSumDist = _mm_add_ps(xmmSumDist, xmmResult);
	xmmSumDist = _mm_shuffle_ps(xmmSumDist, xmmSumDist, 2);
	_mm_store_ss (&Sum, xmmSumDist);

	//������ ���� ���Ѵ�.
	for( i = LoopSize; i < Size; i++)
	{
		Sum += (Average-Array[i])*(Average-Array[i]);
	}

	//�������� �����Ѵ�.
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

