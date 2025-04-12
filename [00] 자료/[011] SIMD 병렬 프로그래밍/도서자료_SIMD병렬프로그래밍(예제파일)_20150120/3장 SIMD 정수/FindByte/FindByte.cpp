// FindByte.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "memory.h"
#include "StopWatch.h"

int FindValueCountC(char *pCharArray, char nFindValue,int nSize)
{
	short nFindCount = 0;
	for(int i = 0; i< nSize ; i++)
	{
		if(pCharArray[i] == nFindValue)
			nFindCount++;
	}
	return nFindCount;
}

int FindValueCountSIMD(char *pCharArray, char nFindValue,int nSize)
{
	char* pChar = pCharArray;
	
	int nLoopCount = (nSize / 16)*16;
	int nRemain = nSize % 16;
	
	char pFindMask[16] = {0};
	unsigned char ucIndex = 0;
	
	for(unsigned char j= 0; j < 16; j++)
	{
		pFindMask[j] = nFindValue;
	}
	
	int nFindCount = 0;
	
	__asm
	{
		pushad
			mov eax, pChar
			mov edx, 0
			mov esi, 0
			mov ecx, nLoopCount
			
			movdqu xmm5, pFindMask
			
FINDLOOP:
		movupd xmm0, [eax+esi]
			
			pcmpeqb xmm0, xmm5
			
			pmovmskb ebx, xmm0
			
			cmp ebx, 0
			je NOTCOUNT
/*		{
				pextrb ebx, xmm0, 0
				cmp ebx, 0
				je NOTCOUNT0
				inc edx
NOTCOUNT0:
				pextrb ebx, xmm0, 1
				cmp ebx, 0
				je NOTCOUNT1
				inc edx
NOTCOUNT1:
				pextrb ebx, xmm0, 2
				cmp ebx, 0
				je NOTCOUNT2
				inc edx
NOTCOUNT2:
				pextrb ebx, xmm0, 3
				cmp ebx, 0
				je NOTCOUNT3
				inc edx
NOTCOUNT3:
				pextrb ebx, xmm0, 4
				cmp ebx, 0
				je NOTCOUNT4
				inc edx
NOTCOUNT4:
				pextrb ebx, xmm0, 5
				cmp ebx, 0
				je NOTCOUNT5
				inc edx
NOTCOUNT5:
				pextrb ebx, xmm0, 6
				cmp ebx, 0
				je NOTCOUNT6
				inc edx
NOTCOUNT6:
				pextrb ebx, xmm0, 7
				cmp ebx, 0
				je NOTCOUNT7
				inc edx
NOTCOUNT7:

				pextrb ebx, xmm0, 8
				cmp ebx, 0
				je NOTCOUNT8
				inc edx
NOTCOUNT8:
				pextrb ebx, xmm0, 9
				cmp ebx, 0
				je NOTCOUNT9
				inc edx
NOTCOUNT9:
				pextrb ebx, xmm0, 10
				cmp ebx, 0
				je NOTCOUNT10
				inc edx
NOTCOUNT2:
				pextrb ebx, xmm0, 11
				cmp ebx, 0
				je NOTCOUNT11
				inc edx
NOTCOUNT11:
				pextrb ebx, xmm0, 12
				cmp ebx, 0
				je NOTCOUNT12
				inc edx
NOTCOUNT12:
				pextrb ebx, xmm0, 13
				cmp ebx, 0
				je NOTCOUNT13
				inc edx
NOTCOUNT13:
				pextrb ebx, xmm0, 14
				cmp ebx, 0
				je NOTCOUNT14
				inc edx
NOTCOUNT14:
				pextrb ebx, xmm0, 15
				cmp ebx, 0
				je NOTCOUNT15
				inc edx
NOTCOUNT15:
		}*/
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
			if(pCharArray[i] == nFindValue )
				nFindCount++;
		}
	}
	
	
	return nFindCount;
}

int main(int argc, char* argv[])
{
	CStopWatch StopWatch;
	const int MAX_SIZE = 100000000;
	
	char* pCharArray = new char[MAX_SIZE];
	memset( pCharArray, 0x00, MAX_SIZE);
	pCharArray[0] = 100;
	pCharArray[1000000] = 100;
	pCharArray[2000000] = 100;
	pCharArray[3000000] = 100;
	pCharArray[4000000] = 100;
	pCharArray[5000000] = 100;
	pCharArray[6000000] = 100;
	pCharArray[7000000] = 100;
	pCharArray[8000000] = 100;
	pCharArray[9000000] = 100;
	
	int nResult = 0;
	
	StopWatch.Start();
	nResult = FindValueCountSIMD(pCharArray,100,MAX_SIZE);
	StopWatch.End();
	
	printf("SIMD Find Count : %d, Time : %f \n", nResult, StopWatch.GetDurationMilliSecond());
	
	StopWatch.Start();
	nResult = FindValueCountC(pCharArray,100,MAX_SIZE);
	StopWatch.End();
	
	printf("C Find Count : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());
	
	
	delete[] pCharArray;

	return 0;
}

