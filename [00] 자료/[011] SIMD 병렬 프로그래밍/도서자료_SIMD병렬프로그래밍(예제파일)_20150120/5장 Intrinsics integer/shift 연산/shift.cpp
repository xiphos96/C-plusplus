// shift.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) short A[8] = {1,2,3,4,5,6,7,8};
	__declspec(align(16)) short B[8] = {-1,-2,-3,-4,-5,-6,-7,-8};
	__declspec(align(16)) short R[8] = {0};
	
	
	__m128i xmmA = _mm_load_si128((__m128i*)A);		//����� �Է�
	__m128i xmmB = _mm_load_si128((__m128i*)B);		//������ �Է�
	
	__m128i xmmR = _mm_slli_epi16(xmmA,1);	//��� ���� shift ����
	
	_mm_store_si128((__m128i*)R,xmmR);		//��� ���
	printf("Left Shift : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_slli_epi16(xmmB,1);	//���� ���� shift ����
	
	_mm_store_si128((__m128i*)R,xmmR);		//��� ���
	printf("Left Shift : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_srai_epi16(xmmA,1);	//��� ����� ������ shift ����
	
	_mm_store_si128((__m128i*)R,xmmR);		//��� ���
	printf("Arithmetic Right Shift : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_srli_epi16(xmmA,1);	//��� ���� ������ shift ����
	
	_mm_store_si128((__m128i*)R,xmmR);		//��� ���
	printf("Logical Right Shift : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	
	xmmR = _mm_srai_epi16(xmmB,1);	//���� ����� ������ shift ����
	
	_mm_store_si128((__m128i*)R,xmmR);		//��� ���
	printf("Arithmetic Right Shift : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);

	xmmR = _mm_srli_epi16(xmmB,1);	//���� ���� ������ shift ����
	
	_mm_store_si128((__m128i*)R,xmmR);		//��� ���
	printf("Logical Right Shift : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	
	return 0;
}
