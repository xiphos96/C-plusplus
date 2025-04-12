// pack.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "dvec.h"

int main(int argc, char* argv[])
{
	__declspec(align(16)) int pA[4] = {1,0,-1,0};
	__declspec(align(16)) int pB[4] = {1,2,0,-2};
	__declspec(align(16)) short pR[8] = {0};
	
	Is32vec4* pVA = (Is32vec4*)pA;
	Is32vec4* pVB = (Is32vec4*)pB;
	Is16vec8* pVR = (Is16vec8*)pR;
	
	*pVR = pack_sat(*pVA , *pVB);		//pack ¿¬»ê
	
	printf("pack : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);

	return 0;
}
