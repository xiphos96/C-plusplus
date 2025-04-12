// MinMax.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dvec.h"

int main(int argc, char* argv[])
{

	__declspec(align(16)) short pA[8] = {8,7,6,5,4,3,2,1};
	__declspec(align(16)) short pB[8] = {1,2,3,4,5,6,7,8};
	__declspec(align(16)) short pR[8] = {0};
	
	Is16vec8* pVA = (Is16vec8*)pA;
	Is16vec8* pVB = (Is16vec8*)pB;
	Is16vec8* pVR = (Is16vec8*)pR;
	
	*pVR = simd_max (*pVA , *pVB);
	
	printf("Max : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);
	
	*pVR = simd_min (*pVA , *pVB);
	
	printf("Min : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);

	return 0;
}
