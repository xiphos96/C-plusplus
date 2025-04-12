// pmul.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	
	short ShortArrayA[8] = {1,2,3,4,5,6,7,8};
	short ShortArrayB[8] = {2,2,2,2,2,2,2,2};
	short ShortResult[8] = {0};

	__asm
	{
		pushad
		movdqu xmm0, ShortArrayA
		movdqu xmm1, ShortArrayB
		pmullw xmm0, xmm1
		movdqu ShortResult, xmm0
		popad
		
	}
	printf("MulResult : %d, %d, %d, %d, %d, %d, %d, %d \n",
		ShortResult[7],ShortResult[6],ShortResult[5],ShortResult[4],
		ShortResult[3],ShortResult[2],ShortResult[1],ShortResult[0]);
	return 0;
}


