// BitLogic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) float	SourceA[4] = {1,0,1,0};
	__declspec(align(16)) float	SourceB[4] = {1,1,0,0};

	__declspec(align(16)) float	AndResult[4] = {0};
	__declspec(align(16)) float	ORResult[4] = {0};
	__declspec(align(16)) float	XORResult[4] = {0};
	__declspec(align(16)) float	ANDNOTResult[4] = {0};

	__asm
	{
		pushad
		movaps xmm0, SourceA
		movaps xmm1, xmm0
		movaps xmm2, xmm0
		movaps xmm3, xmm0
		movaps xmm4, SourceB

		andps xmm0, xmm4
		orps xmm1, xmm4
		xorps xmm2, xmm4
		andnps xmm3, xmm4

		movaps AndResult, xmm0
		movaps ORResult, xmm1
		movaps XORResult, xmm2
		movaps ANDNOTResult, xmm3

		popad
		
	}

	printf("AND : %.2f, %.2f, %.2f, %.2f\n", AndResult[3], AndResult[2], AndResult[1], AndResult[0]);
	printf("OR : %.2f, %.2f, %.2f, %.2f\n", ORResult[3], ORResult[2], ORResult[1], ORResult[0]);
	printf("XOR : %.2f, %.2f, %.2f, %.2f\n", XORResult[3], XORResult[2], XORResult[1], XORResult[0]);
	printf("ANDNOT : %.2f, %.2f, %.2f, %.2f\n", ANDNOTResult[3], ANDNOTResult[2], ANDNOTResult[1], ANDNOTResult[0]);

	return 0;
}

