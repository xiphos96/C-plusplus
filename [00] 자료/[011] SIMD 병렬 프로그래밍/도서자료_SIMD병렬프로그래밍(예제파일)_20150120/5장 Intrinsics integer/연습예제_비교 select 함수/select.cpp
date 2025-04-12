// select.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>
#include "StopWatch.h"

void SelectC(short* pSrc, short CmpValue, int nSize)
{
	for(int i = 0; i < nSize; i++)
	{
		if(pSrc[i] < CmpValue)		//0���� ������ 0 ũ�� ���� ���� �����Ѵ�. 
			pSrc[i] = 0;
	}
}

void SelectIntrinsic(short* pSrc, short CmpValue, int nSize)
{
	int nRemain = nSize % 8;
	
	__m128i XMMCurrentValue;
	__m128i XMMCmpValue = _mm_set1_epi16(CmpValue);		//�� ���ذ� 8���� ���� package����
	__m128i XMMCmpResult;
	
	for(unsigned int Index =0 ; Index < nSize; Index+=8)	//8���� �ѹ��� ó���Ѵ�.
	{
		XMMCurrentValue = _mm_loadu_si128((__m128i*)(pSrc+Index));
		//16byte �� �о�´�.
		
		XMMCmpResult = _mm_cmpgt_epi16(XMMCurrentValue, XMMCmpValue);
		//���簪�� ���ذ��� ���Ѵ�. true �� 0xffff false �̸� 0x0
		
		XMMCurrentValue = _mm_and_si128(XMMCurrentValue,XMMCmpResult);
		//�ΰ��� and�����Ͽ� ū���� �����´�.
		
		_mm_storeu_si128((__m128i*)(pSrc+Index),XMMCurrentValue);
	}
	
	if( nRemain != 0)
	{
		for(int i = nSize-nRemain; i < nSize; i++)
		{
			if(pSrc[i] < CmpValue)		//0���� ������ 0 ũ�� ���� ���� �����Ѵ�. 
				pSrc[i] = 0;
		}
	}
}

#define MAXSIZE 10000

int main(int argc, char* argv[])
{
	short Array[MAXSIZE] = {0};
	
	int i = 0;
	
	//Ȧ���� ����, ¦���� ��� ����
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
	SelectC(Array,0,MAXSIZE);	//C  Select �Լ�
	watch.End();
	
	//���, �����ð� ���
	printf("Result Data : %d,%d,%d,%d,%d,%d,%d,%d, C Time : %f\n",
		Array[0],Array[1],Array[2],Array[3],Array[4],Array[5],Array[6],Array[7],
		watch.GetDurationMilliSecond());
	
	//Ȧ���� ����, ¦���� ��� ����
	for ( i = 0; i < MAXSIZE; i++)
	{
		if( i % 2 == 0)
			Array[i] = i;
		else
			Array[i] = -1*i;
	}
	
	watch.Start();
	SelectIntrinsic(Array,0,MAXSIZE);	//instrinsic Select �Լ�
	watch.End();
	
	//���, �����ð� ���
	printf("Result Data : %d,%d,%d,%d,%d,%d,%d,%d, intrinsic Time : %f\n",
		Array[0],Array[1],Array[2],Array[3],Array[4],Array[5],Array[6],Array[7],
		watch.GetDurationMilliSecond());
	return 0;
}
