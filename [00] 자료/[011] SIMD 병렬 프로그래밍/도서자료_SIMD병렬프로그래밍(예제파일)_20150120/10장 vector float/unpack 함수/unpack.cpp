// unpack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fvec.h>

int main(int argc, char* argv[])
{
	float pA[4] = {0.0,1.1,2.2,3.3};
	float pB[4] = {4.4,5.5,6.6,7.7};
	float pR[4] = {0};
	
	F32vec4 A;
	F32vec4 B;
	
	F32vec4 R;
	
	loadu(A, pA);		//pA 메모리 읽기
	loadu(B, pB);		//pB 메모리 읽기
	
	R = unpack_low(A, B);			// unpack_low
	
	storeu(pR,R);		// == 결과 출력
	printf("unpack_low : %.1f, %.1f, %.1f, %.1f\n" ,pR[0],pR[1],pR[2],pR[3]);
	
	R = unpack_high(A, B);			// unpack_high
	
	storeu(pR,R);		// != 결과 출력
	printf("unpack_high : %.1f, %.1f, %.1f, %.1f\n" ,pR[0],pR[1],pR[2],pR[3]);
	
	
	
	return 0;
}
