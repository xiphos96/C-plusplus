// psrlw.cpp : Defines the entry point for the console application.
//
#include "StdAfx.h"

int main(int argc, char* argv[])
{

	short Value[8] = {1,2,3,4,5,6,7,8};
	short ResultA[8] = {0};
	
	__asm
	{
		pushad
			movdqu  xmm0, Value
			psrlw xmm0, 1
			movdqu ResultA, xmm0
			popad
			
	}
	printf("Bit Left shift Result %d,%d,%d,%d,%d,%d,%d,%d \n",
		ResultA[7],ResultA[6],ResultA[5],ResultA[4],ResultA[3],ResultA[2],ResultA[1],ResultA[0]);
	
	return 0;
}

