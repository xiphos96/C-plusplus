// compare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fvec.h>

int main(int argc, char* argv[])
{
	float pA[4] = {1.1,0.0,3.3,-4.4};
	float pB[4] = {1.1,3.3,2.2,1.1};
	float pR[4] = {0};
	
	F32vec4 A;
	F32vec4 B;
	F32vec4 R;
	
	loadu(A, pA);		//pA 메모리 읽기
	loadu(B, pB);		//pB 메모리 읽기
	
	R = cmpeq(A , B);			//Equality
	
	storeu(pR,R);		// == 결과 출력
	printf("cmpeq : %f, %f, %f, %f\n"	,pR[0],pR[1],pR[2],pR[3]);
	
	R = cmpneq(A , B);			//Inequality
	
	storeu(pR,R);		// !=Max 결과 출력
	printf("cmpneq : %f, %f, %f, %f\n"	,pR[0],pR[1],pR[2],pR[3]);
	
	R = cmpgt(A , B);			//Greater Than
	
	storeu(pR,R);		// > 결과 출력
	printf("cmpgt : %f, %f, %f, %f\n"	,pR[0],pR[1],pR[2],pR[3]);

	R = cmpge(A , B);			//Greater Than or Equal To
	
	storeu(pR,R);		// >= 결과 출력
	printf("cmpge : %f, %f, %f, %f\n"	,pR[0],pR[1],pR[2],pR[3]);

	R = cmpngt(A , B);			//Not Greater Than
	
	storeu(pR,R);		// !( a > b ) 결과 출력
	printf("cmpngt : %f, %f, %f, %f\n"	,pR[0],pR[1],pR[2],pR[3]);

	R = cmpnge(A , B);	//Not Greater Than or Equal To
	
	storeu(pR,R);		// !( a >= b ) 결과 출력
	printf("cmpngt : %f, %f, %f, %f\n"	,pR[0],pR[1],pR[2],pR[3]);

	R = cmplt(A , B);	//Less Than
	
	storeu(pR,R);		// < 결과 출력
	printf("cmplt : %f, %f, %f, %f\n"	,pR[0],pR[1],pR[2],pR[3]);

	R = cmple(A , B);	//Less Than or Equal To
	
	storeu(pR,R);		// <= 결과 출력
	printf("cmple : %f, %f, %f, %f\n"	,pR[0],pR[1],pR[2],pR[3]);

	R = cmpnlt(A , B);	//Not Less Than
	
	storeu(pR,R);		// !( a < b ) 결과 출력
	printf("cmpnlt : %f, %f, %f, %f\n"	,pR[0],pR[1],pR[2],pR[3]);

	R = cmpnle(A , B);	// Not Less Than or Equal To
	
	storeu(pR,R);		// !( a <= b ) 결과 출력
	printf("cmpnle : %f, %f, %f, %f\n"	,pR[0],pR[1],pR[2],pR[3]);

	

	return 0;
}

