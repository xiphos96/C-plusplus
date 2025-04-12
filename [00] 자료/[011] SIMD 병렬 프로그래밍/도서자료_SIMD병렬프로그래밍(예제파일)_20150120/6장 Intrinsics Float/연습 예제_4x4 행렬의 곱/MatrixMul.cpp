// MatrixMul.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "emmintrin.h"
#include "StopWatch.h"

void AddMatrix4x4C(const float* MatrixA, const float* MatrixB, float* MaxtrixDest) 
{
	for(int i = 0; i < 16; i++)
		MaxtrixDest[i] = MatrixA[i] + MatrixB[i];
}

void AddMatrix4x4SIMD( float* MatrixA, float* MatrixB, float* MaxtrixDest)
{
	__asm
	{
		mov eax, MatrixA
		mov	ebx, MatrixB
		mov	edx, MaxtrixDest	
		
		movups xmm0, [eax]
		movups xmm1, [eax + 16]
		movups xmm2, [eax + 32]
		movups xmm3, [eax + 48]
			
		movups xmm4, [ebx]
		movups xmm5, [ebx + 16]
		movups xmm6, [ebx + 32]
		movups xmm7, [ebx + 48]
		
		addps xmm0, xmm4
		addps xmm1, xmm5
		addps xmm2, xmm6
		addps xmm3, xmm7
		
		movups [edx], xmm0
		movups [edx+16], xmm1
		movups [edx+32], xmm2
		movups [edx+48], xmm3
	}
}

void MatrixMul4x4SIMD( float* MatrixA, float* MatrixB, float* MaxtrixDest)
{
	__asm
	{
		mov eax, MatrixA
		mov	ebx, MatrixB
		mov	edx, MaxtrixDest
		mov esi,0
		
		movaps xmm0, [ebx]
		movaps xmm1, [ebx + 16]
		movaps xmm2, [ebx + 32]
		movaps xmm3, [ebx + 48]
SIMDLOOP:			
		movaps xmm4, [eax+esi]
		movaps xmm5, xmm4
		movaps xmm6, xmm4
		movaps xmm7, xmm4

		shufps xmm4,xmm4,0x00
		shufps xmm5,xmm5,0x55
		shufps xmm6,xmm6,0xaa
		shufps xmm7,xmm7,0xff

		mulps xmm4, xmm0
		mulps xmm5, xmm1
		mulps xmm6, xmm2
		mulps xmm7, xmm3
		
		addps xmm5, xmm4
		addps xmm6, xmm5
		addps xmm7, xmm6
		
		movaps [edx+esi], xmm7
		
		add esi, 16
		cmp esi, 64
		jne SIMDLOOP
	}
}

void MatrixMul4x4C( float* MatrixA, float* MatrixB, float* MaxtrixDest)
{
	MaxtrixDest[0] = MatrixA[0]*MatrixB[0] + MatrixA[1]*MatrixB[4] + MatrixA[2]*MatrixB[8] + MatrixA[3]*MatrixB[12];
	MaxtrixDest[1] = MatrixA[0]*MatrixB[1] + MatrixA[1]*MatrixB[5] + MatrixA[2]*MatrixB[9] + MatrixA[3]*MatrixB[13];
	MaxtrixDest[2] = MatrixA[0]*MatrixB[2] + MatrixA[1]*MatrixB[6] + MatrixA[2]*MatrixB[10] + MatrixA[3]*MatrixB[14];
	MaxtrixDest[3] = MatrixA[0]*MatrixB[3] + MatrixA[1]*MatrixB[7] + MatrixA[2]*MatrixB[11] + MatrixA[3]*MatrixB[15];

	MaxtrixDest[4] = MatrixA[4]*MatrixB[0] + MatrixA[5]*MatrixB[4] + MatrixA[6]*MatrixB[8] + MatrixA[7]*MatrixB[12];
	MaxtrixDest[5] = MatrixA[4]*MatrixB[1] + MatrixA[5]*MatrixB[5] + MatrixA[6]*MatrixB[9] + MatrixA[7]*MatrixB[13];
	MaxtrixDest[6] = MatrixA[4]*MatrixB[2] + MatrixA[5]*MatrixB[6] + MatrixA[6]*MatrixB[10] + MatrixA[7]*MatrixB[14];
	MaxtrixDest[7] = MatrixA[4]*MatrixB[3] + MatrixA[5]*MatrixB[7] + MatrixA[6]*MatrixB[11] + MatrixA[7]*MatrixB[15];

	MaxtrixDest[8] = MatrixA[8]*MatrixB[0] + MatrixA[9]*MatrixB[4] + MatrixA[10]*MatrixB[8] + MatrixA[11]*MatrixB[12];
	MaxtrixDest[9] = MatrixA[8]*MatrixB[1] + MatrixA[9]*MatrixB[5] + MatrixA[10]*MatrixB[9] + MatrixA[11]*MatrixB[13];
	MaxtrixDest[10] = MatrixA[8]*MatrixB[2] + MatrixA[9]*MatrixB[6] + MatrixA[10]*MatrixB[10] + MatrixA[11]*MatrixB[14];
	MaxtrixDest[11] = MatrixA[8]*MatrixB[3] + MatrixA[9]*MatrixB[7] + MatrixA[10]*MatrixB[11] + MatrixA[11]*MatrixB[15];

	MaxtrixDest[12] = MatrixA[12]*MatrixB[0] + MatrixA[13]*MatrixB[4] + MatrixA[14]*MatrixB[8] + MatrixA[15]*MatrixB[12];
	MaxtrixDest[13] = MatrixA[12]*MatrixB[1] + MatrixA[13]*MatrixB[5] + MatrixA[14]*MatrixB[9] + MatrixA[15]*MatrixB[13];
	MaxtrixDest[14] = MatrixA[12]*MatrixB[2] + MatrixA[13]*MatrixB[6] + MatrixA[14]*MatrixB[10] + MatrixA[15]*MatrixB[14];
	MaxtrixDest[15] = MatrixA[12]*MatrixB[3] + MatrixA[13]*MatrixB[7] + MatrixA[14]*MatrixB[11] + MatrixA[15]*MatrixB[15];
}

void Matrix4x4Intrinsic( float* MatrixA, float* MatrixB, float* MaxtrixDest)
{
	int indexA = 0;
	int indexB = 0;
    int i = 0;

	__m128 xmmB[4];
	for( i = 0; i < 4; i++)
		xmmB[i] = _mm_load_ps((MatrixB+(i*4)));

	__m128 xmmR;
	for( i = 0; i< 4; i++)
	{
		indexB = 0;
		xmmR = _mm_add_ps(_mm_mul_ps(_mm_set1_ps(MatrixA[indexA++]),xmmB[indexB++]),
			_mm_add_ps(_mm_mul_ps(_mm_set1_ps(MatrixA[indexA++]),xmmB[indexB++]),
			_mm_add_ps(_mm_mul_ps(_mm_set1_ps(MatrixA[indexA++]),xmmB[indexB++]),
			_mm_mul_ps(_mm_set1_ps(MatrixA[indexA++]),xmmB[indexB++]))));
		_mm_store_ps((MaxtrixDest+(i*4)),xmmR);
	}
}

int main(int argc, char* argv[])
{
	__declspec(align(16)) float MatrixA[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	__declspec(align(16)) float MatrixB[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	__declspec(align(16)) float MatrixDest[16] = {0};

	CStopWatch watch;
	int i = 0;

	watch.Start();
	for(i = 0; i < 10000; i++)
		MatrixMul4x4C(MatrixA,MatrixB,MatrixDest);
	watch.End();
	printf("4x4 C Result Time : %f\n",watch.GetDurationMilliSecond());
	printf("%f, %f, %f, %f\n", MatrixDest[0], MatrixDest[1], MatrixDest[2], MatrixDest[3]);
	printf("%f, %f, %f, %f\n", MatrixDest[4], MatrixDest[5], MatrixDest[6], MatrixDest[7]);
	printf("%f, %f, %f, %f\n", MatrixDest[8], MatrixDest[9], MatrixDest[10], MatrixDest[11]);
	printf("%f, %f, %f, %f\n", MatrixDest[12], MatrixDest[13], MatrixDest[14], MatrixDest[15]);
	
	watch.Start();
	for(i = 0; i < 10000; i++)
		MatrixMul4x4SIMD(MatrixA,MatrixB,MatrixDest);
	watch.End();
	printf("4x4 SIMD Time : %f\n",watch.GetDurationMilliSecond());
	printf("%f, %f, %f, %f\n", MatrixDest[0], MatrixDest[1], MatrixDest[2], MatrixDest[3]);
	printf("%f, %f, %f, %f\n", MatrixDest[4], MatrixDest[5], MatrixDest[6], MatrixDest[7]);
	printf("%f, %f, %f, %f\n", MatrixDest[8], MatrixDest[9], MatrixDest[10], MatrixDest[11]);
	printf("%f, %f, %f, %f\n", MatrixDest[12], MatrixDest[13], MatrixDest[14], MatrixDest[15]);

	watch.Start();
	for(i = 0; i < 10000; i++)
		Matrix4x4Intrinsic(MatrixA,MatrixB,MatrixDest);
	watch.End();
	
	printf("4x4 Intrinsic Time : %f\n",watch.GetDurationMilliSecond());
	printf("%f, %f, %f, %f\n", MatrixDest[0], MatrixDest[1], MatrixDest[2], MatrixDest[3]);
	printf("%f, %f, %f, %f\n", MatrixDest[4], MatrixDest[5], MatrixDest[6], MatrixDest[7]);
	printf("%f, %f, %f, %f\n", MatrixDest[8], MatrixDest[9], MatrixDest[10], MatrixDest[11]);
	printf("%f, %f, %f, %f\n", MatrixDest[12], MatrixDest[13], MatrixDest[14], MatrixDest[15]);
	
	return 0;
}

