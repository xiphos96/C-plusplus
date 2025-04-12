// sub.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) float SrcA[4] = {1.1,2.2,3.3,4.4};
	__declspec(align(16)) float SrcB[4] = {4.4,3.3,2.2,1.1};
	__declspec(align(16)) float SUBPSResult[4] = {0};	//packed 결과 출력
	__declspec(align(16)) float SUBSSResult[4] = {0};	//scalar 결과 출력

	__asm
	{
		pushad
			
		movaps xmm0, SrcA	//xmm0 = SrcA
		movaps xmm1, xmm0	//xmm0 = xmm1
		movaps xmm2, SrcB	//xmm2 = SrcB
			
		subps xmm0, xmm2	//xmm0 = xmm0 - xmm2 Packed
		subss xmm1, xmm2	//xmm1 = xmm1 - xmm2 Scalar
			
		movaps SUBPSResult, xmm0	//SUBPSResult = xmm0
		movaps SUBSSResult, xmm1	//SUBSSResult = xmm1
		popad
		
	}
	printf("SUBPS : %.3f,%.3f,%.3f,%.3f \n",
		SUBPSResult[3],SUBPSResult[2],SUBPSResult[1],SUBPSResult[0]);
	printf("SUBSS : %.3f,%.3f,%.3f,%.3f \n",
		SUBSSResult[3],SUBSSResult[2],SUBSSResult[1],SUBSSResult[0]);
	return 0;
}

