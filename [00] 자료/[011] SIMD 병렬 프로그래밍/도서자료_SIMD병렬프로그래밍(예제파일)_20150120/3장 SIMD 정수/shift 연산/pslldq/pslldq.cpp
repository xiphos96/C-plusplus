// pslldq.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) char byteArrayA[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	
	__declspec(align(16)) char LeftResult[16] = {0};		//0으로 초기화
	__declspec(align(16)) char RightResult[16] = {0};		//0으로 초기화
	
	
	
	__asm
	{
		pushad
			
			movdqa xmm0, byteArrayA	//xmm0 = byteArrayA;
			movdqa xmm1, xmm0	//xmm1 = xmm0;
			
			pslldq xmm0, 2
			
			psrldq xmm1, 2

			movdqa LeftResult, xmm0		//LeftResult = xmm0;
			movdqa RightResult, xmm1	//RightResult = xmm1;

			popad
			
	}
	
	printf("Shift Double Quadword Left Logical : \n %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
		LeftResult[15],LeftResult[14],LeftResult[13],LeftResult[12],
		LeftResult[11],LeftResult[10],LeftResult[9],LeftResult[8],
		LeftResult[7],LeftResult[6],LeftResult[5],LeftResult[4],
		LeftResult[3],LeftResult[2],LeftResult[1],LeftResult[0]);

	printf("Shift Double Quadword Right Logical : \n %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
		RightResult[15],RightResult[14],RightResult[13],RightResult[12],
		RightResult[11],RightResult[10],RightResult[9],RightResult[8],
		RightResult[7],RightResult[6],RightResult[5],RightResult[4],
		RightResult[3],RightResult[2],RightResult[1],RightResult[0]);
	return 0;
}

