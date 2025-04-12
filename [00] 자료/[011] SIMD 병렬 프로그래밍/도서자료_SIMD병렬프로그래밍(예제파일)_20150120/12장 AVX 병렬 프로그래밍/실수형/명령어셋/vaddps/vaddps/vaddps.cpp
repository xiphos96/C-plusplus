// vaddps.cpp : ÄÜ¼Ö ÀÀ¿ë ÇÁ·Î±×·¥¿¡ ´ëÇÑ ÁøÀÔÁ¡À» Á¤ÀÇÇÕ´Ï´Ù.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	float SrcA[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	float SrcB[8] = {2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0};

	float DstAdd[8] = {0};	//µ¡¼À °á°ú ÀÔ·Â
	float DstSub[8] = {0};	//»¬¼À °á°ú ÀÔ·Â
	float DstMul[8] = {0};	//°ö¼À °á°ú ÀÔ·Â
	float DstDiv[8] = {0};	//³ª´°¼À °á°ú ÀÔ·Â
	
	__asm
	{
		vmovups ymm0, SrcA		;ymm0 = SrcA
		vmovups ymm1, SrcB		;ymm1 = SrcB

		vaddps ymm2, ymm0, ymm1	;ymm2 = ymm0+ymm1
		vmovups DstAdd, ymm2		;DstAdd = ymm2

		vsubps ymm2, ymm0, ymm1	;ymm2 = ymm0-ymm1
		vmovups DstSub, ymm2		;DstSub = ymm2

		vmulps ymm2, ymm0, ymm1	;ymm2 = ymm0*ymm1
		vmovups DstMul, ymm2		;DstMul = ymm2

		vdivps ymm2, ymm0, ymm1	;ymm2 = ymm0/ymm1
		vmovups DstDiv, ymm2		;DstDiv = ymm2
	}
	//µ¡¼À °á°ú ÇÁ¸°Æ®
	printf("Add : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstAdd[0],DstAdd[1],DstAdd[2],DstAdd[3],
		DstAdd[4],DstAdd[5],DstAdd[6],DstAdd[7]);
	//»¬¼À °á°ú ÇÁ¸°Æ®
	printf("Sub : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstSub[0],DstSub[1],DstSub[2],DstSub[3],
		DstSub[4],DstSub[5],DstSub[6],DstSub[7]);
	//°ö¼À °á°ú ÇÁ¸°Æ®
	printf("Mul : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstMul[0],DstMul[1],DstMul[2],DstMul[3],
		DstMul[4],DstMul[5],DstMul[6],DstMul[7]);
	//³ª´°¼À °á°ú ÇÁ¸°Æ®
	printf("Div : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstDiv[0],DstDiv[1],DstDiv[2],DstDiv[3],
		DstDiv[4],DstDiv[5],DstDiv[6],DstDiv[7]);
	
	return 0;
}

