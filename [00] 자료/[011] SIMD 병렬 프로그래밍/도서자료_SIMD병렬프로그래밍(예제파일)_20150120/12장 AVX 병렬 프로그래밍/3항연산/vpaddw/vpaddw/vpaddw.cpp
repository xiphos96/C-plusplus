// vpaddw.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	short SrcA[8] = {1,2,3,4,5,6,7,8};
	short SrcB[8] = {2,2,2,2,2,2,2,2};

	short DstAdd[8] = {0};
	short DstSub[8] = {0};
	short DstMul[8] = {0};
		
	__asm
	{
		vmovdqu xmm0, SrcA
		vmovdqu xmm1, SrcB

		vpaddw xmm2, xmm0, xmm1
		vmovdqu DstAdd, xmm2

		vpsubw xmm2, xmm0, xmm1
		vmovdqu DstSub, xmm2

		vpmullw xmm2, xmm0, xmm1
		vmovdqu DstMul, xmm2
	}

	printf("Add : %d, %d, %d, %d, %d, %d, %d, %d\n",
		DstAdd[0],DstAdd[1],DstAdd[2],DstAdd[3],
		DstAdd[4],DstAdd[5],DstAdd[6],DstAdd[7]);

	printf("Sub : %d, %d, %d, %d, %d, %d, %d, %d\n",
		DstSub[0],DstSub[1],DstSub[2],DstSub[3],
		DstSub[4],DstSub[5],DstSub[6],DstSub[7]);

	printf("Mul : %d, %d, %d, %d, %d, %d, %d, %d\n",
		DstMul[0],DstMul[1],DstMul[2],DstMul[3],
		DstMul[4],DstMul[5],DstMul[6],DstMul[7]);

	return 0;
}

