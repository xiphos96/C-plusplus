// vinsertf128.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	float fSrc[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	
	float DInsert0[8] = {0};
	float DInsert1[8] = {0};

	__asm
	{
		vmovups xmm1, [fSrc]
		vmovups xmm2, [fSrc+16]
		vxorps ymm0, ymm0, ymm0
			
		vinsertf128 ymm0,ymm0,xmm1,0 
		vmovups DInsert0, ymm0

		vinsertf128 ymm0,ymm0,xmm2,1 
		vmovups DInsert1, ymm0
	}
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DInsert0[0],DInsert0[1],DInsert0[2],DInsert0[3],
		DInsert0[4],DInsert0[5],DInsert0[6],DInsert0[7]);
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DInsert1[0],DInsert1[1],DInsert1[2],DInsert1[3],
		DInsert1[4],DInsert1[5],DInsert1[6],DInsert1[7]);

	return 0;
}

