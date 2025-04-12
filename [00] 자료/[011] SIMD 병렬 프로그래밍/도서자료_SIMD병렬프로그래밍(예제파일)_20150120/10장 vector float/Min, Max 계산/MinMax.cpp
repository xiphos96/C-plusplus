// MinMax.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fvec.h"

int main(int argc, char* argv[])
{
	float pA[4] = {1.1,2.2,3.3,4.4};
	float pB[4] = {4.4,3.3,2.2,1.1};
	float pR[4] = {0};
	
	F32vec4 A;
	F32vec4 B;
	F32vec4 R;
	
	loadu(A, pA);		//pA 메모리 읽기
	loadu(B, pB);		//pB 메모리 읽기

	R = simd_min(A , B);			//Min 계산
	
	storeu(pR,R);		// Min 결과 출력
	printf("Min : %.3f, %.3f, %.3f, %.3f\n"	,pR[0],pR[1],pR[2],pR[3]);

	R = simd_max(A , B);			//Max 계산
	
	storeu(pR,R);		// Max 결과 출력
	printf("Max : %.3f, %.3f, %.3f, %.3f\n" ,pR[0],pR[1],pR[2],pR[3]);

	

	return 0;
}


