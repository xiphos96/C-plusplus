// sub.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int A = 5;
	int B = 7;
	int C = 0;
	
	__asm
	{
		pushad
		mov ebx, A 	//ebx = A;
		sub ebx, B	//ebx = ebx - B;
		mov C, ebx	//C = ebx;
		popad
	}
	
	printf( "5 - 7 SUB Result : %d\n", C );
	return 0;
}


