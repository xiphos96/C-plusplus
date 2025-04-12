// FindShortPosition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "memory.h"
#include "StopWatch.h"
#include <emmintrin.h>
//#include <algorithm>

short GetMaxValueC(const short *pShortArray,const int nSize)
{
	short MaxValue = 0;
	for(int i = 0; i< nSize ; i++)
	{
		if(pShortArray[i] > MaxValue )
			MaxValue = pShortArray[i];

	}
	return MaxValue;
}

short GetMaxValueSIMD(const short *pShortArray, const int nSize)
{
	const short* pShort = pShortArray;
	
	int nLoopCount = (nSize / 8)*16;
	int nRemain = nSize % 8;
	
	short nMaxValue = 0;

	short MaxValueArray[8] ={0};
	__asm
	{
		pushad
		mov eax, pShort
		mov esi, 0
		mov ecx, nLoopCount
		
		pxor xmm1, xmm1
			
FINDLOOP:
		movupd xmm0, [eax+esi]
		pmaxsw xmm1, xmm0
		

		add esi, 16
		cmp esi, ecx
		jne FINDLOOP

		movupd MaxValueArray, xmm1

		popad
		
	}

	for( unsigned char Count = 0; Count < 8 ; Count++)
	{
		if( MaxValueArray[Count] > nMaxValue )
			nMaxValue = MaxValueArray[Count];
	}
	
	if( nRemain != 0)
	{
		for( int i = nSize-nRemain; i< nSize; i++)
		{
			if(pShortArray[i] > nMaxValue )
				nMaxValue = pShortArray[i];
		}
	}
	
	
	return nMaxValue;
}

short GetMaxValueIntrinsic(const short *pShortArray, const int nSize)
{
	const short* pShort = pShortArray;
	
	int nRemain = nSize % 8;
	
	short nMaxValue = 0;
	
	short MaxValueArray[8] ={0};

	__m128i XMMCurrentValue;
	__m128i XMMMaxValue;

	for(unsigned int Index =0 ; Index < nSize; Index+=8)
	{
		XMMCurrentValue = _mm_loadu_si128((__m128i*)(pShortArray+Index));		//16byte 씩 읽어온다.
		
		XMMMaxValue = _mm_max_epi16(XMMMaxValue, XMMCurrentValue);			//16byte 씩 더한다.
	}
	
	_mm_storeu_si128((__m128i*)MaxValueArray,XMMMaxValue);

	for( unsigned char Count = 0; Count < 8 ; Count++)
	{
		if( MaxValueArray[Count] > nMaxValue )
			nMaxValue = MaxValueArray[Count];
	}
	
	if( nRemain != 0)
	{
		for( int i = nSize-nRemain; i< nSize; i++)
		{
			if(pShortArray[i] > nMaxValue )
				nMaxValue = pShortArray[i];
		}
	}
	
	
	return nMaxValue;
}

int main(int argc, char* argv[])
{
	CStopWatch StopWatch;
	const int MAX_SIZE = 100000002;
	
	short* pShortArray = new short[MAX_SIZE];
	memset( pShortArray, 0x00, MAX_SIZE*sizeof(short));

	pShortArray[9000003] = 100;

	int nResult = 0;
	
	StopWatch.Start();
	nResult = GetMaxValueC(pShortArray,MAX_SIZE);
	StopWatch.End();
	
	printf("C Get Value : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());
			
	StopWatch.Start();
	nResult = GetMaxValueIntrinsic(pShortArray,MAX_SIZE);
	StopWatch.End();
	
	printf("Intrisic Get Value : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());

	StopWatch.Start();
	nResult = GetMaxValueSIMD(pShortArray,MAX_SIZE);
	StopWatch.End();
	
	printf("SIMD Get Value : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());

	delete[] pShortArray;

	return 0;
}

