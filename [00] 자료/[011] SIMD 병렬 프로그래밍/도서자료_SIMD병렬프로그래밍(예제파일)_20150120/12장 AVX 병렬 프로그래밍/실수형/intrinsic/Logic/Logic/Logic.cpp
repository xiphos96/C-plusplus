// Logic.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "immintrin.h"

int _tmain(int argc, _TCHAR* argv[])
{
	float SrcA[8] = {1,0,1,0,1,0,1,0};
	float SrcB[8] = {1,1,0,0,1,1,0,0};

	float DstAnd[8] = {0};
	float DstOR[8] = {0};
	float DstXor[8] = {0};
	float DstAndN[8] = {0};
		
	__m256 mSrcA = _mm256_loadu_ps(SrcA);
	__m256 mSrcB = _mm256_loadu_ps(SrcB);

	__m256 mDst = _mm256_and_ps(mSrcA, mSrcB);
	_mm256_storeu_ps(DstAnd, mDst);
	
	mDst = _mm256_or_ps(mSrcA, mSrcB);
	_mm256_storeu_ps(DstOR, mDst);
		
	mDst = _mm256_xor_ps(mSrcA, mSrcB);
	_mm256_storeu_ps(DstXor, mDst);

	mDst = _mm256_andnot_ps(mSrcA, mSrcB);
	_mm256_storeu_ps(DstAndN, mDst);
	
	printf("And : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstAnd[0],DstAnd[1],DstAnd[2],DstAnd[3],
		DstAnd[4],DstAnd[5],DstAnd[6],DstAnd[7]);
		
	printf("OR : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstOR[0],DstOR[1],DstOR[2],DstOR[3],
		DstOR[4],DstOR[5],DstOR[6],DstOR[7]);

	printf("XOR : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstXor[0],DstXor[1],DstXor[2],DstXor[3],
		DstXor[4],DstXor[5],DstXor[6],DstXor[7]);

	printf("And not : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstAndN[0],DstAndN[1],DstAndN[2],DstAndN[3],
		DstAndN[4],DstAndN[5],DstAndN[6],DstAndN[7]);
	
	return 0;
}


