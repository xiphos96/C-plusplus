// move.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) float SrcA[4] = {1.1,2.2,3.3,4.4};	//align memory
	__declspec(align(16)) float ResultA[4] = {0};

	float SrcB[4] = {1.1,2.2,3.3,4.4};	//unalign memory
	float ResultB[4] = {0};

	__asm
	{
		pushad
		movaps xmm0, SrcA		//xmm0 = SrcA
		movaps ResultA, xmm0	//ResultA = xmm0

		movups xmm1, SrcB		//xmm1 = SrcB
		movups ResultB, xmm1	//ResultB = xmm1

		popad
		
	}
	
	printf("Align Result : %.3f, %.3f, %.3f, %.3f\n",ResultA[3],ResultA[2],ResultA[1],ResultA[0]);
	printf("Unalign Result : %.3f, %.3f, %.3f, %.3f\n",ResultB[3],ResultB[2],ResultB[1],ResultB[0]);

	return 0;
}


