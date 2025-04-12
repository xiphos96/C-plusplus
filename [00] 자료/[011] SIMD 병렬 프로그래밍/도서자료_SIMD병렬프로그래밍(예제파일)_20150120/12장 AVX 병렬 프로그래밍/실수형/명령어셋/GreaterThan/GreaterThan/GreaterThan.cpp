// GreaterThan.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	float SrcA[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	float SrcB[8] = {2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0};

	float DstGt[8] = {0};
	
	__asm
	{
		vmovups ymm0, SrcA			;ymm0 = SrcA
		vmovups ymm1, SrcB			;ymm1 = SrcB

		vcmpgtps ymm2, ymm0, ymm1		;ymm2 = if( ymm0 > ymm1)
		vandps	ymm2, ymm2, ymm0		;ymm2 = ymm2 & ymm0
		vmovups DstGt, ymm2			;DstGt = ymm2

	}
	
	//Greater than 결과 출력
	printf("select gt : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstGt[0],DstGt[1],DstGt[2],DstGt[3],
		DstGt[4],DstGt[5],DstGt[6],DstGt[7]);

	return 0;
}