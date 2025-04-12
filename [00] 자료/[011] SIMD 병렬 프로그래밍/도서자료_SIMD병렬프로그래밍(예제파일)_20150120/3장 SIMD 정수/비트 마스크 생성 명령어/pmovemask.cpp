// pmovemask.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	
	char CharArrayA[16] = {0xff,0xff,0x0,0xff,0x0,0x0,0x0,0x0,
							0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
	int mask = 0;
	__asm
	{
		pushad
		movdqu xmm0, CharArrayA
		pmovmskb eax, xmm0		//eax = 0000000000001011
		mov mask, eax
		popad
		
	}
	printf("mask = %d \n", mask);
	
	return 0;
}

