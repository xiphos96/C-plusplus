// Pand.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int SrcA[4] = {1,0,1,0};
	int SrcB[4] = {1,1,0,0};

	int DstAnd[4] = {0};
	int DstOR[4] = {0};
	int DstXOR[4] = {0};
	int DstAndN[4] = {0};
		
	__asm
	{
		vmovdqu xmm0, SrcA
		vmovdqu xmm1, SrcB

		vpand xmm2, xmm0, xmm1
		vmovdqu DstAnd, xmm2

		vpor xmm2, xmm0, xmm1
		vmovdqu DstOR, xmm2

		vpxor xmm2, xmm0, xmm1
		vmovdqu DstXOR, xmm2

		vpandn xmm2, xmm0, xmm1
		vmovdqu DstAndN, xmm2
	}

	printf("And : %d, %d, %d, %d\n",
		DstAnd[0],DstAnd[1],DstAnd[2],DstAnd[3]);

	printf("OR : %d, %d, %d, %d\n",
		DstOR[0],DstOR[1],DstOR[2],DstOR[3]	);
		
	printf("XOR : %d, %d, %d, %d\n",
		DstXOR[0],DstXOR[1],DstXOR[2],DstXOR[3]);

	printf("DstAndN : %d, %d, %d, %d\n",
		DstAndN[0],DstAndN[1],DstAndN[2],DstAndN[3]);
	
	return 0;
}

