// Logical.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fvec.h>

int main(int argc, char* argv[])
{
	float pA[4] = {1.0,0.0,1.0,0.0};
	float pB[4] = {1.0,1.0,0.0,0.0};
	float pR[4] = {0};
	
	F32vec4 A;
	F32vec4 B;
	F32vec4 R;
	
	loadu(A, pA);		//pA 메모리 읽기
	loadu(B, pB);		//pB 메모리 읽기
	
	R = A & B;			//AND 계산
	
	storeu(pR,R);		// AND 결과 출력
	printf("AND : %.3f, %.3f, %.3f, %.3f\n" ,pR[0],pR[1],pR[2],pR[3]);
	
	R = A | B;			// OR 계산
	
	storeu(pR,R);		// OR 결과 출력
	printf("OR : %.3f, %.3f, %.3f, %.3f\n" ,pR[0],pR[1],pR[2],pR[3]);

	R = A ^ B;			// XOR 계산
	
	storeu(pR,R);		// XOR 결과 출력
	printf("XOR : %.3f, %.3f, %.3f, %.3f\n"	,pR[0],pR[1],pR[2],pR[3]);

	

	return 0;
}
