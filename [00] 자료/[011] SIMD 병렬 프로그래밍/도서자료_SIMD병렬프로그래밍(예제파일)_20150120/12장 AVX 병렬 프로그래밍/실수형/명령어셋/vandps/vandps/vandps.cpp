// vandps.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	__declspec(align(32)) float SrcA[8] = {1.0,1.0,0.0,0.0,1.0,1.0,0.0,0.0};
	__declspec(align(32)) float SrcB[8] = {1.0,0.0,1.0,0.0,1.0,0.0,1.0,0.0};
	__declspec(align(32)) float DstAnd[8] = {0};
	__declspec(align(32)) float DstOr[8] = {0};
	__declspec(align(32)) float DstXor[8] = {0};
	__declspec(align(32)) float DstAndn[8] = {0};

	__asm
	{
		vmovaps ymm0, SrcA		;ymm0 = SrcA
		vmovaps ymm1, SrcB		;ymm1 = SrcB

		vandps ymm2, ymm0, ymm1	;ymm2 = ymm0 & ymm1
		vmovaps DstAnd, ymm2		;DstAnd = ymm2

		vorps ymm2, ymm0, ymm1	;ymm2 = ymm0 | ymm1
		vmovaps DstOr, ymm2		;DstAnd = ymm2

		vxorps ymm2, ymm0, ymm1	;ymm2 = ymm0 ^ ymm1
		vmovaps DstXor, ymm2		;DstAnd = ymm2

		vandnps ymm2, ymm0, ymm1	;ymm2 = ~ymm0 & ymm1
		vmovaps DstAndn, ymm2		;DstAndn = ymm2
	}

	printf("And : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstAnd[0],DstAnd[1],DstAnd[2],DstAnd[3],
		DstAnd[4],DstAnd[5],DstAnd[6],DstAnd[7]);
	
	printf("Or : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstOr[0],DstOr[1],DstOr[2],DstOr[3],
		DstOr[4],DstOr[5],DstOr[6],DstOr[7]);
	
	printf("Xor : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstXor[0],DstXor[1],DstXor[2],DstXor[3],
		DstXor[4],DstXor[5],DstXor[6],DstXor[7]);
	
	printf("And Not : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstAndn[0],DstAndn[1],DstAndn[2],DstAndn[3],
		DstAndn[4],DstAndn[5],DstAndn[6],DstAndn[7]);
	return 0;
}

