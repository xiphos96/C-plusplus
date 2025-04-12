// vshufps.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	__declspec(align(32)) float fSrcA[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	__declspec(align(32)) float fSrcB[8] = {9, 10, 11, 12, 13, 14, 15, 16};
		
	__declspec(align(32)) float DstPS[8] = {0};


	__asm
	{
		vmovaps ymm0, fSrcA
		vmovaps ymm1, fSrcB

		vshufps ymm2, ymm1, ymm0, 10011100b
		vmovaps DstPS, ymm2
	}
	printf("vshufps : ");
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstPS[0],DstPS[1],DstPS[2],DstPS[3],
		DstPS[4],DstPS[5],DstPS[6],DstPS[7]);
	
	return 0;
}


