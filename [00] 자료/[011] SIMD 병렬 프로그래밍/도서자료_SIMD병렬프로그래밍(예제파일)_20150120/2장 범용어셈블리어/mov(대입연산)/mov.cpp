// mov.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int a = 1;
	int nValue = 0;	//�޸� ����
	__asm
	{
		mov eax, 1	//�������� ����
		mov nValue, 2
	}
	printf("nValue : %d\n",nValue);
	return 0;
}


