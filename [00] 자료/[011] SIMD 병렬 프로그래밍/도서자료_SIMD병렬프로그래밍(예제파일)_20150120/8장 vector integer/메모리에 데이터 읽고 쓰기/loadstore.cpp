// loadstore.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <dvec.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) short A[8] = {1,2,3,4,5,6,7,8};
	__declspec(align(16)) short R[8] = {0};
	
	Is16vec8 Vector(1,2,3,4,5,6,7,8);	//역순으로 8부터 입력
	
	_mm_store_si128((__m128i *)R, Vector);	//intrinsic 함수로 쓰기
	
	printf("Store : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[0],R[1],R[2],R[3],R[4],R[5],R[6],R[7]);
	
	Is16vec8 *a = (Is16vec8 *)A;	//포인터 캐스팅으로 바로 읽기
	
	Is16vec8 *r = (Is16vec8 *)R;
	
	*r = *a;	//대입 연산
	
	printf("Store : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[0],R[1],R[2],R[3],R[4],R[5],R[6],R[7]);
	return 0;
}
