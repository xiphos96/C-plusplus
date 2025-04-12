// Cvt.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int nSrc[8] = {10,20,30,40,50,60,70,80};
	float fSrc[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	
	int DstPStoI[8] = {0};
	float DstItoPS[8] = {0};
	double DstItoPD[4] = {0};
	
	__asm
	{
		vmovdqu ymm0, nSrc		;ymm0 = nSrc
		vcvtdq2ps ymm1, ymm0		;ymm1 = convertdq2ps(ymm0)
		vmovups DstItoPS, ymm1	;DstItoPS = ymm1 

		vmovdqu xmm0, nSrc		;ymm0 = nSrc
		vcvtdq2pd ymm1, xmm0		;ymm1 = convertdq2pd(ymm0)
		vmovups DstItoPD, ymm1	;DstItoPD = ymm1

		vmovups ymm0, fSrc		;ymm0 = nSrc
		vcvtps2dq ymm1, ymm0		;ymm1 = convertps2dq(ymm0)
		vmovups DstPStoI, ymm1	;DstPStoI = ymm1
	}

	printf("convert i to ps : ");
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstItoPS[0],DstItoPS[1],DstItoPS[2],DstItoPS[3],
		DstItoPS[4],DstItoPS[5],DstItoPS[6],DstItoPS[7]);

	printf("convert i to pd : %.2f, %.2f, %.2f, %.2f\n",
		DstItoPD[0],DstItoPD[1],DstItoPD[2],DstItoPD[3]);
	// float -> integer
	printf("convert ps to i : ");
	printf("%d, %d, %d, %d, %d, %d, %d, %d\n",
		DstPStoI[0],DstPStoI[1],DstPStoI[2],DstPStoI[3],
		DstPStoI[4],DstPStoI[5],DstPStoI[6],DstPStoI[7]);

	return 0;
}