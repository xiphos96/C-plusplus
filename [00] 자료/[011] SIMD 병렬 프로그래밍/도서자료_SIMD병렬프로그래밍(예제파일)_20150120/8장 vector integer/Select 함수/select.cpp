// select.cpp : Defines the entry point for the console application.
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
	
	*pVR = select_eq (*pVA , *pVB, *pVA , *pVB);		//Equality 연산
	
	printf("Equality : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);
	
	*pVR = select_neq (*pVA , *pVB, *pVA , *pVB);		//Inequality 연산
	
	printf("Inequality : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);
	
	*pVR = select_gt (*pVA , *pVB, *pVA , *pVB);		//Greater Than 연산
	
	printf("Greater Than : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);
	
	*pVR = select_lt (*pVA , *pVB, *pVA , *pVB);		//Less Than 연산
	
	printf("Less Than : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,pR[0],pR[1],pR[2],pR[3],pR[4],pR[5],pR[6],pR[7]);
	
	return 0;
}


