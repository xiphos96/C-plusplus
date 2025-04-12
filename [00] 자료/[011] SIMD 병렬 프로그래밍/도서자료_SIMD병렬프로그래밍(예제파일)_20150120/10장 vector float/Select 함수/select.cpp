// select.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fvec.h>

int main(int argc, char* argv[])
{
	float pA[4] = {0.0,-1.1,-2.2,-3.3};
	float pB[4] = {0.0,1.1,2.2,3.3};
	float pR[4] = {0};
	
	F32vec4 A;
	F32vec4 B;
	F32vec4 C(1.0,1.0,1.0,1.0);
	F32vec4 D(2.0,2.0,2.0,2.0);
	F32vec4 R;
	
	loadu(A, pA);		//pA 메모리 읽기
	loadu(B, pB);		//pB 메모리 읽기
	
	R = select_eq(A, B, C, D);			// Equality
	
	storeu(pR,R);		// == 결과 출력
	printf("Equality : %.1f, %.1f, %.1f, %.1f\n" ,pR[0],pR[1],pR[2],pR[3]);
	
	R = select_neq(A, B, C, D);			// Inequality
	
	storeu(pR,R);		// != 결과 출력
	printf("Inequality : %.1f, %.1f, %.1f, %.1f\n" ,pR[0],pR[1],pR[2],pR[3]);

	R = select_gt(A, B, C, D);			// Greater Than
	
	storeu(pR,R);		// > 결과 출력
	printf("Greater Than : %.1f, %.1f, %.1f, %.1f\n" ,pR[0],pR[1],pR[2],pR[3]);

	R = select_ge(A, B, C, D);			// Greater Than or Equal To
	
	storeu(pR,R);		// >= 결과 출력
	printf("Greater Than or Equal To : %.1f, %.1f, %.1f, %.1f\n" ,pR[0],pR[1],pR[2],pR[3]);
	
	R = select_ngt(A, B, C, D);			// Not Greater Than
	
	storeu(pR,R);		// !( a > b ) 결과 출력
	printf("Not Greater Than : %.1f, %.1f, %.1f, %.1f\n" ,pR[0],pR[1],pR[2],pR[3]);
	
	R = select_nge(A, B, C, D);			// Not Greater Than or Equal To
	
	storeu(pR,R);		// !( a >= b ) 결과 출력
	printf("Not Greater Than or Equal To : %.1f, %.1f, %.1f, %.1f\n" ,pR[0],pR[1],pR[2],pR[3]);
	
	R = select_lt(A, B, C, D);			// Less Than
	
	storeu(pR,R);		// < 결과 출력
	printf("Less Than : %.1f, %.1f, %.1f, %.1f\n" ,pR[0],pR[1],pR[2],pR[3]);
	
	R = select_le(A, B, C, D);			// Less Than or Equal To
	
	storeu(pR,R);		// <= 결과 출력
	printf("Less Than or Equal To : %.1f, %.1f, %.1f, %.1f\n" ,pR[0],pR[1],pR[2],pR[3]);
	
	R = select_nlt(A, B, C, D);			// Not Less Than
	
	storeu(pR,R);		// !( a < b ) 결과 출력
	printf("Not Less Than : %.1f, %.1f, %.1f, %.1f\n" ,pR[0],pR[1],pR[2],pR[3]);
	
	R = select_nle(A, B, C, D);			// Not Less Than or Equal To
	
	storeu(pR,R);		// !( a <= b ) 결과 출력
	printf("Not Less Than or Equal To : %.1f, %.1f, %.1f, %.1f\n" ,pR[0],pR[1],pR[2],pR[3]);

	

	return 0;
}

