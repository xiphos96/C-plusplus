// mul.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int A = 5;
	int C = 0;
	
	__asm
	{
		pushad
		mov ebx, 15	//ebx = 15;
		mov eax, A	//eax = A; 
		mul ebx		//eax = ebx*eax;
		mov C, eax
		popad
	}
	
	printf( "15 * 5 MUL Result : %d\n", C );
	return 0;
}


