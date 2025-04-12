// RSQRT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) float SrcA[4] = {1.0,2.0,3.0,4.0};
	__declspec(align(16)) float SrcB[4] = {4.0,3.0,2.0,1.0};
	__declspec(align(16)) float RSQRTPSResult[4] = {0};	//packed 결과 출력
	__declspec(align(16)) float RSQRTSSResult[4] = {0};	//scalar 결과 출력
	
	__asm
	{
		pushad
			
		movaps xmm0, SrcA	//xmm0 = SrcA
		movaps xmm1, xmm0	//xmm0 = xmm1
		movaps xmm2, SrcB	//xmm2 = SrcB
			
		rsqrtps xmm0, xmm2	//xmm0 = 1 /√ xmm2 Packed
		rsqrtss xmm1, xmm2	//xmm1 = 1 /√ xmm2 Scalar
			
		movaps RSQRTPSResult, xmm0	//RSQRTPSResult = xmm0
		movaps RSQRTSSResult, xmm1	//RSQRTSSResult = xmm1
		popad
		
	}
	printf("RSQRTPS : %.3f,%.3f,%.3f,%.3f \n",
		RSQRTPSResult[3],RSQRTPSResult[2],RSQRTPSResult[1],RSQRTPSResult[0]);
	printf("RSQRTSS : %.3f,%.3f,%.3f,%.3f \n",
		RSQRTSSResult[3],RSQRTSSResult[2],RSQRTSSResult[1],RSQRTSSResult[0]);
	return 0;
}

