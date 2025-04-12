// Math.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "immintrin.h"

int _tmain(int argc, _TCHAR* argv[])
{
	float SrcA[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	float SrcB[8] = {2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0};

	float DstRCP[8] = {0};
	float DstRsqrt[8] = {0};
	float DstSqrt[8] = {0};
	float DstHadd[8] = {0};
	float DstHsub[8] = {0};
	
	__m256 mSrcA = _mm256_loadu_ps(SrcA);
	__m256 mSrcB = _mm256_loadu_ps(SrcB);

	__m256 mDst = _mm256_rcp_ps(mSrcA);
	_mm256_storeu_ps(DstRCP, mDst);
	
	mDst = _mm256_sqrt_ps(mSrcA);
	_mm256_storeu_ps(DstSqrt, mDst);
		
	mDst = _mm256_rsqrt_ps(mSrcA);
	_mm256_storeu_ps(DstRsqrt, mDst);

	mDst = _mm256_hadd_ps(mSrcA,mSrcB);
	_mm256_storeu_ps(DstHadd, mDst);
	
	mDst = _mm256_hsub_ps(mSrcA,mSrcB);
	_mm256_storeu_ps(DstHsub, mDst);

	printf("RCP : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstRCP[0],DstRCP[1],DstRCP[2],DstRCP[3],
		DstRCP[4],DstRCP[5],DstRCP[6],DstRCP[7]);
		
	printf("Sqrt : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstSqrt[0],DstSqrt[1],DstSqrt[2],DstSqrt[3],
		DstSqrt[4],DstSqrt[5],DstSqrt[6],DstSqrt[7]);

	printf("Rsqrt : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstRsqrt[0],DstRsqrt[1],DstRsqrt[2],DstRsqrt[3],
		DstRsqrt[4],DstRsqrt[5],DstRsqrt[6],DstRsqrt[7]);

	printf("Hadd : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstHadd[0],DstHadd[1],DstHadd[2],DstHadd[3],
		DstHadd[4],DstHadd[5],DstHadd[6],DstHadd[7]);
	
	printf("HSub : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstHsub[0],DstHsub[1],DstHsub[2],DstHsub[3],
		DstHsub[4],DstHsub[5],DstHsub[6],DstHsub[7]);

	return 0;
}


