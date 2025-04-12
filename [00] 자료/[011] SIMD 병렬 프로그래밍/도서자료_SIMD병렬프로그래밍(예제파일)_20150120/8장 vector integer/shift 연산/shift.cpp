// shift.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <dvec.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) short pA[8] = {1,2,3,4,-5,-6,-7,-8};
	__declspec(align(16)) short pR[8] = {0};
	
	Is16vec8* pVA = (Is16vec8*)pA;
	Is16vec8* pVR = (Is16vec8*)pR;
	
	*pVR = *pVA << 2;		//哭率 shift
	
	printf("Left 2 shift : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);

	*pVR = *pVA >> 1;		//坷弗率 shift
	
	printf("Right 1 shift : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);
	
	*pVR <<=  1;		//哭率 shift
	
	printf("Left 1 shift : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);

	*pVR >>=  1;		//坷弗率 shift
	
	printf("Right 1 shift : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);

	return 0;
}
