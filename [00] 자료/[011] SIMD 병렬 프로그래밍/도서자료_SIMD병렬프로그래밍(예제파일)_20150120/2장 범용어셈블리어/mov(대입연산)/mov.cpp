// mov.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int a = 1;
	int nValue = 0;	//메모리 변수
	__asm
	{
		mov eax, 1	//레지스터 변수
		mov nValue, 2
	}
	printf("nValue : %d\n",nValue);
	return 0;
}


