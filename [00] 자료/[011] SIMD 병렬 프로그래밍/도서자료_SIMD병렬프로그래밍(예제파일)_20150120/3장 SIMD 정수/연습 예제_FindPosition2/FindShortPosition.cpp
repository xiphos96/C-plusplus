// FindShortPosition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "memory.h"
#include "StopWatch.h"
#include <algorithm>

int FindPositionSTL(const short *pShortArray, const short nFindValue, const int nSize)
{
	const short * pPosition = std::find(pShortArray, pShortArray+nSize, nFindValue);
	return pPosition-pShortArray;
}

int FindPositionC(const short *pShortArray, const short nFindValue, const int nSize)
{
    int i = 0;
	for( i = 0; i< nSize ; i++)
	{
		if(pShortArray[i] == nFindValue)
			return i;
	}
	return i;
}

int FindPositionSIMD(const short *pShortArray, const short nFindValue, const int nSize)
{
	const short* pShort = pShortArray;
	
	int nLoopCount = (nSize / 8)*16;
	int nRemain = nSize % 8;
	
	short pFindMask[8] = {0};

    unsigned char j= 0;
	
	for( j= 0; j < 8; j++)
	{
		pFindMask[j] = nFindValue;
	}
	
	int nFindCount = 0;
	int nPosition = 0;

	__asm
	{
		pushad
		mov eax, pShort
		mov edx, -1
		mov esi, 0
		mov ecx, nLoopCount
		
		movdqu xmm5, pFindMask
			
FINDLOOP:
		movdqu  xmm0, [eax+esi] 	//�޸��� ���� xmm0�� ����
		pcmpeqw xmm0, xmm5		//����ũ�� ���� ���� ���� �ִ��� ��
		pmovmskb ebx, xmm0		//package�� ���� 1bit�� �����Ѵ�.
		
		cmp ebx, 0			//���� ���� �ִ��� ��
		je NOTFIND			//���� ���� ������ ���� ����
		{
FINDNEXT:
			inc edx
			pextrw ebx, xmm0, 0	//0��° ��ġ �� ����
			psrldq xmm0, 2		//2byte ������ ����Ʈ ����
			cmp ebx, 0		//���� �ִ��� ��
			je FINDNEXT
			jne FINDEND
		}
NOTFIND:
		
		add esi, 16
		cmp esi, ecx
		jne FINDLOOP

FINDEND:
		mov eax, esi
		shr eax, 1
		add eax, edx
		mov nPosition, eax

		popad
		
	}
	
	if( nRemain != 0 && nPosition == 0)
	{
		for( int i = nSize-nRemain; i< nSize; i++)
		{
			if(pShortArray[i] == nFindValue )
				return i;
		}
	}
		
	return nPosition;
}

int main(int argc, char* argv[])
{
	CStopWatch StopWatch;
	const int MAX_SIZE = 100000000;
	
	short* pShortArray = new short[MAX_SIZE];
	memset( pShortArray, 0x00, MAX_SIZE*sizeof(short));

	pShortArray[9000004] = 100;

	int nResult = 0;
		
	StopWatch.Start();
	nResult = FindPositionC(pShortArray,100,MAX_SIZE);
	StopWatch.End();
	
	printf("C Find Count : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());
		
	StopWatch.Start();
	nResult = FindPositionSTL(pShortArray,100,MAX_SIZE);
	StopWatch.End();
	
	printf("STL Find Count : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());

	StopWatch.Start();
	nResult = FindPositionSIMD(pShortArray,100,MAX_SIZE);
	StopWatch.End();
	
	printf("SIMD Find Count : %d, Time : %f \n", nResult, StopWatch.GetDurationMilliSecond());
	delete[] pShortArray;

	return 0;
}

