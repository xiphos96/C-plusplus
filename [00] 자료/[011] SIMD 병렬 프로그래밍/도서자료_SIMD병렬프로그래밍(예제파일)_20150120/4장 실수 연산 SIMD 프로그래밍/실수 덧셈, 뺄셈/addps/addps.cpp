// addps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) float SrcA[4] = {1.1,2.2,3.3,4.4};
	__declspec(align(16)) float SrcB[4] = {4.4,3.3,2.2,1.1};
	__declspec(align(16)) float ADDPSResult[4] = {0};
	__declspec(align(16)) float ADDSSResult[4] = {0};
	__asm
	{
		pushad

		movaps xmm0, SrcA	//xmm0 = SrcA
		movaps xmm1, xmm0	//xmm0 = xmm1
		movaps xmm2, SrcB	//xmm2 = SrcB

		addps xmm0, xmm2	//xmm0 = xmm0 + xmm2 Packed
		addss xmm1, xmm2	//xmm0 = xmm0 + xmm2 Scalar

		movaps ADDPSResult, xmm0	//ADDPSResult = xmm0
		movaps ADDSSResult, xmm1	//ADDSSResult = xmm1
		popad
		
	}
	printf("ADDPS : %.3f,%.3f,%.3f,%.3f \n",
		ADDPSResult[3],ADDPSResult[2],ADDPSResult[1],ADDPSResult[0]);
	printf("ADDSS : %.3f,%.3f,%.3f,%.3f \n",
		ADDSSResult[3],ADDSSResult[2],ADDSSResult[1],ADDSSResult[0]);
	return 0;
}

