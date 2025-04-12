// FindShortPosition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "memory.h"
#include "StopWatch.h"

int GetSumValueC(const int *pIntArray, const int nSize)
{
	int SumValue = 0;
    int i = 0;
	for( i = 0; i< nSize ; i++)
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
		movdqu xmm0, [eax+esi]
		paddd xmm1, xmm0
		
		add esi, 16
		cmp esi, ecx
		jnz FINDLOOP
		
		movdqu SumValueArray, xmm1
		
		popad
		
	}
	unsigned char Count = 0;
    int i = 0;
	for( Count = 0; Count < 4 ; Count++)
		nSumValue += SumValueArray[Count];
	
	if( nRemain != 0)
	{
		for( i = nSize-nRemain; i< nSize; i++)
			nSumValue += pIntArray[i];
	}
		
	return nSumValue;
}

int main(int argc, char* argv[])
{
	CStopWatch StopWatch;
	const int MAX_SIZE = 10000000;
	int i = 0;
	int* pIntArray = new int[MAX_SIZE];
	memset( pIntArray, 0x00, MAX_SIZE*sizeof(int));
	for( i = 0; i < MAX_SIZE; i++)
		pIntArray[i] = 1;
	int nResult = 0;
	
	StopWatch.Start();
	nResult = GetSumValueC(pIntArray,MAX_SIZE);
	StopWatch.End();
	
	printf("C Get Value : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());
	
	StopWatch.Start();
	nResult = GetSumValueSIMD(pIntArray,MAX_SIZE);
	StopWatch.End();
	
	printf("SIMD Get Value : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());
	
	delete[] pIntArray;
	
	return 0;
}

