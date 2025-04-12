// Logical.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) int IntArrayA[4] = {1,1,0,0};
	__declspec(align(16)) int IntArrayB[4] = {1,0,1,0};

	__declspec(align(16)) int ANDResult[4] = {0};		//0으로 초기화
	__declspec(align(16)) int ORResult[4] = {0};		//0으로 초기화
	__declspec(align(16)) int XORResult[4] = {0};		//0으로 초기화
	__declspec(align(16)) int ANDNOTResult[4] = {0};		//0으로 초기화

	__asm
	{
		pushad

		movdqa xmm0, IntArrayA	//xmm0 = IntArrayA;
		movdqa xmm1, xmm0		//xmm1 = xmm0;
		movdqa xmm2, xmm0		//xmm2 = xmm0;
		movdqa xmm3, xmm0		//xmm3 = xmm0;
		movdqa xmm4, IntArrayB	//xmm4 = IntArrayB;
			
		pand xmm0,xmm4			//AND 연산
		por xmm1,xmm4			//OR 연산
		pxor xmm2,xmm4			//XOR 연산
		pandn xmm3,xmm4			//ANDNOT 연산

		movdqa ANDResult, xmm0		//ANDResult = xmm0;
		movdqa ORResult, xmm1		//ORResult = xmm1;
		movdqa XORResult, xmm2		//XORResult = xmm2;
		movdqa ANDNOTResult, xmm3	//ANDNOTResult = xmm3;
		
		popad
		
	}
	printf("AND Result : %d,%d,%d,%d\n",	ANDResult[0],ANDResult[1],ANDResult[2],ANDResult[3]);
	printf("OR Result : %d,%d,%d,%d\n",	ORResult[0],ORResult[1],ORResult[2],ORResult[3]);
	printf("XOR Result : %d,%d,%d,%d\n",	XORResult[0],XORResult[1],XORResult[2],XORResult[3]);
	printf("ANDNOT Result : %d,%d,%d,%d\n",	ANDNOTResult[0],ANDNOTResult[1],ANDNOTResult[2],ANDNOTResult[3]);
	return 0;
}

