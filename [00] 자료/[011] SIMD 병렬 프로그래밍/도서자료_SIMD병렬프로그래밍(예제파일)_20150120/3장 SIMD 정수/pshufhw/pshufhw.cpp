// pshufhw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	short ValueA [8] = {0};
	short ValueB [8] = {0,1,2,3,4,5,6,7};
	short HighResult [8] = {0};
	short LowResult [8] = {0};
	__asm
	{
		pushad
		movdqu xmm0, ValueA
		movdqu xmm1, ValueB
			
		pshufhw xmm0, xmm1, 00111011b
			
		movdqu HighResult, xmm0

		pshuflw xmm0, xmm1, 10001100b
		
		movdqu LowResult, xmm0

		popad
		
	}
	printf("Shuffle High Result : %d,%d,%d,%d,%d,%d,%d,%d\n",
		HighResult[7],HighResult[6],HighResult[5],HighResult[4],
		HighResult[3],HighResult[2],HighResult[1],HighResult[0]);

	printf("Shuffle Low Result : %d,%d,%d,%d,%d,%d,%d,%d\n",
		LowResult[7],LowResult[6],LowResult[5],LowResult[4],
		LowResult[3],LowResult[2],LowResult[1],LowResult[0]);
	return 0;
}
