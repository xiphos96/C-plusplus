// AddSub.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) short A[8] = {2,4,6,8,10,8,6,4};
	__declspec(align(16)) short B[8] = {1,2,3,4,5,6,7,8};
	__declspec(align(16)) short R[8] = {0};
	
	__m128i xmmA = _mm_load_si128((__m128i*)A);
	__m128i xmmB = _mm_load_si128((__m128i*)B);

	__m128i xmmR = _mm_add_epi16(xmmA,xmmB);	//µ¡¼À ¿¬»ê

	_mm_store_si128((__m128i*)R,xmmR);		//°á°ú Ãâ·Â
	printf("Add : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);

	xmmR = _mm_sub_epi16(xmmA,xmmB);		//»¬¼À ¿¬»ê
	
	_mm_store_si128((__m128i*)R,xmmR);		//°á°ú Ãâ·Â
	printf("Sub : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);

	xmmR = _mm_mullo_epi16(xmmA,xmmB);		//°ö¼À¿¬»ê
	
	_mm_store_si128((__m128i*)R,xmmR);		//°á°ú Ãâ·Â
	printf("Mul : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);

	xmmR = _mm_min_epi16(xmmA,xmmB);		//Min°ª °è»ê
	
	_mm_store_si128((__m128i*)R,xmmR);		//°á°ú Ãâ·Â
	printf("Min : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);

	xmmR = _mm_max_epi16(xmmA,xmmB);		//Max°ª °è»ê
	
	_mm_store_si128((__m128i*)R,xmmR);		//°á°ú Ãâ·Â
	printf("Max : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);

	xmmR = _mm_avg_epu16(xmmA,xmmB);		//Æò±Õ°ª °è»ê
	
	_mm_store_si128((__m128i*)R,xmmR);		//°á°ú Ãâ·Â
	printf("AVG : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
	
	return 0;
}


