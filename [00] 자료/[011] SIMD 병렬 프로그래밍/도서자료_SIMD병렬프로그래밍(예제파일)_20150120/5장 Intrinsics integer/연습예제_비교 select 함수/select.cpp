// select.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>
#include "StopWatch.h"

void SelectC(short* pSrc, short CmpValue, int nSize)
{
	for(int i = 0; i < nSize; i++)
	{
		if(pSrc[i] < CmpValue)		//0보다 작으면 0 크면 원래 값을 리턴한다. 
			pSrc[i] = 0;
	}
}

void SelectIntrinsic(short* pSrc, short CmpValue, int nSize)
{
	int nRemain = nSize % 8;
	
	__m128i XMMCurrentValue;
	__m128i XMMCmpValue = _mm_set1_epi16(CmpValue);		//비교 기준값 8개를 가진 package생성
	__m128i XMMCmpResult;
	
	for(unsigned int Index =0 ; Index < nSize; Index+=8)	//8개씩 한번에 처리한다.
	{
		XMMCurrentValue = _mm_loadu_si128((__m128i*)(pSrc+Index));
		//16byte 씩 읽어온다.
		
		XMMCmpResult = _mm_cmpgt_epi16(XMMCurrentValue, XMMCmpValue);
		//현재값과 기준값을 비교한다. true 면 0xffff false 이면 0x0
		
		XMMCurrentValue = _mm_and_si128(XMMCurrentValue,XMMCmpResult);
		//두값을 and연산하여 큰값만 가져온다.
		
		_mm_storeu_si128((__m128i*)(pSrc+Index),XMMCurrentValue);
	}
	
	if( nRemain != 0)
	{
		for(int i = nSize-nRemain; i < nSize; i++)
		{
			if(pSrc[i] < CmpValue)		//0보다 작으면 0 크면 원래 값을 리턴한다. 
				pSrc[i] = 0;
		}
	}
}

#define MAXSIZE 10000

int main(int argc, char* argv[])
{
	short Array[MAXSIZE] = {0};
	
	int i = 0;
	
	//홀수는 음수, 짝수는 양수 셋팅
	for ( i = 0; i < MAXSIZE; i++)
	{
		if( i % 2 == 0)
			Array[i] = i;
		else
			Array[i] = -1*i;
	}
	
	CStopWatch watch;
	
	printf("Source Data : %d,%d,%d,%d,%d,%d,%d,%d\n",
		Array[0],Array[1],Array[2],Array[3],Array[4],Array[5],Array[6],Array[7]);
	
	watch.Start();
	SelectC(Array,0,MAXSIZE);	//C  Select 함수
	watch.End();
	
	//결과, 측정시간 출력
	printf("Result Data : %d,%d,%d,%d,%d,%d,%d,%d, C Time : %f\n",
		Array[0],Array[1],Array[2],Array[3],Array[4],Array[5],Array[6],Array[7],
		watch.GetDurationMilliSecond());
	
	//홀수는 음수, 짝수는 양수 셋팅
	for ( i = 0; i < MAXSIZE; i++)
	{
		if( i % 2 == 0)
			Array[i] = i;
		else
			Array[i] = -1*i;
	}
	
	watch.Start();
	SelectIntrinsic(Array,0,MAXSIZE);	//instrinsic Select 함수
	watch.End();
	
	//결과, 측정시간 출력
	printf("Result Data : %d,%d,%d,%d,%d,%d,%d,%d, intrinsic Time : %f\n",
		Array[0],Array[1],Array[2],Array[3],Array[4],Array[5],Array[6],Array[7],
		watch.GetDurationMilliSecond());
	return 0;
}
