// SetValue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) short R[8] = {1,1,1,1,1,1,1,1};
	
	__m128i Temp = _mm_setzero_si128();		//0���� �ʱ�ȭ

	_mm_store_si128((__m128i*)R,Temp);		//��� ���
	printf("Result : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);

	Temp = _mm_set_epi16(8,7,6,5,4,3,2,1);	//������� �Է�
	
	_mm_store_si128((__m128i*)R,Temp);		//��� ���
	printf("Result : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);

	Temp = _mm_set1_epi16(9);		//1�� ������ ��� �Է�
	
	_mm_store_si128((__m128i*)R,Temp);		//��� ���
	printf("Result : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);

	Temp =_mm_setr_epi16(8,7,6,5,4,3,2,1);	//�������� �Է�
	
	_mm_store_si128((__m128i*)R,Temp);		//��� ���
	printf("Result : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	return 0;
}

