// AddSub.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//


#include "stdafx.h"
#include "immintrin.h"

int _tmain(int argc, _TCHAR* argv[])
{
	__declspec(align(32)) float SrcA[8] = {1,2,3,4,5,6,7,8};
	__declspec(align(32)) float SrcB[8] = {2,2,2,2,2,2,2,2};
	__declspec(align(32)) float DstAdd[8] = {0};
	__declspec(align(32)) float DstSub[8] = {0};
	__declspec(align(32)) float DstMul[8] = {0};
	__declspec(align(32)) float DstDiv[8] = {0};
		
	__m256 mmSrcA = _mm256_setzero_ps();
	__m256 mmSrcB = _mm256_setzero_ps();
	__m256 mmDst = _mm256_setzero_ps();
		
	mmSrcA = _mm256_load_ps(SrcA);
	mmSrcB = _mm256_load_ps(SrcB);

	mmDst = _mm256_add_ps(mmSrcA,mmSrcB);
	_mm256_store_ps(DstAdd,mmDst);

	mmDst = _mm256_sub_ps(mmSrcA,mmSrcB);
	_mm256_store_ps(DstSub,mmDst);

	mmDst = _mm256_mul_ps(mmSrcA,mmSrcB);
	_mm256_store_ps(DstMul,mmDst);

	mmDst = _mm256_div_ps(mmSrcA,mmSrcB);
	_mm256_store_ps(DstDiv,mmDst);

	printf("Add : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstAdd[0],DstAdd[1],DstAdd[2],DstAdd[3],
		DstAdd[4],DstAdd[5],DstAdd[6],DstAdd[7]);

	printf("Sub : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstSub[0],DstSub[1],DstSub[2],DstSub[3],
		DstSub[4],DstSub[5],DstSub[6],DstSub[7]);

	printf("Mul : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstMul[0],DstMul[1],DstMul[2],DstMul[3],
		DstMul[4],DstMul[5],DstMul[6],DstMul[7]);

	printf("Div : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstDiv[0],DstDiv[1],DstDiv[2],DstDiv[3],
		DstDiv[4],DstDiv[5],DstDiv[6],DstDiv[7]);
	return 0;
}
