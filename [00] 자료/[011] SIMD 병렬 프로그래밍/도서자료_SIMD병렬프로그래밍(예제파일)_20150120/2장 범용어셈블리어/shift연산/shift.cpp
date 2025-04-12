// shift.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int nValue = 8;

	__asm
	{
		pushad
		mov eax, nValue		// eax = nValue (8);
		shl	eax, 1		// eax << 1; 8x2 = 16
		mov nValue, eax		// nValue = eax;
		popad
	}
	printf("SHL Result : %d\n", nValue);
	
	__asm
	{
		pushad
		mov eax, nValue		// eax = nValue; (16)
		shr	eax, 2		// eax >> 2; 16 / 4 = 4
		mov nValue, eax		// nValue = eax
		popad
	}
	printf("SHR Result : %d\n", nValue);
	return 0;
}


