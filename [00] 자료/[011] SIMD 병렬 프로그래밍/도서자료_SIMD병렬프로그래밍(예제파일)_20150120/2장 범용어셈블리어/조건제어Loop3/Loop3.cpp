// Loop3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int nValue = 1000;
	__asm
	{
		mov eax, 1000	//eax = 1000;
SIMDLOOP:
		//�ݺ� ���� �ڵ� �ۼ�


		dec eax		//eax--;
		cmp eax, 0	// eax �� 0�� ���� ������ ��
		jne SIMDLOOP	//jump not equal goto LOOP;
		mov nValue, eax	//nValue = eax;
			
	}
	printf("Result : %d\n",nValue);
	return 0;
}

