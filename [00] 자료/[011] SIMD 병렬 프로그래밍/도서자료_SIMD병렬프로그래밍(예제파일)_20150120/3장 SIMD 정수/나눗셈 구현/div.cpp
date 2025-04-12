// div.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	short A = 149;
	short B = 9;
	short R = A / B;

	printf("C Div : %d / %d = %d \n", A, B, R);

	short ShortArrayA[8] = {149,149,149,149,149,149,149,149};
	short ShortArrayB[8] = {0};
	short ShortResult[8] = {0};
	
	short multiplier = 256 / 9;	//256/9=28
	for (int i = 0; i < 8; i++)
		ShortArrayB[i] = multiplier;	//28 package생성
	
	__asm
	{
		pushad
		movdqu xmm0, ShortArrayA
		movdqu xmm1, ShortArrayB
		pmullw xmm0, xmm1			//28을 곱한다.
		psraw xmm0, 8				//256으로 나눈다.
		movdqu ShortResult, xmm0
		popad
		
	}
	printf("DivResult : %d, %d, %d, %d, %d, %d, %d, %d \n",
		ShortResult[7],ShortResult[6],ShortResult[5],ShortResult[4],
		ShortResult[3],ShortResult[2],ShortResult[1],ShortResult[0]);
	return 0;
}

