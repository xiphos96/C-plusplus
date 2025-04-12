// zeroall.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	double Data[4] = {1,2,3,4};
	double Ret0[4] = {0};
	double Ret7[4] = {0};
	double ZURet0[4] = {0};
	double ZURet7[4] = {0};
	double ZRet0[4] = {0};
	double ZRet7[4] = {0};
	__asm
	{
		vmovups ymm0, Data
		vmovaps ymm7, ymm0
		vmovups Ret0, ymm0
		vmovups Ret7, ymm7
		
		vzeroupper

		vmovups ZURet0, ymm0
		vmovups ZURet7, ymm7

		vzeroall
		vmovups ZRet0, ymm0
		vmovups ZRet7, ymm7
	}
	printf("%.2f, %.2f, %.2f, %.2f\n",
		Ret0[3],Ret0[2],Ret0[1],Ret0[0]);
	printf("%.2f, %.2f, %.2f, %.2f\n",
		Ret7[3],Ret7[2],Ret7[1],Ret7[0]);
	
	printf("\nZero Upper\n%.2f, %.2f, %.2f, %.2f\n",
		ZURet0[3],ZURet0[2],ZURet0[1],ZURet0[0]);
	printf("%.2f, %.2f, %.2f, %.2f\n",
		ZURet7[3],ZURet7[2],ZURet7[1],ZURet7[0]);

	printf("\nZero All\n%.2f, %.2f, %.2f, %.2f\n",
		ZRet0[3],ZRet0[2],ZRet0[1],ZRet0[0]);
	printf("%.2f, %.2f, %.2f, %.2f\n",
		ZRet7[3],ZRet7[2],ZRet7[1],ZRet7[0]);
	return 0;
}

