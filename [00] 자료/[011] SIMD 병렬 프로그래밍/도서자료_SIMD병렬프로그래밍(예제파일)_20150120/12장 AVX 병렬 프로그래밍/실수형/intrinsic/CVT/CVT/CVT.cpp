// CVT.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "immintrin.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int nSrc[8] = {1,2,3,4,5,6,7,8};
	float fSrc[8] = {10,20,30,40,50,60,70,80};
	
	int DstPStoI[8] = {0};
	float DstItoPS[8] = {0};
	double DstItoPD[4] = {0};
	
	__m256i m256iSrc = _mm256_loadu_si256((__m256i*)nSrc);
	__m256	mDstPS = _mm256_cvtepi32_ps( m256iSrc);

	_mm256_storeu_ps(DstItoPS, mDstPS);

	__m128i m128iSrc = _mm_loadu_si128((__m128i*)nSrc);
	__m256d	mDstPD = _mm256_cvtepi32_pd( m128iSrc);

	_mm256_storeu_pd(DstItoPD, mDstPD);

	__m256 mSrc = _mm256_loadu_ps(fSrc);
	__m256i m256iDst = _mm256_cvtps_epi32(mSrc);
	
	_mm256_storeu_si256((__m256i*)DstPStoI, m256iDst);
	
	printf("convert i to ps : ");
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstItoPS[0],DstItoPS[1],DstItoPS[2],DstItoPS[3],
		DstItoPS[4],DstItoPS[5],DstItoPS[6],DstItoPS[7]);

	printf("convert i to pd : ");
	printf("%.2f, %.2f, %.2f, %.2f\n",
		DstItoPD[0],DstItoPD[1],DstItoPD[2],DstItoPD[3]);

	printf("convert ps to i : ");
	printf("%d, %d, %d, %d, %d, %d, %d, %d\n",
		DstPStoI[0],DstPStoI[1],DstPStoI[2],DstPStoI[3],
		DstPStoI[4],DstPStoI[5],DstPStoI[6],DstPStoI[7]);

	return 0;
}
