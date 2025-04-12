// pavgw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	short ValueA [8] = {1,2,3,4,5,6,7,8};
	short ValueB [8] = {0};
	short Result [8] = {0};
	__asm
	{
		pushad
		movdqu xmm0, ValueA
		movdqu xmm1, ValueB

		pavgw xmm0, xmm1

		movdqu Result, xmm0
		popad
		
	}
	printf("Result %d,%d,%d,%d,%d,%d,%d,%d\n",
		Result[7],Result[6],Result[5],Result[4],
		Result[3],Result[2],Result[1],Result[0]);
	return 0;
}


