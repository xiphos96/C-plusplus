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
	const short* pShort = pShortArray;		//스택 포인터 변수로 받아온다.
	
	int nLoopCount = (nSize / 8)*16;		//8배수 개수를 한 번에 계산
	int nRemain = nSize % 8;			//8배수 나머지 영역은 C로 구현
	
	short nMaxValue = 0;			//결괏값을 가지고 있을 메모리 변수

	short MaxValueArray[8] ={0};		//중간 결괏값을 담을 배열
	__asm
	{
		pushad
		mov eax, pShort		//자료구조 포인터를 레지스터에 옮긴다.
					//eax = pShort;
		mov esi, 0		//자료구조를 indexing할 레지스터 초기화
					//esi = 0;
		mov ecx, nLoopCount	//순환 연산 Limit 값을 담을 변수
		
		pxor xmm1, xmm1	//결괏값을 담을 레지스터 변수
				//xmm1 = 0;
			
FINDLP:
		movdqu xmm0, [eax+esi]		//xmm0 에 현재 값을 가져온다.
//xmm0 = *(eax+esi);
		pmaxsw xmm1, xmm0		//xmm1 = __max( xmm0, xmm1)
		

		add esi, 16			//esi = esi + 16; (esi += 16)과 같다.
		cmp esi, ecx			//if( esi != ecx )
		jne FINDLP			//goto FINDLP

		movdqu MaxValueArray, xmm1	//MaxValueArray = xmm1;

		popad
		
	}

	for( unsigned char Count = 0; Count < 8 ; Count++)
	{
//xmm1에서 구한 값 8개를 비교하여 최종 결괏값을 구한다.
if( MaxValueArray[Count] > nMaxValue )	
			nMaxValue = MaxValueArray[Count];
	}
	
	if( nRemain != 0)	//8배수가 아닌 나머지 값이 있으면 Max 값 비교를 수행
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
		
	StopWatch.Start();	//시간 측정 시작
	nResult = GetMaxValueC(pShortArray,MAX_SIZE);	//C 버전 수행
	StopWatch.End();		//시간 측정 종료
	
	printf("C Get Value : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());	//결과 출력
		
	StopWatch.Start();	//시간 측정 시작
	nResult = GetMaxValueSIMD(pShortArray,MAX_SIZE);//SIMD 수행
	StopWatch.End();		//시간 측정 종료
	
	printf("SIMD Get Value : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());	//결과 출력

	delete[] pShortArray;

	return 0;
}
