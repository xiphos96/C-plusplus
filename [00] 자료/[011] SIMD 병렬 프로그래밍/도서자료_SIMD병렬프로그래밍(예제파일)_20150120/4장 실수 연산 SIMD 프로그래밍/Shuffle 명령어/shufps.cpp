// shufps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	float SrcA[4] = {1,2,3,4};
	float SrcB[4] = {5,6,7,8};
	float Result[4] = {0};
	__asm
	{
		pushad
		movups xmm0, SrcA
		movups xmm1, SrcB

		shufps xmm0, xmm1, 	10011100b

		movups Result,xmm0
		popad
		
	}
	printf("SHUFPS : %.3f, %.3f, %.3f, %.3f \n", Result[3], Result[2], Result[1], Result[0]);
	return 0;
}

