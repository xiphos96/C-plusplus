// div.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int A = 5;
	int B = 0;
	int C = 0;
	
	__asm
	{
		pushad
		mov eax, 17	//eax = 15;
		cdq		//32bit를 64bit로 확장
		//convert double word to quad word
		mov ebx, A	//ebx = A;
		div ebx		//eax = eax / ebx;
		mov B, eax	//B = eax;
		// edx = eax % eax;
		mov C, edx	//C = edx;
		popad
	}
	
	printf( "17/3 DIV Result : %d, %d\n", B, C );
	return 0;
}


