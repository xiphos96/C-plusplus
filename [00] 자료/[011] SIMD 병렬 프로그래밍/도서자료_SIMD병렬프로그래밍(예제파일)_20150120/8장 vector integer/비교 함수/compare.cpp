// compare.cpp : Defines the entry point for the console application.
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
	
	*pVR = cmpeq (*pVA , *pVB);		//Equality ����
	
	printf("Equality : %x, %x, %x, %x, %x, %x, %x, %x\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);
	
	*pVR = cmpneq (*pVA , *pVB);		//Inequality ����
	
	printf("Inequality : %x, %x, %x, %x, %x, %x, %x, %x\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);
	
	*pVR = cmpgt (*pVA , *pVB);		//Greater Than ����
	
	printf("Greater Than : %x, %x, %x, %x, %x, %x, %x, %x\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);
	
	*pVR = cmplt (*pVA , *pVB);		//Less Than ����
	
	printf("Less Than : %x, %x, %x, %x, %x, %x, %x, %x\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);
	
	return 0;
}
