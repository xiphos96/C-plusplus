// movealign.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{

	__declspec(align(16)) short ShortArrayA[8] = {1,2,3,4,5,6,7,8};
	__declspec(align(16)) short ShortArrayB[8] = {0};		//0으로 초기화
	__asm
	{
		pushad
		movdqa  xmm0, ShortArrayA	//xmm0 = ShortArrayA
		movdqa  ShortArrayB, xmm0	//ShortArrayB = xmm0
		popad
		
	}
	printf("ShortArrayB : %d,%d,%d,%d,%d,%d,%d,%d\n",
		ShortArrayB[7],ShortArrayB[6],ShortArrayB[5],ShortArrayB[4],
		ShortArrayB[3],ShortArrayB[2],ShortArrayB[1],ShortArrayB[0]);
	return 0;
}
