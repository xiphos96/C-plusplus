// PSRAD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) int intArrayA[4] = {-100,-200,-300,-400};
	
	__declspec(align(16)) int intResult[4] = {0};		//0으로 초기화
	
	
	
	__asm
	{
		pushad
			
		movdqa xmm0, intArrayA	//xmm0 = IntArrayA;
			
		psrad xmm0, 2
			
		movdqa intResult, xmm0	//xmm0 = IntArrayB;
		popad
		
	}
	
	printf("Packed Shift Right Arithmetic : %d,%d,%d,%d\n",
		intResult[0],intResult[1],intResult[2],intResult[3]);
	return 0;
}
