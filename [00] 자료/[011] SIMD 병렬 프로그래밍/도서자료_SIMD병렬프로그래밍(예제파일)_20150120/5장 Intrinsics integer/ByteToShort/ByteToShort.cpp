// ByteToShort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>
#include "StopWatch.h"

#define MAX_SIZE 1024*1024*50

void ByteToShortC(unsigned char* pByte, unsigned short* pShort, int nSize)
{
	for(int i = 0; i< MAX_SIZE; i++)
	{
		pShort[i] = pByte[i];
	}
};

void ShortToIntC(unsigned short* pShort, unsigned int* pInt, int nSize)
{
	for(int i = 0; i< MAX_SIZE; i++)
	{
		pInt[i] = pShort[i];
	}
};

void ByteToIntC(unsigned char* pByte, unsigned int* pInt, int nSize)
{
	for(int i = 0; i< MAX_SIZE; i++)
	{
		pInt[i] = pByte[i];
	}
};

void ByteToShortIntrinsic(unsigned char* pByte, unsigned short* pShort, int nSize)
{
	int LoopCount = (nSize/16)*16;
	int Remain = nSize - LoopCount;

	__m128i XMMLowData;
	__m128i XMMHighData;
	__m128i ZeroData = _mm_setzero_si128();
	int i = 0;
	int j = 0;
	for( i = 0; i < LoopCount; i+=16)
	{
		XMMLowData = _mm_loadu_si128((__m128i*)(pByte+i));
		XMMHighData = _mm_unpackhi_epi8(XMMLowData,ZeroData);	//pack 연산
		XMMLowData = _mm_unpacklo_epi8(XMMLowData,ZeroData);	//pack 연산

		_mm_storeu_si128((__m128i*)(pShort+j),XMMLowData);		//결과 출력
		j+=8;
		_mm_storeu_si128((__m128i*)(pShort+j),XMMHighData);		//결과 출력
		j+=8;

	}

	for( i = LoopCount; i < nSize; i++)
	{
		pShort[i] = pByte[i];
	}
}


void ShortToIntIntrinsic(unsigned short* pShort, unsigned int* pInt, int nSize)
{
	int LoopCount = (nSize/8)*8;
	int Remain = nSize - LoopCount;
	
	__m128i XMMLowData;
	__m128i XMMHighData;
	__m128i ZeroData = _mm_setzero_si128();
	int i = 0;
	int j = 0;
	for( i = 0; i < LoopCount; i+=8)
	{
		XMMLowData = _mm_loadu_si128((__m128i*)(pShort+i));
		XMMHighData = _mm_unpackhi_epi16(XMMLowData,ZeroData);	//pack 연산
		XMMLowData = _mm_unpacklo_epi16(XMMLowData,ZeroData);	//pack 연산
		
		_mm_storeu_si128((__m128i*)(pInt+j),XMMLowData);		//결과 출력
		j+=4;
		_mm_storeu_si128((__m128i*)(pInt+j),XMMHighData);		//결과 출력
		j+=4;
		
	}
	
	for( i = LoopCount; i < nSize; i++)
	{
		pInt[i] = pShort[i];
	}
}

void ByteToIntIntrinsic(unsigned char* pByte, unsigned int* pint, int nSize)
{
	int LoopCount = (nSize/16)*16;
	int Remain = nSize - LoopCount;
	
	__m128i XMMLoadData;
	__m128i XMMData[4];
	__m128i ZeroData = _mm_setzero_si128();
	int i = 0;
	int j = 0;
	for( i = 0; i < LoopCount; i+=16)
	{
		XMMLoadData = _mm_loadu_si128((__m128i*)(pByte+i));
		XMMData[0] = _mm_unpacklo_epi8(XMMLoadData,ZeroData);	//pack 연산
		XMMData[2] = _mm_unpackhi_epi8(XMMLoadData,ZeroData);	//pack 연산
		XMMData[1] = _mm_unpackhi_epi16(XMMData[0],ZeroData);	//pack 연산
		XMMData[0] = _mm_unpacklo_epi16(XMMData[0],ZeroData);	//pack 연산
		
		XMMData[3] = _mm_unpackhi_epi16(XMMData[2],ZeroData);	//pack 연산
		XMMData[2] = _mm_unpacklo_epi16(XMMData[2],ZeroData);	//pack 연산

		_mm_storeu_si128((__m128i*)(pint+j),XMMData[0]);		//결과 출력
		j+=4;
		_mm_storeu_si128((__m128i*)(pint+j),XMMData[1]);		//결과 출력
		j+=4;
		_mm_storeu_si128((__m128i*)(pint+j),XMMData[2]);		//결과 출력
		j+=4;
		_mm_storeu_si128((__m128i*)(pint+j),XMMData[3]);		//결과 출력
		j+=4;
		
	}
	
	for( i = LoopCount; i < nSize; i++)
	{
		pint[i] = pByte[i];
	}
}

int main(int argc, char* argv[])
{
	int i = 0;
	unsigned char* ByteArray = new unsigned char[MAX_SIZE];
	unsigned short* ShortArray = new unsigned short[MAX_SIZE];
	unsigned int* IntArray = new unsigned int [MAX_SIZE];

	for( i = 0; i < MAX_SIZE; i++)
	{
		ByteArray[i] = i % 256;
		ShortArray[i] = i % 256;
	}

	CStopWatch watch;

	printf("%d, %d, %d, %d, %d, %d, %d, %d\n",
		ByteArray[0],ByteArray[1],ByteArray[2],ByteArray[3],
		ByteArray[4],ByteArray[5],ByteArray[6],ByteArray[7]);

	watch.Start();
	ByteToShortC(ByteArray, ShortArray, MAX_SIZE );
	watch.End();
	
	printf("%d, %d, %d, %d, %d, %d, %d, %d ByteToShortC Time: %f msec\n",
		ShortArray[0],ShortArray[1],ShortArray[2],ShortArray[3],
		ShortArray[4],ShortArray[5],ShortArray[6],ShortArray[7],watch.GetDurationMilliSecond());

	watch.Start();
	ByteToIntC(ByteArray, IntArray, MAX_SIZE );
	watch.End();
	
	printf("%d, %d, %d, %d, %d, %d, %d, %d ByteToIntC Time: %f msec\n",
		IntArray[0],IntArray[1],IntArray[2],IntArray[3],
		IntArray[4],IntArray[5],IntArray[6],IntArray[7],watch.GetDurationMilliSecond());

	watch.Start();
	ShortToIntC(ShortArray, IntArray, MAX_SIZE );
	watch.End();
	
	printf("%d, %d, %d, %d, %d, %d, %d, %d ShortToIntC Time: %f msec\n",
		IntArray[0],IntArray[1],IntArray[2],IntArray[3],
		IntArray[4],IntArray[5],IntArray[6],IntArray[7],watch.GetDurationMilliSecond());
	
	for( i = 0; i < MAX_SIZE; i++)
	{
		ShortArray[i] = 0;
	}

	watch.Start();
	ByteToShortIntrinsic(ByteArray, ShortArray, MAX_SIZE );
	watch.End();
		
	printf("%d, %d, %d, %d, %d, %d, %d, %d ByteToShortIntrinsic: %f msec\n",
		ShortArray[0],ShortArray[1],ShortArray[2],ShortArray[3],
		ShortArray[4],ShortArray[5],ShortArray[6],ShortArray[7],watch.GetDurationMilliSecond());

	watch.Start();
	ByteToIntIntrinsic(ByteArray, IntArray, MAX_SIZE );
	watch.End();
	
	printf("%d, %d, %d, %d, %d, %d, %d, %d ByteToIntIntrinsic: %f msec\n",
		IntArray[0],IntArray[1],IntArray[2],IntArray[3],
		IntArray[4],IntArray[5],IntArray[6],IntArray[7],watch.GetDurationMilliSecond());

	watch.Start();
	ShortToIntIntrinsic(ShortArray, IntArray, MAX_SIZE );
	watch.End();
	
	printf("%d, %d, %d, %d, %d, %d, %d, %d ShortToIntIntrinsic: %f msec\n",
		IntArray[0],IntArray[1],IntArray[2],IntArray[3],
		IntArray[4],IntArray[5],IntArray[6],IntArray[7],watch.GetDurationMilliSecond());

	delete[] ByteArray;
	delete[] ShortArray;
	delete[] IntArray;
	return 0;
}

