// GetSumFloat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fvec.h>
#include "StopWatch.h"

float GetSumFloatVector (F32vec4 *array, int size)
{
	float result = 0;
	F32vec4 vec0, vec1;
	
	int LoopSize = size / 4;
	int Remain = size - (size % 4);
    int i = 1;
	
	vec0 = _mm_load_ps ((float *) array);	//0¹øÂ° load
	
	for( i = 1; i < LoopSize; i++)		//1 ~ LoopSize Sum
		vec0 += array[i];
	
	//4°³ pack sum
	vec1 = _mm_shuffle_ps(vec1, vec0, 0x40);	
	vec0 += vec1;
	vec1 = _mm_shuffle_ps(vec1, vec0, 0x30);
	vec0 += vec1;
	vec0 = _mm_shuffle_ps(vec0, vec0, 2);
	_mm_store_ss (&result, vec0);
	
	for( i = Remain; i < size; i++)
		result += ((float *) array)[i];
	
	return result;
}

float GetSumFloatC (float *array, int size)
{
	float result = 0;
	
	for( int i = 0; i < size; i++)		//1 ~ LoopSize Sum
		result += array[i];
	
	return result;
}

void main(int argc, char *argv[]){

	const int SIZE =5000;

	__declspec(align(16)) float FloatDataArray[SIZE];

	float FloatSum = 0;

	int IntegerSum= 0;

	for (int i=0; i < SIZE; i++)
	{
		FloatDataArray[i] = (float) i;
		IntegerSum += i;
	}
	CStopWatch watch;
	watch.Start();
	float SIMDResult = GetSumFloatVector ((F32vec4 *)FloatDataArray, SIZE);
	watch.End();
	printf ("Vector Sum Result : %f ,Time : %f\n", SIMDResult, watch.GetDurationMilliSecond());

	watch.Start();
	float CResult = GetSumFloatC (FloatDataArray, SIZE);
	watch.End();
	printf ("C Float Sum Result : %f ,Time : %f\n", CResult, watch.GetDurationMilliSecond());

}
