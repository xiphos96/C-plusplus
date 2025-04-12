// add.cpp : Defines the entry point for the console application.
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
		mov eax, A	//eax = A 값 대입
		mov ebx, B	//ebx = B 값 대입
		add eax, ebx	//eax = eax + ebx;
		mov C, eax	//C = eax 대입
		popad
	}
	
	printf( "5 + 7 ADD Result : %d\n", C );
	return 0;
}


