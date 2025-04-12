// FindInt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "memory.h"
#include "StopWatch.h"

int FindValueCountC(const int *pIntArray,const int nFindValue,const int nSize)
{
	int nFindCount = 0;
	for(int i = 0; i< nSize ; i++)
	{
		if(pIntArray[i] == nFindValue)
			nFindCount++;
	}
	return nFindCount;
}

int FindValueCountSIMD(const int *pIntArray,const int nFindValue,const int nSize)
{
	const int* pInt = pIntArray;

	int nLoopCount = (nSize / 4)*16;
	int nRemain = nSize % 4;

	int pFindMask[4] = {0};

	for(int j= 0; j < 4; j++)
	{
		pFindMask[j] = nFindValue;
	}

	int nFindCount = 0;

	__asm
	{
		pushad
		mov eax, pInt
		mov edx, 0
		mov esi, 0
		mov ecx, nLoopCount

		movupd xmm5, pFindMask

FINDLOOP:
		movupd xmm0, [eax+esi]

		pcmpeqd xmm0, xmm5

		pmovmskb ebx, xmm0

		cmp ebx, 0
		je NOTCOUNT
		inc edx
NOTCOUNT:

		add esi, 16
		cmp esi, ecx
		jne FINDLOOP

		mov nFindCount, edx
		popad
		
	}

	if( nRemain != 0)
	{
		for( int i = nSize-nRemain; i< nSize; i++)
		{
			if(pIntArray[i] == nFindValue )
				nFindCount++;
		}
	}


	return nFindCount;
}

int main(int argc, char* argv[])
{
	CStopWatch StopWatch;
	const int MAX_SIZE = 10000000;

	int* pIntArray = new int[MAX_SIZE];
	memset( pIntArray, 0x00, MAX_SIZE*sizeof(int));
	pIntArray[0] = 100;
	pIntArray[1000000] = 100;
	pIntArray[2000000] = 100;
	pIntArray[3000000] = 100;
	pIntArray[4000000] = 100;
	pIntArray[5000000] = 100;
	pIntArray[6000000] = 100;
	pIntArray[7000000] = 100;
	pIntArray[8000000] = 100;
	pIntArray[9000000] = 100;

	int nResult = 0;

	StopWatch.Start();
	nResult = FindValueCountSIMD(pIntArray,100,MAX_SIZE);
	StopWatch.End();

	printf("SIMD Find Count : %d, Time : %f \n", nResult, StopWatch.GetDurationMilliSecond());

	StopWatch.Start();
	nResult = FindValueCountC(pIntArray,100,MAX_SIZE);
	StopWatch.End();

	printf("C Find Count : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());


	delete[] pIntArray;

	return 0;
}

