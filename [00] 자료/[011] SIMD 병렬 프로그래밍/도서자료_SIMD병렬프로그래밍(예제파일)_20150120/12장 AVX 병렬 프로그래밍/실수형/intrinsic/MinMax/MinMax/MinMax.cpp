// MinMax.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "immintrin.h"

int _tmain(int argc, _TCHAR* argv[])
{	
	float fSrcA[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	float fSrcB[8] = {2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0};

	float fDstMin[8] = {0};
	float fDstMax[8] = {0};

	__m256 mSrcA = _mm256_loadu_ps(fSrcA);
	__m256 mSrcB = _mm256_loadu_ps(fSrcB);
	__m256 mDst = _mm256_min_ps(mSrcA, mSrcB);
	_mm256_storeu_ps(fDstMin, mDst);

	mDst = _mm256_max_ps(mSrcA, mSrcB);
	_mm256_storeu_ps(fDstMax, mDst);

	printf("float Min : ");
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		fDstMin[0],fDstMin[1],fDstMin[2],fDstMin[3],
		fDstMin[4],fDstMin[5],fDstMin[6],fDstMin[7]);

	printf("float Max : ");
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		fDstMax[0],fDstMax[1],fDstMax[2],fDstMax[3],
		fDstMax[4],fDstMax[5],fDstMax[6],fDstMax[7]);

	/*
	double dSrcA[4] = {1.0,2.0,3.0,4.0};
	double dSrcB[4] = {2.0,2.0,2.0,2.0};

	double dDstMin[4] = {0};
	double dDstMax[4] = {0};

	__m256d mdSrcA = _mm256_loadu_pd(dSrcA);
	__m256d mdSrcB = _mm256_loadu_pd(dSrcB);
	__m256d mdDst = _mm256_min_pd(mdSrcA, mdSrcB);
	_mm256_storeu_pd(dDstMin, mdDst);

	mdDst = _mm256_max_pd(mdSrcA, mdSrcB);
	_mm256_storeu_pd(dDstMax, mdDst);
	
	printf("double Min : ");
	printf("%.2f, %.2f, %.2f, %.2f\n",
		dDstMin[0],dDstMin[1],dDstMin[2],dDstMin[3]);

	printf("double Max : ");
	printf("%.2f, %.2f, %.2f, %.2f\n",
		dDstMax[0],dDstMax[1],dDstMax[2],dDstMax[3]);*/
	return 0;
}
