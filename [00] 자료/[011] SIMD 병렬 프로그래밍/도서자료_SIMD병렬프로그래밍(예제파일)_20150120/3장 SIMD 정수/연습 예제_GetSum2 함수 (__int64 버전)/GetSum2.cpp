// FindShortPosition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "memory.h"
#include "StopWatch.h"

__int64 GetSumValueC(const int *pIntArray, const int nSize)
{
	__int64 SumValue = 0;
    int i = 0;
	for( i = 0; i< nSize ; i++)
	{
		SumValue += pIntArray[i];
	}
	return SumValue;
}

__int64 GetSumValueSIMD(const int *pIntArray, const int nSize)
{
	const int* pInt = pIntArray;
	
	int nLoopCount = (nSize / 4)*16 ;
	int nRemain = nSize % 4;
	
	__int64 nSumValue = 0;
	__int64 SumValueArray[2] ={0};

	__asm
	{
		pushad
		mov eax, pInt
		mov esi, 0
		mov ecx, nLoopCount
		pxor xmm6, xmm6		
		pxor xmm7, xmm7
		
			
FINDLOOP:
		movdqu xmm0, [eax+esi]
		movdqu xmm1, xmm0

		punpckhdq xmm1, xmm6
		paddq xmm7, xmm1

		punpckldq xmm0, xmm6
		paddq xmm7, xmm0
		
		add esi, 16
		cmp esi, ecx
		jnz FINDLOOP
		
		movdqu xmm5, xmm7
		psrldq xmm5, 8
		paddq xmm7, xmm5

		movdqu SumValueArray, xmm7
		
		popad
		
	}
	
//	for( unsigned char Count = 0; Count < 2 ; Count++)
//		nSumValue += SumValueArray[Count];
	nSumValue = SumValueArray[0];
	
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
		pIntArray[i] = i;

	__int64 nResultC = 0;
	__int64 nResultSIMD = 0;
	
	StopWatch.Start();
	nResultC = GetSumValueC(pIntArray,MAX_SIZE);
	StopWatch.End();
	
	printf("C Time : %f \n",StopWatch.GetDurationMilliSecond());
	
	StopWatch.Start();
	nResultSIMD = GetSumValueSIMD(pIntArray,MAX_SIZE);
	StopWatch.End();
	
	printf("SIMD Time : %f \n",StopWatch.GetDurationMilliSecond());
	if(nResultC == nResultSIMD)
		printf("Result OK \n" );

	delete[] pIntArray;
	
	return 0;
}

