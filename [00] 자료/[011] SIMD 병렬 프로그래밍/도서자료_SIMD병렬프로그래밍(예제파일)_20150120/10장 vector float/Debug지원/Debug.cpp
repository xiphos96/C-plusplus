// Debug.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define _ENABLE_VEC_DEBUG
#include "fvec.h"
using namespace std;

int main(int argc, char* argv[])
{
	float pA[4] = {1.1,2.2,3.3,4.4};
	float pB[4] = {4.4,3.3,2.2,1.1};
	float pR[4] = {0};
	
	F32vec4 A;
	F32vec4 B;
	F32vec4 R;
	
	loadu(A, pA);		//pA ¸Þ¸ð¸® ÀÐ±â
	loadu(B, pB);		//pB ¸Þ¸ð¸® ÀÐ±â
	
	R = A + B;			//µ¡¼À °è»ê

	cout << "ADD : " << R << endl;
	
	R = A - B;			// »¬¼À °è»ê
	
	cout  << "SUB : " << R << endl;

	R = A * B;			// °ö¼À °è»ê
	
	cout  << "MUL : " << R << endl;

	R = A / B;			// ³ª´°¼À °è»ê
	
	cout  << "DIV : " << R << endl;

	R[0] = 1.414;

	cout << "First Element R[0] : " << R[0] << endl;

	
	
	return 0;
}