// RCP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) float SrcA[4] = {1.1,2.2,3.3,4.4};
	__declspec(align(16)) float SrcB[4] = {4.4,3.3,2.2,1.1};
	__declspec(align(16)) float RCPPSResult[4] = {0};	//packed 결과 출력
	__declspec(align(16)) float RCPSSResult[4] = {0};	//scalar 결과 출력
	
	__asm
	{
		pushad
			
			movaps xmm0, SrcA	//xmm0 = SrcA
			movaps xmm1, xmm0	//xmm0 = xmm1
			movaps xmm2, SrcB	//xmm2 = SrcB
			
			rcpps xmm0, xmm2	//xmm0 = xmm0 / xmm2 Packed
			rcpss xmm1, xmm2	//xmm1 = xmm1 / xmm2 Scalar
			
			movaps RCPPSResult, xmm0	//RCPPSResult = xmm0
			movaps RCPSSResult, xmm1	//RCPSSResult = xmm1
			popad
			
	}
	printf("RCPPS : %.3f,%.3f,%.3f,%.3f \n",
		RCPPSResult[3],RCPPSResult[2],RCPPSResult[1],RCPPSResult[0]);
	printf("RCPSS : %.3f,%.3f,%.3f,%.3f \n",
		RCPSSResult[3],RCPSSResult[2],RCPSSResult[1],RCPSSResult[0]);
	return 0;
}


