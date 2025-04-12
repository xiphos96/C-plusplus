// loadstore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fvec.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) float A[4] = {1.1,2.2,3.3,4.4};
	__declspec(align(16)) float B[4] = {4.4,3.3,2.2,1.1};
	__declspec(align(16)) float R[4] = {0};
	
	F32vec4 Vector;	//�������� 4���� �Է�

	loadu(Vector, B);

	storeu(R,Vector);
	
	printf("Store : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);
	
	F32vec4 *vA = (F32vec4 *)A;	//������ ĳ�������� �ٷ� �б�
	
	F32vec4 *vR = (F32vec4 *)R;
	
	*vR = *vA;	//���� ����
	
	printf("Store : %.3f, %.3f, %.3f, %.3f\n"
		,R[0],R[1],R[2],R[3]);
	return 0;
}

