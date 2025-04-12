// vmath.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	__declspec(align(32)) float Src[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
		
	__declspec(align(32)) float DstSqrt[8] = {0};
	__declspec(align(32)) float DstRcp[8] = {0};
	__declspec(align(32)) float DstRsqrt[8] = {0};
	
	__asm
	{
		vmovaps ymm0, Src			;ymm1 = Src

		vsqrtps ymm1, ymm0		;ymm1 = √ymm0
		vmovaps DstSqrt, ymm1		;DstSqrt = ymm1

		vrcpps ymm1, ymm0			;ymm1 = 1/ymm0
		vmovaps DstRcp, ymm1		;DstRcp = ymm1

		vrsqrtps ymm1, ymm0		;ymm1 = 1/√ymm0
		vmovaps DstRsqrt, ymm1	;DstRsqrt = ymm1
	}
	//RCP 결과 출력
	printf("Rcp : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstRcp[0],DstRcp[1],DstRcp[2],DstRcp[3],
		DstRcp[4],DstRcp[5],DstRcp[6],DstRcp[7]);
	//Sqrt 결과 출력
	printf("Sqrt : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstSqrt[0],DstSqrt[1],DstSqrt[2],DstSqrt[3],
		DstSqrt[4],DstSqrt[5],DstSqrt[6],DstSqrt[7]);
	//Rsqrt 결과 출력
	printf("Rsqrt : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstRsqrt[0],DstRsqrt[1],DstRsqrt[2],DstRsqrt[3],
		DstRsqrt[4],DstRsqrt[5],DstRsqrt[6],DstRsqrt[7]);
	return 0;
}

