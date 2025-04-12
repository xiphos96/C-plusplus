// Div.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) float SrcA[4] = {1.1,2.2,3.3,4.4};
	__declspec(align(16)) float SrcB[4] = {4.4,3.3,2.2,1.1};
	__declspec(align(16)) float DIVPSResult[4] = {0};	//packed 결과 출력
	__declspec(align(16)) float DIVSSResult[4] = {0};	//scalar 결과 출력
	
	__asm
	{
		pushad
			
		movaps xmm0, SrcA	//xmm0 = SrcA
		movaps xmm1, xmm0	//xmm0 = xmm1
		movaps xmm2, SrcB	//xmm2 = SrcB
		
		divps xmm0, xmm2	//xmm0 = xmm0 / xmm2 Packed
		divss xmm1, xmm2	//xmm1 = xmm1 / xmm2 Scalar
		
		movaps DIVPSResult, xmm0	//DIVPSResult = xmm0
		movaps DIVSSResult, xmm1	//DIVSSResult = xmm1
		popad
		
	}
	printf("DIVPS : %.3f,%.3f,%.3f,%.3f \n",
		DIVPSResult[3],DIVPSResult[2],DIVPSResult[1],DIVPSResult[0]);
	printf("DIVSS : %.3f,%.3f,%.3f,%.3f \n",
		DIVSSResult[3],DIVSSResult[2],DIVSSResult[1],DIVSSResult[0]);
	return 0;
}

