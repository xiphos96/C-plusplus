// pshufd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int ValueA [4] = {0};
	int ValueB [4] = {0,1,2,3};
	int Result [4] = {0};
	
	__asm
	{
		pushad
		movdqu xmm0, ValueA
		movdqu xmm1, ValueB
			
		pshufd xmm0, xmm1, 00111011b
			
		movdqu Result, xmm0
			
		popad
		
	}
	printf("Shuffle Result : %d,%d,%d,%d\n",
			Result[3],Result[2],Result[1],Result[0]);
	return 0;
}


