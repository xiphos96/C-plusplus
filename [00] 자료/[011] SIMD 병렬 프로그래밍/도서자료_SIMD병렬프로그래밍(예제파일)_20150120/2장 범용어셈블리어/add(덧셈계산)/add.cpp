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
		mov eax, A	//eax = A �� ����
		mov ebx, B	//ebx = B �� ����
		add eax, ebx	//eax = eax + ebx;
		mov C, eax	//C = eax ����
		popad
	}
	
	printf( "5 + 7 ADD Result : %d\n", C );
	return 0;
}


