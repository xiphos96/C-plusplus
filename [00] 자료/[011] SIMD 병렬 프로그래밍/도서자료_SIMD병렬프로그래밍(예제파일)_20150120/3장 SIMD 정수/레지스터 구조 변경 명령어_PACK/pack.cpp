// pack.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) int intArrayA[4] = {1,2,3,4};
	__declspec(align(16)) int intArrayB[4] = {1,2,3,4};
	
	__declspec(align(16)) short shortResult[8] = {0};		//0으로 초기화
	
	
	
	__asm
	{
		pushad
			
			movdqa xmm0, intArrayA	//xmm0 = IntArrayA;
			movdqa xmm1, intArrayB	//xmm1 = intArrayB;
			
			packssdw xmm0, xmm1
			
			movdqa shortResult, xmm0	//xmm0 = IntArrayB;
			popad
			
	}
	
	printf("short Result : %d,%d,%d,%d,%d,%d,%d,%d\n",
		shortResult[7],shortResult[6],shortResult[5],shortResult[4],
		shortResult[3],shortResult[2],shortResult[1],shortResult[0]);
	return 0;
}