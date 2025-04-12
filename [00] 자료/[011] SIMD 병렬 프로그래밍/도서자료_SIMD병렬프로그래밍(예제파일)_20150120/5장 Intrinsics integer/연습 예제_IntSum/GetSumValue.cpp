// GetSumValue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StopWatch.h"
#include <emmintrin.h>

int GetSumValueC(const int *pIntArray, const int nSize)
{
	int SumValue = 0;
	for(int i = 0; i< nSize ; i++)
	{
		SumValue += pIntArray[i];
	}
	return SumValue;
}

int GetSumValueSIMD(const int *pIntArray, const int nSize)
{
	const int* pInt = pIntArray;
	
	int nLoopCount = (nSize / 4)*16 ;
	int nRemain = nSize % 4;
	
	int nSumValue = 0;
	
	int SumValueArray[4] ={0};
	__asm
	{
		pushad
		mov eax, pInt
		mov esi, 0
		mov ecx, nLoopCount
		
		pxor xmm1, xmm1
			
FINDLOOP:
		movupd xmm0, [eax+esi]
		paddd xmm1, xmm0
		
		add esi, 16
		cmp esi, ecx
		jnz FINDLOOP
		
		movupd SumValueArray, xmm1
		
		popad
		
	}
	
	for( unsigned char Count = 0; Count < 4 ; Count++)
		nSumValue += SumValueArray[Count];
	
	if( nRemain != 0)
	{
		for( int i = nSize-nRemain; i< nSize; i++)
			nSumValue += pIntArray[i];
	}
	
	return nSumValue;
}

int GetSumValueIntrinsics(const int *pIntArray, const int nSize)
{

	int nRemain = nSize % 4;
	int nLoopCount = nSize - nRemain ;

	int nSumValue = 0;
	int SumValueArray[4] ={0};
	
	__m128i XMMCurrentValue;
	__m128i XMMSumValue = _mm_setzero_si128();		//0으로 초기화
	
	for(unsigned int Index =0 ; Index < nLoopCount; Index+=4)
	{
		XMMCurrentValue = _mm_loadu_si128((__m128i*)(pIntArray+Index));		//16byte 씩 읽어온다.
		
		XMMSumValue = _mm_add_epi32(XMMSumValue, XMMCurrentValue);			//16byte 씩 더한다.
	}
	
	_mm_storeu_si128((__m128i*)SumValueArray,XMMSumValue);
	
	for( unsigned char Count = 0; Count < 4 ; Count++)
		nSumValue += SumValueArray[Count];
	
	if( nRemain != 0)
	{
		for( int i = nSize-nRemain; i< nSize; i++)
			nSumValue += pIntArray[i];
	}
	
	return nSumValue;
}

int main(int argc, char* argv[])
{
	CStopWatch StopWatch;
	const int MAX_SIZE = 10000000;
	
	int* pIntArray = new int[MAX_SIZE];
	memset( pIntArray, 0x00, MAX_SIZE*sizeof(int));
	for(int i = 0; i < MAX_SIZE; i++)
		pIntArray[i] = 1;
	int nResult = 0;
	
	StopWatch.Start();
	nResult = GetSumValueC(pIntArray,MAX_SIZE);
	StopWatch.End();
	
	printf("C Get Value : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());
	
	StopWatch.Start();
	nResult = GetSumValueIntrinsics(pIntArray,MAX_SIZE);
	StopWatch.End();
	
	printf("Intrinsics Get Value : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());
	
	StopWatch.Start();
	nResult = GetSumValueSIMD(pIntArray,MAX_SIZE);
	StopWatch.End();
	
	printf("SIMD Get Value : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());
	delete[] pIntArray;
	
	return 0;
}