// add.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <dvec.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) short pA[8] = {1,2,3,4,5,6,7,8};
	__declspec(align(16)) short pB[8] = {1,2,3,4,5,6,7,8};
	__declspec(align(16)) short pR[8] = {0};

	__m128i m = _mm_load_si128((__m128i*)pA);

	Is16vec8 vA(m);
	Is16vec8 vB(1,1,1,1,1,1,1,1);
	Is16vec8 vC =  vA + vB;		//vector µ¡¼À
	//(1,2,3,4,5,6,7,8) + (1,1,1,1,1,1,1,1) = (2,3,4,5,6,7,8,9);

	_mm_store_si128((__m128i *)pR, vC);

	printf("ADD : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);

	Is16vec8* pVA = (Is16vec8*)pA;	//pA ¹è¿­ ÀÐ±â
	Is16vec8* pVB = (Is16vec8*)pB;	//pB ¹è¿­ ÀÐ±â
	Is16vec8* pVR = (Is16vec8*)pR;	//pR ¹è¿­ ¾²±â

	*pVR = *pVA + *pVB;		//vector µ¡¼À
	//(1,2,3,4,5,6,7,8) + (1,2,3,4,5,6,7,8) = (2,4,6,8,10,12,14,16);

	printf("ADD : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);

	return 0;
}

