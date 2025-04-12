// FindShortPosition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "memory.h"
#include "StopWatch.h"
#include <emmintrin.h>

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
	const short* pShort = pShortArray;		//���� ������ ������ �޾ƿ´�.
	
	int nLoopCount = (nSize / 8)*16;		//8��� ������ �� ���� ���
	int nRemain = nSize % 8;			//8��� ������ ������ C�� ����
	
	short nMaxValue = 0;			//�ᱣ���� ������ ���� �޸� ����

	short MaxValueArray[8] ={0};		//�߰� �ᱣ���� ���� �迭
	__asm
	{
		pushad
		mov eax, pShort		//�ڷᱸ�� �����͸� �������Ϳ� �ű��.
					//eax = pShort;
		mov esi, 0		//�ڷᱸ���� indexing�� �������� �ʱ�ȭ
					//esi = 0;
		mov ecx, nLoopCount	//��ȯ ���� Limit ���� ���� ����
		
		pxor xmm1, xmm1	//�ᱣ���� ���� �������� ����
				//xmm1 = 0;
			
FINDLP:
		movdqu xmm0, [eax+esi]		//xmm0 �� ���� ���� �����´�.
//xmm0 = *(eax+esi);
		pmaxsw xmm1, xmm0		//xmm1 = __max( xmm0, xmm1)
		

		add esi, 16			//esi = esi + 16; (esi += 16)�� ����.
		cmp esi, ecx			//if( esi != ecx )
		jne FINDLP			//goto FINDLP

		movdqu MaxValueArray, xmm1	//MaxValueArray = xmm1;

		popad
		
	}

	for( unsigned char Count = 0; Count < 8 ; Count++)
	{
//xmm1���� ���� �� 8���� ���Ͽ� ���� �ᱣ���� ���Ѵ�.
if( MaxValueArray[Count] > nMaxValue )	
			nMaxValue = MaxValueArray[Count];
	}
	
	if( nRemain != 0)	//8����� �ƴ� ������ ���� ������ Max �� �񱳸� ����
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
	const int MAX_SIZE = 100000000;
	
	short* pShortArray = new short[MAX_SIZE];
	memset( pShortArray, 0x00, MAX_SIZE*sizeof(short));

	pShortArray[9000003] = 100;
	pShortArray[0] = 101;

	int nResult = 0;
		
	StopWatch.Start();	//�ð� ���� ����
	nResult = GetMaxValueC(pShortArray,MAX_SIZE);	//C ���� ����
	StopWatch.End();		//�ð� ���� ����
	
	printf("C Get Value : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());	//��� ���
		
	StopWatch.Start();	//�ð� ���� ����
	nResult = GetMaxValueSIMD(pShortArray,MAX_SIZE);//SIMD ����
	StopWatch.End();		//�ð� ���� ����
	
	printf("SIMD Get Value : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());	//��� ���

	delete[] pShortArray;

	return 0;
}
