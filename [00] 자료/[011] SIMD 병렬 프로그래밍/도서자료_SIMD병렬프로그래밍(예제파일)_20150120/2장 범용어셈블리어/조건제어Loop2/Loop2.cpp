// Loop2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int nValue = 1000;
	__asm
	{
		mov eax, 1000	//eax = 1000;
SIMDLOOP:
		
		dec eax		//eax--;
		jnz SIMDLOOP	//if( 0 != eax ) goto LOOP;
		//jump not zero, eax, to LOOP
		mov nValue, eax	//nValue = eax;	
	}
	printf("Result : %d\n",nValue);
	return 0;
}

