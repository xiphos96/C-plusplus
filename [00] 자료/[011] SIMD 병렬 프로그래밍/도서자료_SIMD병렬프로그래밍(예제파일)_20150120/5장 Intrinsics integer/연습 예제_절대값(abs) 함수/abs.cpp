// abs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>
#include "StopWatch.h"

void ABSC(short* pSrc, int nSize)
{
	for(int i = 0; i < nSize; i++)
	{
		if(pSrc[i] < 0)		//0���� ������ -1�� ���Ͽ� ��� ��ȯ
			pSrc[i] *= -1;
	}
}

void ABSIntrinsic(short* pSrc, int nSize)
{
	int nRemain = nSize % 8;
	
	__m128i XMMCurrentValue;
	__m128i XMMZeroValue;
	
	for(unsigned int Index =0 ; Index < nSize; Index+=8)	//8���� �ѹ��� ó���Ѵ�.
	{
		XMMZeroValue = _mm_setzero_si128();
		XMMCurrentValue = _mm_loadu_si128((__m128i*)(pSrc+Index));
		//16byte �� �о�´�.
		
		XMMZeroValue = _mm_subs_epi16(XMMZeroValue, XMMCurrentValue);
		//ZeroValue = 0 - CurrentValue , ����� ���� ��ȯ, ������ ��� ��ȯ
		
		XMMCurrentValue = _mm_max_epi16(XMMCurrentValue,XMMZeroValue);
		//�ΰ��� ���Ͽ� ū���� �����´�.
		
		_mm_storeu_si128((__m128i*)(pSrc+Index),XMMCurrentValue);
	}

	if( nRemain != 0)
	{
		for( int i = nSize-nRemain; i< nSize; i++)
		{
			if(pSrc[i] < 0)
				pSrc[i] *= -1;
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
	ABSC(Array,MAXSIZE);	//C ABS �Լ�
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
	ABSIntrinsic(Array,MAXSIZE);	//instrinsic ABS �Լ�
	watch.End();

	//���, �����ð� ���
	printf("Result Data : %d,%d,%d,%d,%d,%d,%d,%d, intrinsic Time : %f\n",
		Array[0],Array[1],Array[2],Array[3],Array[4],Array[5],Array[6],Array[7],
		watch.GetDurationMilliSecond());
	return 0;
}

