// pextrw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	short SourceA[8] = {1,2,3,4,5,6,7,8};
	short SourceB[8] = {0};

	short Result[8] = {0};

	int Value = 0;

	__asm
	{
		pushad
		movdqu xmm0, SourceA
		pextrw eax, xmm0, 2
		mov Value, eax

		mov eax, 8
		movdqu xmm1, SourceB
		pinsrw xmm1, eax, 4
		movdqu Result, xmm1
		popad
		
	}

	printf("Pextrw : %d\n",Value);
	printf("Pinsrw : %d, %d, %d, %d, %d, %d, %d, %d\n",
		Result[7],Result[6],Result[5],Result[4],Result[3],Result[2],Result[1],Result[0]);
	return 0;
}

