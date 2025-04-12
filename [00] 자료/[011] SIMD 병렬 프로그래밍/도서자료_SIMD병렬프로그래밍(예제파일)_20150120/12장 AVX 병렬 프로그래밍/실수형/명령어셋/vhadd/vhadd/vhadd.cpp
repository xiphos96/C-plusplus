// vhadd.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	__declspec(align(32)) float fSrcA[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	__declspec(align(32)) float fSrcB[8] = {2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0};
		
	__declspec(align(32)) float HaddPS[8] = {0};
	__declspec(align(32)) float HsubPS[8] = {0};

	__declspec(align(32)) double dSrcA[4] = {1.0,2.0,3.0,4.0};
	__declspec(align(32)) double dSrcB[4] = {2.0,2.0,2.0,2.0};
		
	__declspec(align(32)) double HaddPD[4] = {0};
	__declspec(align(32)) double HsubPD[4] = {0};

	__asm
	{
		vmovaps ymm0, fSrcA			;ymm0 = fSrcA
		vmovaps ymm1, fSrcB			;ymm1 = fSrcB
			
		vhaddps ymm2, ymm1, ymm0		;ymm2[0] = ymm1[0]+ymm1[1]
		vmovaps HaddPS, ymm2			;HaddPS = ymm2

		vhsubps ymm2, ymm1, ymm0		;ymm2[0] = ymm1[0]-ymm1[1]
		vmovaps HsubPS, ymm2			;HsubPS = ymm2

		vmovapd ymm0, dSrcA			;ymm0 = dSrcA
		vmovapd ymm1, dSrcB			;ymm0 = dSrcB

		vhaddpd ymm2, ymm1, ymm0		;ymm2[0] = ymm1[0]+ymm1[1]
		vmovapd HaddPD, ymm2			;HaddPD = ymm2

		vhsubpd ymm2, ymm1, ymm0		;ymm2[0] = ymm1[0]-ymm1[1]
		vmovapd HsubPD, ymm2			;HsubPD = ymm2
	}
	//HaddPS 결과 출력
	printf("HaddPS : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		HaddPS[0],HaddPS[1],HaddPS[2],HaddPS[3],
		HaddPS[4],HaddPS[5],HaddPS[6],HaddPS[7]);
	//HsubPS 결과 출력
	printf("HsubPS : %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		HsubPS[0],HsubPS[1],HsubPS[2],HsubPS[3],
		HsubPS[4],HsubPS[5],HsubPS[6],HsubPS[7]);
	//HaddPD 결과 출력
	printf("HaddPD %.2f, %.2f, %.2f, %.2f\n",
		HaddPD[0],HaddPD[1],HaddPD[2],HaddPD[3]);
	//HsubPD 결과 출력
	printf("HsubPD %.2f, %.2f, %.2f, %.2f\n",
		HsubPD[0],HsubPD[1],HsubPD[2],HsubPD[3]);

	return 0;
}

