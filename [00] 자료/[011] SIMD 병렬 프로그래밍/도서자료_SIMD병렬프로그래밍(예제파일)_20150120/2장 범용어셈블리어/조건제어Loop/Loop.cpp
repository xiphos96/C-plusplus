// Loop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int nValue = 0;
	__asm
	{
		pushad
			
		mov eax, 0		//eax = 0;
SIMDLOOP:					//�ݺ� ������ �� �� goto�� ����
		//������ ���� �Է�
			
		inc eax			//eax++
		cmp eax, 1000		//if(eax != 0) 
		//compare eax, 1000
		jne SIMDLOOP		//goto LOOP 
		//jump not equal LOOP
		
		mov nValue, eax		//nValue = eax;
		popad
	}
	printf("Result : %d\n", nValue);
	return 0;
}
