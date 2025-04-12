// pcmp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	
	short ShortArrayA[8] = {1,2,3,4,5,6,7,8};
	short ShortArrayB[8] = {9,8,7,6,5,4,3,2};
	short MinResult[8] = {0};
	short MaxResult[8] = {0};
	
	__asm
	{
		pushad
		movdqu xmm0, ShortArrayA
		movdqu xmm1, xmm0
		movdqu xmm2, ShortArrayB
		
		pcmpeqw xmm0, xmm2
		pcmpgtw xmm1, xmm2
		movdqu MinResult, xmm0
		movdqu MaxResult, xmm1
		popad
		
	}
	printf("Equality Result : %x, %x, %x, %x, %x, %x, %x, %x \n",
		MinResult[7],MinResult[6],MinResult[5],MinResult[4],
		MinResult[3],MinResult[2],MinResult[1],MinResult[0]);
	
	printf("Greater than : %x, %x, %x, %x, %x, %x, %x, %x \n",
		MaxResult[7],MaxResult[6],MaxResult[5],MaxResult[4],
		MaxResult[3],MaxResult[2],MaxResult[1],MaxResult[0]);
	return 0;
}

