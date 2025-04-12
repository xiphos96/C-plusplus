// ReadByte.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "immintrin.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char nSrc[20] = {1,2,3,4,5,6,7,8,0,0,0,0,0,0,0,0,0,0,0,0};
	float fSrc[8] = {10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0};
	
	float DstPS[8] = {0};

	__m128i m128isrcA = _mm_loadu_si128((__m128i*)nSrc);
	__m128i m128isrcB = _mm_loadu_si128((__m128i*)(nSrc+4));

	m128isrcA = _mm_cvtepu8_epi32(m128isrcA);
	m128isrcB = _mm_cvtepu8_epi32(m128isrcB);

	__m256i m256iSrc = _mm256_insertf128_si256(_mm256_setzero_si256(), m128isrcA, 0);
	m256iSrc = _mm256_insertf128_si256(m256iSrc, m128isrcB, 1);

	__m256	mDstPS = _mm256_cvtepi32_ps( m256iSrc);

	_mm256_storeu_ps(DstPS, mDstPS);

	printf("DstPS %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstPS[0],DstPS[1],DstPS[2],DstPS[3],
		DstPS[4],DstPS[5],DstPS[6],DstPS[7]);

	return 0;
}

