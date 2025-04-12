// sqrt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) float SrcA[4] = {1.0,2.0,3.0,4.0};
	__declspec(align(16)) float SrcB[4] = {4.0,3.0,2.0,1.0};
	__declspec(align(16)) float SQRTPSResult[4] = {0};	//packed 결과 출력
	__declspec(align(16)) float SQRTSSResult[4] = {0};	//scalar 결과 출력
	
	__asm
	{
		pushad
			
			movaps xmm0, SrcA	//xmm0 = SrcA
			movaps xmm1, xmm0	//xmm0 = xmm1
			movaps xmm2, SrcB	//xmm2 = SrcB
			
			sqrtps xmm0, xmm2	//xmm0 = √ xmm2 Packed
			sqrtss xmm1, xmm2	//xmm1 = √ xmm2 Scalar
			
			movaps SQRTPSResult, xmm0	//SQRTPSResult = xmm0
			movaps SQRTSSResult, xmm1	//SQRTSSResult = xmm1
			popad
			
	}
	printf("SQRTPS : %.3f,%.3f,%.3f,%.3f \n",
		SQRTPSResult[3],SQRTPSResult[2],SQRTPSResult[1],SQRTPSResult[0]);
	printf("SQRTSS : %.3f,%.3f,%.3f,%.3f \n",
		SQRTSSResult[3],SQRTSSResult[2],SQRTSSResult[1],SQRTSSResult[0]);
	return 0;
}

