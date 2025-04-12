// Debug.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define _ENABLE_VEC_DEBUG
#include "dvec.h"

int main(int argc, char* argv[])
{
	__declspec( align(16) )	short pA[8] = {1,2,3,4,5,6,7,8};
	__declspec( align(16) )	short pB[8] = {8,7,6,5,4,3,2,1};
	__declspec( align(16) )	short pR[8] = {0};
	
	Is16vec8* A = (Is16vec8*)pA;
	Is16vec8* B = (Is16vec8*)pB;
	Is16vec8* R = (Is16vec8*)pR;
	
	*R = *A + *B;			//µ¡¼À °è»ê
	
	cout << "ADD : " << *R << endl;
	
	*R = *A - *B;			// »¬¼À °è»ê
	
	cout  << "SUB : " << *R << endl;
	
	*R = *A * *B;			// °ö¼À °è»ê
	
	cout  << "MUL : " << *R << endl;

	cout << "First Element : " << (*R)[0] << endl;
	
	return 0;
}

