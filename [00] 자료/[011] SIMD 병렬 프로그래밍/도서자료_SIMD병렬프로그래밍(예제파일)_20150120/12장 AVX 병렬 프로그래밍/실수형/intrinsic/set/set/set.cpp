// set.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "immintrin.h"

int _tmain(int argc, _TCHAR* argv[])
{
	float SrcA[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	float SrcB[8] = {2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0};

	float DstSet[8] = {0};
	float DstZero[8] = {2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0};
	float DstSetR[8] = {0};
	float DstSet1[8] = {0};
	float DstHsub[8] = {0};
	
	__m256 mSrcA = _mm256_loadu_ps(SrcA);
	__m256 mSrcB = _mm256_loadu_ps(SrcB);

	__m256 mDst = _mm256_set_ps(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0);
	_mm256_storeu_ps(DstSet, mDst);

	mDst = _mm256_setzero_ps();
	_mm256_storeu_ps(DstZero, mDst);
	
	mDst = _mm256_setr_ps(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0);
	_mm256_storeu_ps(DstSetR, mDst);

	mDst = _mm256_set1_ps(9.0);
	_mm256_storeu_ps(DstSet1, mDst);
	
	printf("Set : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstSet[0],DstSet[1],DstSet[2],DstSet[3],
		DstSet[4],DstSet[5],DstSet[6],DstSet[7]);

	printf("Set Zero : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstZero[0],DstZero[1],DstZero[2],DstZero[3],
		DstZero[4],DstZero[5],DstZero[6],DstZero[7]);

	printf("SetR : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstSetR[0],DstSetR[1],DstSetR[2],DstSetR[3],
		DstSetR[4],DstSetR[5],DstSetR[6],DstSetR[7]);

	printf("Set1 : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstSet1[0],DstSet1[1],DstSet1[2],DstSet1[3],
		DstSet1[4],DstSet1[5],DstSet1[6],DstSet1[7]);
	
	return 0;
}

