// psub.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	
	char ByteArrayA[16] = {0};
	char ByteArrayB[16] = {0};
    unsigned char i = 0;
	
	for( i = 0; i < 16; i++)
	{
		ByteArrayA[i] = i+1;
		ByteArrayB[i] = i;	
	}
	
	char ByteResult[16] ={0};
	__asm
	{
		pushad
			movdqu xmm0, ByteArrayA
			movdqu   xmm1, ByteArrayB
			psubb xmm0, xmm1
			movdqu   ByteResult, xmm0
			popad
			
	}
	printf("subResult : %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d \n",
		ByteResult[15],ByteResult[14],ByteResult[13],ByteResult[12],
		ByteResult[11],ByteResult[10],ByteResult[9],ByteResult[8],
		ByteResult[7],ByteResult[6],ByteResult[5],ByteResult[4],
		ByteResult[3],ByteResult[2],ByteResult[1],ByteResult[0]);
	return 0;
}


