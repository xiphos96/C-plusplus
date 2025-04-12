// add.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int IntArrayA[4] = { 1,2,3,4 };
	int IntArrayB[4] = { 5,6,7,8 };

	int IntResult[4] = {0};
	__asm
	{
		pushad
		movdqu xmm0, IntArrayA		//xmm0 = IntArrayA
		movdqu xmm1, IntArrayB		//xmm1 = IntArrayB
		paddd xmm0, xmm1		//xmm0 = xmm0 + xmm1
		movdqu IntResult, xmm0		//IntResult = xmm0
		popad
		
	}

	printf("AddResult : %d, %d, %d, %d \n"
,IntResult[3],IntResult[2],IntResult[1],IntResult[0]);
	return 0;
}

