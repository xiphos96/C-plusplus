// Mul.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) float SrcA[4] = {1.1,2.2,3.3,4.4};
	__declspec(align(16)) float SrcB[4] = {4.4,3.3,2.2,1.1};
	__declspec(align(16)) float MULPSResult[4] = {0};	//packed 결과 출력
	__declspec(align(16)) float MULSSResult[4] = {0};	//scalar 결과 출력
	
	__asm
	{
		pushad
			
		movaps xmm0, SrcA	//xmm0 = SrcA
		movaps xmm1, xmm0	//xmm0 = xmm1
		movaps xmm2, SrcB	//xmm2 = SrcB
			
		mulps xmm0, xmm2	//xmm0 = xmm0 * xmm2 Packed
		mulss xmm1, xmm2	//xmm1 = xmm1 * xmm2 Scalar
			
		movaps MULPSResult, xmm0	//MULPSResult = xmm0
		movaps MULSSResult, xmm1	//MULSSResult = xmm1
		popad
		
	}
	printf("MULPS : %.3f,%.3f,%.3f,%.3f \n",
		MULPSResult[3],MULPSResult[2],MULPSResult[1],MULPSResult[0]);
	printf("MULSS : %.3f,%.3f,%.3f,%.3f \n",
		MULSSResult[3],MULSSResult[2],MULSSResult[1],MULSSResult[0]);
	return 0;
}


