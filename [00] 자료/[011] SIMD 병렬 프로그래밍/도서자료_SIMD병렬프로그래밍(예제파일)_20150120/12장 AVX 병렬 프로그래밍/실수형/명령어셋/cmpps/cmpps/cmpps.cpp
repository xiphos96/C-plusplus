// cmpps.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

	float SrcA[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	float SrcB[8] = {2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0};

	float DstEq[8] = {0};
	float DstLt[8] = {0};
	float DstLe[8] = {0};
	float DstGt[8] = {0};
	float DstGe[8] = {0};
	
	__asm
	{
		vmovups ymm0, SrcA
		vmovups ymm1, SrcB

		vcmpps ymm2, ymm0, ymm1, 0
		vmovups DstEq, ymm2

		vcmpps ymm2, ymm0, ymm1, 1
		vmovups DstLt, ymm2

		vcmpps ymm2, ymm0, ymm1, 2
		vmovups DstLe, ymm2

		vcmpps ymm2, ymm0, ymm1, 14
		vmovups DstGt, ymm2

		vcmpps ymm2, ymm0, ymm1, 13
		vmovups DstGe, ymm2
	}

	printf("Equal : ");
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstEq[0],DstEq[1],DstEq[2],DstEq[3],DstEq[4],DstEq[5],DstEq[6],DstEq[7]);

	printf("Less Than : ");
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstLt[0],DstLt[1],DstLt[2],DstLt[3],DstLt[4],DstLt[5],DstLt[6],DstLt[7]);

	printf("Less Equal : ");
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstLe[0],DstLe[1],DstLe[2],DstLe[3],DstLe[4],DstLe[5],DstLe[6],DstLe[7]);

	printf("Greater than : ");
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstGt[0],DstGt[1],DstGt[2],DstGt[3],DstGt[4],DstGt[5],DstGt[6],DstGt[7]);

	printf("Greater Equal : ");
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstGe[0],DstGe[1],DstGe[2],DstGe[3],DstGe[4],DstGe[5],DstGe[6],DstGe[7]);

	return 0;
}
