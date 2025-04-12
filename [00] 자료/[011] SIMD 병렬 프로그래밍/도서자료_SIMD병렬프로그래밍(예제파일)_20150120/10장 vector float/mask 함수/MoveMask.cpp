// MoveMask.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fvec.h"

int main(int argc, char* argv[])
{
	float pA[4] = {-1.1,-2.2,3.3,4.4};
	
	F32vec4 A;
	
	loadu(A, pA);		//pA �޸� �б�

	int i = move_mask( A );	// 4bit mask ����

	printf("Bit Mask : %x\n",i);
	
	
	
	return 0;
}

