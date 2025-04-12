// MinMax.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	
	float fSrcA[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	float fSrcB[8] = {2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0};

	float fDstMin[8] = {0};
	float fDstMax[8] = {0};

	double dSrcA[4] = {1.0,2.0,3.0,4.0};
	double dSrcB[4] = {2.0,2.0,2.0,2.0};

	double dDstMin[4] = {0};
	double dDstMax[4] = {0};
	__asm
	{
		vmovups ymm0, fSrcA
		vmovups ymm1, fSrcB

		vminps ymm2, ymm0, ymm1
		vmovups fDstMin, ymm2

		vmaxps ymm2, ymm0, ymm1
		vmovups fDstMax, ymm2

		vmovupd ymm0, dSrcA
		vmovupd ymm1, dSrcB

		vminpd ymm2, ymm0, ymm1
		vmovups dDstMin, ymm2

		vmaxpd ymm2, ymm0, ymm1
		vmovupd dDstMax, ymm2
	}

	printf("float Min : ");
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		fDstMin[0],fDstMin[1],fDstMin[2],fDstMin[3],
		fDstMin[4],fDstMin[5],fDstMin[6],fDstMin[7]);

	printf("float Max : ");
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		fDstMax[0],fDstMax[1],fDstMax[2],fDstMax[3],
		fDstMax[4],fDstMax[5],fDstMax[6],fDstMax[7]);

	printf("double Min : ");
	printf("%.2f, %.2f, %.2f, %.2f\n",
		dDstMin[0],dDstMin[1],dDstMin[2],dDstMin[3]);

	printf("double Max : ");
	printf("%.2f, %.2f, %.2f, %.2f\n",
		dDstMax[0],dDstMax[1],dDstMax[2],dDstMax[3]);
	return 0;
}

