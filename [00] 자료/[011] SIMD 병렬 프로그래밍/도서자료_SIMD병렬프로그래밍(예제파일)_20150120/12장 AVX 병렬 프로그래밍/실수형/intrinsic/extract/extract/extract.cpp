// extract.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "immintrin.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int nSrc[8] = {10,20,30,40,50,60,70,80};
	float fSrc[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	
	int DstIA[8] = {0};
	int DstIB[8] = {0};
	float DstPSA[4] = {0};
	float DstPSB[4] = {0};

	__m256 m256Src = _mm256_loadu_ps(fSrc);
	__m128 m128Src = _mm256_extractf128_ps(m256Src,0);

	_mm_storeu_ps(DstPSA, m128Src);

	m128Src = _mm256_extractf128_ps(m256Src,1);

	_mm_storeu_ps(DstPSB, m128Src);
	
	printf("DstPSA %.2f, %.2f, %.2f, %.2f\n",
		DstPSA[0],DstPSA[1],DstPSA[2],DstPSA[3]);

	printf("DstPSB %.2f, %.2f, %.2f, %.2f\n",
		DstPSB[0],DstPSB[1],DstPSB[2],DstPSB[3]);

	__m256i m256iSrc = _mm256_loadu_si256((__m256i*)nSrc);
	__m128i m128iSrc = _mm256_extractf128_si256(m256iSrc,0);

	_mm_storeu_si128((__m128i*)DstIA, m128iSrc);

	m128Src = _mm256_extractf128_ps(m256Src,1);

	_mm_storeu_si128((__m128i*)DstIB, m128iSrc);

	printf("DstIA : %d, %d, %d, %d\n",
		DstIA[0],DstIA[1],DstIA[2],DstIA[3]);

	printf("DstIB : %d, %d, %d, %d\n",
		DstIB[0],DstIB[1],DstIB[2],DstIB[3]);
	return 0;
}

