// insert.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "immintrin.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int nSrc[8] = {10,20,30,40,50,60,70,80};
	float fSrc[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	
	int DstIA[8] = {0};
	int DstIB[8] = {0};
	float DstPSA[8] = {0};
	float DstPSB[8] = {0};

	__m256 m256Src = _mm256_setzero_ps();
	__m128 m128Src = _mm_loadu_ps(fSrc);

	m256Src = _mm256_insertf128_ps(m256Src, m128Src, 0);

	_mm256_storeu_ps(DstPSA, m256Src);

	m128Src = _mm_loadu_ps(fSrc+4);;
	m256Src = _mm256_insertf128_ps(_mm256_setzero_ps(), m128Src, 1);

	_mm256_storeu_ps(DstPSB, m256Src);

	printf("DstPSA %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstPSA[0],DstPSA[1],DstPSA[2],DstPSA[3],
		DstPSA[4],DstPSA[5],DstPSA[6],DstPSA[7]);

	printf("DstPSA %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstPSB[0],DstPSB[1],DstPSB[2],DstPSB[3],
		DstPSB[4],DstPSB[5],DstPSB[6],DstPSB[7]);
	
	__m256i m256iSrc = _mm256_setzero_si256();
	__m128i m128iSrc = _mm_loadu_si128((__m128i*)nSrc);

	m128iSrc = _mm_loadu_si128((__m128i*)nSrc);
	m256iSrc = _mm256_insertf128_si256(m256iSrc, m128iSrc, 0);

	_mm256_storeu_si256((__m256i*)DstIA, m256iSrc);

	m128iSrc = _mm_loadu_si128((__m128i*)(nSrc+4));
	m256iSrc = _mm256_insertf128_si256(_mm256_setzero_si256(), m128iSrc, 1);

	_mm256_storeu_si256((__m256i*)DstIB, m256iSrc);

	printf("DstIA : %d, %d, %d, %d, %d, %d, %d, %d\n",
		DstIA[0],DstIA[1],DstIA[2],DstIA[3],
		DstIA[4],DstIA[5],DstIA[6],DstIA[7]);

	printf("DstIB : %d, %d, %d, %d, %d, %d, %d, %d\n",
		DstIB[0],DstIB[1],DstIB[2],DstIB[3],
		DstIB[4],DstIB[5],DstIB[6],DstIB[7]);

	return 0;
}

