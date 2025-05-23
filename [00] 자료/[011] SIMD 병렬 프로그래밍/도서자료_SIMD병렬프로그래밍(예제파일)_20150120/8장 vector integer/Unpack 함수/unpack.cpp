// unpack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dvec.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) short pA[8] = {1,0,1,0,-1,0,-1,2};
	__declspec(align(16)) short pB[8] = {1,1,0,0,1,1,0,0};
	__declspec(align(16)) short pR[8] = {0};
	
	Is16vec8* pVA = (Is16vec8*)pA;
	Is16vec8* pVB = (Is16vec8*)pB;
	Is16vec8* pVR = (Is16vec8*)pR;
	
	*pVR = unpack_low(*pVA , *pVB);		//unpack_low ����
	
	printf("unpack low : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);
	
	*pVR = unpack_high(*pVA , *pVB);		//unpack_high ����
	
	printf("unpack high : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);
	
	return 0;
}

