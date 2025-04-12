// math.cpp : Defines the entry point for the console application.
//
#include "StdAfx.h"
#include "fvec.h"

int main(int argc, char* argv[])
{
	float pA[4] = {1.0,2.0,3.0,4.0};
	float pR[4] = {0};
	
	F32vec4 A;
	F32vec4 R;
	
	loadu(A, pA);		//pA 메모리 읽기
	
	R = sqrt( A );			//루트 값 계산
	
	storeu(pR,R);		// 결과 출력
	printf("Square Root : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	R = rcp( A );			//역 분수 계산
	
	storeu(pR,R);		// 결과 출력
	printf("Reciprocal : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	R = rsqrt( A );			//루트 역분수 값 계산
	
	storeu(pR,R);		// 결과 출력
	printf("Reciprocal Square Root : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	R = rcp_nr( A );			//Newton Raphson법 역분수 계산
	
	storeu(pR,R);		// 결과 출력
	printf("Reciprocal Newton Raphson : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	R = rsqrt_nr( A );			//Newton Raphson법 루트 역분수 계산
	
	storeu(pR,R);		// 결과 출력
	printf("Reciprocal Square Root Newton Raphson : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);

	R = add_horizontal( A );			//수평 덧셈 계산
	
	storeu(pR,R);		// 결과 출력
	printf("Horizontal Add : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);
	return 0;
}
