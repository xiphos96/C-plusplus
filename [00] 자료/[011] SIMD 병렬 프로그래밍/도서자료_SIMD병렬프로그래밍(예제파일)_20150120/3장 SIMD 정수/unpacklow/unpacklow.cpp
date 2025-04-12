// unpacklow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) short shortArrayA[8] = {1,2,3,4,5,6,7,8};
	__declspec(align(16)) short shortArrayB[8] = {0,0,0,0,1,1,1,1};

	__declspec(align(16)) short shortResult[8] = {0};		//0으로 초기화
	__declspec(align(16)) int Result[8] = {0};		//0으로 초기화
	
	
	__asm
	{
		pushad
			
			movdqa xmm0, shortArrayA	//xmm0 = IntArrayA;
			movdqa xmm1, shortArrayB	//xmm1 = xmm0;
			
			punpcklwd xmm0, xmm1
			
			movdqa shortResult, xmm0	//xmm4 = IntArrayB;
			movdqa Result, xmm0	//xmm4 = IntArrayB;
			popad
			
	}
	
	printf("short Result : %d,%d,%d,%d,%d,%d,%d,%d\n",
		shortResult[7],shortResult[6],shortResult[5],shortResult[4],
		shortResult[3],shortResult[2],shortResult[1],shortResult[0]);
	printf("Int Result : %d,%d,%d,%d\n",Result[3],Result[2],Result[1],Result[0]);
	return 0;
}
