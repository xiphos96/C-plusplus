// vpminmax.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	short SrcA[8] = {1,2,3,4,5,6,7,8};
	short SrcB[8] = {2,2,2,2,2,2,2,2};

	short DstMin[8] = {0};
	short DstMax[8] = {0};
	short DstAvg[8] = {0};
		
	__asm
	{
		vmovdqu xmm0, SrcA
		vmovdqu xmm1, SrcB

		vpminsw xmm2, xmm0, xmm1
		vmovdqu DstMin, xmm2

		vpmaxsw xmm2, xmm0, xmm1
		vmovdqu DstMax, xmm2

		vpavgw xmm2, xmm0, xmm1
		vmovdqu DstAvg, xmm2
	}

	printf("Min : %d, %d, %d, %d, %d, %d, %d, %d\n",
		DstMin[0],DstMin[1],DstMin[2],DstMin[3],
		DstMin[4],DstMin[5],DstMin[6],DstMin[7]);

	printf("Max : %d, %d, %d, %d, %d, %d, %d, %d\n",
		DstMax[0],DstMax[1],DstMax[2],DstMax[3],
		DstMax[4],DstMax[5],DstMax[6],DstMax[7]	);
	
	printf("Avg : %d, %d, %d, %d, %d, %d, %d, %d\n",
		DstAvg[0],DstAvg[1],DstAvg[2],DstAvg[3],
		DstAvg[4],DstAvg[5],DstAvg[6],DstAvg[7]);
	return 0;
}

