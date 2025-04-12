// sharpenTime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StopWatch.h"
#include <emmintrin.h>

bool Convolution3x3SIMD(unsigned char* pSrc,unsigned char* pDest,unsigned int nImageWidth, unsigned int nImageHeight,
					unsigned int *ROIPoint, short* pKernel)
{
	unsigned int nStartX = ROIPoint[0];
	unsigned int nStartY = ROIPoint[1];
	unsigned int nEndX = ROIPoint[2];
	unsigned int nEndY = ROIPoint[3];

	if(0 == nStartX) nStartX = 1;	//필터링으로 인한 사이즈 에러처리
	if(0 == nStartY) nStartY = 1;	//필터링으로 인한 사이즈 에러처리
	if(nImageWidth == nEndX) nEndX = nImageWidth - 1;
	if(nImageHeight == nEndY) nEndY = nImageHeight - 1;

	short Mask0[8],Mask1[8],Mask2[8],Mask3[8];			//short형 8개 kernel 생성
	short Mask4[8],Mask5[8],Mask6[8],Mask7[8],Mask8[8];	//short형 8개 kernel 생성

	short debug[8];
	unsigned char debug2[16];

	for( int i = 0; i < 8; i++)
	{
		Mask0[i] = pKernel[0];	//kernel [m-1][n-1]
		Mask1[i] = pKernel[1];	//kernel [m][n-1]
		Mask2[i] = pKernel[2];	//kernel [m+1][n-1]

		Mask3[i] = pKernel[3];	//kernel [m-1][n]
		Mask4[i] = pKernel[4];	//kernel [m][n]
		Mask5[i] = pKernel[5];	//kernel [m+1][n]

		Mask6[i] = pKernel[6];	//kernel [m-1][n+1]
		Mask7[i] = pKernel[7];	//kernel [m][n+1]
		Mask8[i] = pKernel[8];	//kernel [m+1][n+1]
	}

	unsigned int nProcessLength = (nEndX - nStartX);
	int HLoopCount = nProcessLength/16;		//16단위 가로 방향 루프 카운트
	unsigned int VLoopCount = nEndY - nStartY;	//세로 방향 루프 카운트
	unsigned int nRemain = nProcessLength%16;	//16단위 계산후 나머지 부분 처리
	unsigned int nNextStartLength = nImageWidth - nProcessLength+16;	//다음줄 처리
	unsigned char * pStartSrc = pSrc+nStartX+nStartY*nImageWidth;		//프로세싱 시작부 처리
	unsigned char * pDestSrc = pDest+nStartX+nStartY*nImageWidth;		//dest 버퍼 시작부 포인트
	unsigned int test = 0;
	__asm
	{
		pushad
		mov eax, pStartSrc
		mov edx, pDestSrc
		mov esi, nNextStartLength
		mov ebx, VLoopCount
		mov ecx, HLoopCount
		mov edi, nImageWidth

		movdqu xmm3,Mask8
		pxor xmm4,xmm4
VLOOP:
HLOOP:
		//0번 위치		
		pxor xmm7,xmm7				//하위 short형 합 결과값
		pxor xmm6,xmm6				//상위 short형 합 결과값

		sub eax, edi
		movdqu xmm5, Mask0			//kernel [m-1][n-1]
		movdqu xmm0,[eax-1]			//src[m-1][n-1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//하위8byte-> short형 변환
		punpckhbw xmm1,xmm4			//상위8byte-> short형 변환

		pmullw xmm0, xmm5			//Kernel[m-1][n-1]*src[m-1][n-1]
		pmullw xmm1, xmm5			//Kernel[m-1][n-1]*src[m-1][n-1]

		paddsw xmm7,xmm0			//하위 8 short 계산값 입력
		paddsw xmm6,xmm1			//상위 8 short 계산값 입력

		//1번 위치
		movdqu xmm5, Mask1			//Kernel[m][n-1]
		movdqu xmm0,[eax]			//src[m][n-1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//하위8byte-> short형 변환
		punpckhbw xmm1,xmm4			//상위8byte-> short형 변환
		
		pmullw xmm0, xmm5			//Kernel[m][n-1]*src[m][n-1]
		pmullw xmm1, xmm5			//Kernel[m][n-1]*src[m][n-1]
		
		paddsw xmm7,xmm0			//하위 8 short 계산값 합
		paddsw xmm6,xmm1			//상위 8 short 계산값 합

		//2번 위치
		movdqu xmm5, Mask2			//Kernel[m+1][n-1]
		movdqu xmm0,[eax+1]			//src[m+1][n-1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//하위8byte-> short형 변환
		punpckhbw xmm1,xmm4			//상위8byte-> short형 변환
		
		pmullw xmm0, xmm5			//Kernel[m+1][n-1]*src[m+1][n-1]
		pmullw xmm1, xmm5			//Kernel[m+1][n-1]*src[m+1][n-1]
		
		paddsw xmm7,xmm0			//하위 8 short 계산값 합
		paddsw xmm6,xmm1			//상위 8 short 계산값 합
		

		//3번 위치
		add eax, edi
		movdqu xmm5, Mask3			//Kernel[m-1][n]
		movdqu xmm0,[eax-1]			//src[m-1][n]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//하위8byte-> short형 변환
		punpckhbw xmm1,xmm4			//상위8byte-> short형 변환

		pmullw xmm0, xmm5			//Kernel[m-1][n]*src[m+1][n]
		pmullw xmm1, xmm5			//Kernel[m-1][n]*src[m+1][n]

		paddsw xmm7,xmm0			//하위 8 short 계산값 합
		paddsw xmm6,xmm1			//상위 8 short 계산값 합

		//4번 위치
		movdqu xmm5, Mask4			//Kernel[m][n]
		movdqu xmm0,[eax]			//src[m][n]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//하위8byte-> short형 변환
		punpckhbw xmm1,xmm4			//상위8byte-> short형 변환

		pmullw xmm0, xmm5			//Kernel[m][n]*src[m][n]
		pmullw xmm1, xmm5			//Kernel[m][n]*src[m][n]

		paddsw xmm7,xmm0			//하위 8 short 계산값 합
		paddsw xmm6,xmm1			//상위 8 short 계산값 합
		
		//5번 위치
		movdqu xmm5, Mask5			//Kernel[m+1][n]
		movdqu xmm0,[eax+1]			//src[m+1][n]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//하위8byte-> short형 변환
		punpckhbw xmm1,xmm4			//상위8byte-> short형 변환

		pmullw xmm0, xmm5			//Kernel[m+1][n]*src[m+1][n]
		pmullw xmm1, xmm5			//Kernel[m+1][n]*src[m+1][n]

		paddsw xmm7,xmm0			//하위 8 short 계산값 합
		paddsw xmm6,xmm1			//상위 8 short 계산값 합

		//6번 위치
		add eax, edi
		movdqu xmm5, Mask6			//Kernel[m-1][n+1
		movdqu xmm0,[eax-1]			//src[m-1][n+1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//하위8byte-> short형 변환
		punpckhbw xmm1,xmm4			//상위8byte-> short형 변환

		pmullw xmm0, xmm5			//Kernel[m-1][n+1]*src[m-1][n+1]
		pmullw xmm1, xmm5			//Kernel[m-1][n+1]*src[m-1][n+1]
		
		paddsw xmm7,xmm0			//하위 8 short 계산값 합
		paddsw xmm6,xmm1			//상위 8 short 계산값 합
		
		//7번 위치
		movdqu xmm5, Mask8			//Kernel[m][n+1]
		movdqu xmm0,[eax]			//src[m][n+1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//하위8byte-> short형 변환
		punpckhbw xmm1,xmm4			//상위8byte-> short형 변환

		pmullw xmm0, xmm5			//Kernel[m][n+1]*src[m][n+1]
		pmullw xmm1, xmm5			//Kernel[m][n+1]*src[m][n+1]

		paddsw xmm7,xmm0			//하위 8 short 계산값 합
		paddsw xmm6,xmm1			//상위 8 short 계산값 합
		
		//8번 위치
		movdqu xmm5, xmm3			//Kernel[m+1][n+1]
		movdqu xmm0,[eax+1]			//src[m+1][n+1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//하위8byte-> short형 변환
		punpckhbw xmm1,xmm4			//상위8byte-> short형 변환
		
		pmullw xmm0, xmm5			//Kernel[m+1][n+1]*src[m+1][n+1]
		pmullw xmm1, xmm5			//Kernel[m+1][n+1]*src[m+1][n+1]
		
		paddsw xmm7,xmm0			//하위 8 short 계산값 합
		paddsw xmm6,xmm1			//상위 8 short 계산값 합
		
		packuswb xmm7,xmm6			//하위8 short형 + 상위 8 short형 -> 16byte형 변환
		movdqu [edx], xmm7

		sub eax, edi
		dec ecx
		cmp ecx,0
		jg ADD16
		je ADDREMAIN
		jl HLOOPEND
ADD16:		//다음 가로방향 16byte 증가 처리 반복
		add eax,16
		add edx,16
		jmp HLOOP
ADDREMAIN:	//마지막 16단위 처리후 나머지 부분 처리
		add eax,nRemain
		add edx,nRemain
		jmp HLOOP
HLOOPEND:		//가로 방향 루프 종료
		add eax,esi
		add edx,esi
		mov ecx, HLoopCount

		dec ebx
		cmp ebx,0
		jz LOOPEND
		jmp VLOOP	//다음 세로 방향 루프 시작
LOOPEND:
		popad
		
	}

	return true;
}

bool Convolution3x3C(unsigned char *pSrc, unsigned char *pDest, unsigned int nImageWidth, unsigned int nImageHeight, unsigned int *ROIPoint, short *pKernel)
{
	unsigned int nStartX = ROIPoint[0];
	unsigned int nStartY = ROIPoint[1];
	unsigned int nEndX = ROIPoint[2];
	unsigned int nEndY = ROIPoint[3];
	
	if(0 == nStartX) nStartX = 1;
	if(0 == nStartY) nStartY = 1;
	if(nImageWidth == nEndX) nEndX = nImageWidth - 1;
	if(nImageHeight == nEndY) nEndY = nImageHeight - 1;

	short total = 0;
	short value[9] = {0};

	for(unsigned int j = nStartY; j < nEndY; j++)
	{	
		for(unsigned int i = nStartX; i < nEndX; i++)
		{
			total = 0;
			value[0] = pSrc[i+j*nImageWidth-nImageWidth-1];
			total += pKernel[0]*value[0];
			
			value[1] = pSrc[i+j*nImageWidth-nImageWidth];
			total += pKernel[1]*value[1];

			value[2] = pSrc[i+j*nImageWidth-nImageWidth+1];
			total += pKernel[2]*value[2];
			
			value[3] = pSrc[i+j*nImageWidth-1];
			total += pKernel[3]*value[3];

			value[4] = pSrc[i+j*nImageWidth];
			total += pKernel[4]*value[4];

			value[5] = pSrc[i+j*nImageWidth+1];
			total += pKernel[5]*value[5];

			value[6] = pSrc[i+j*nImageWidth+nImageWidth-1];
			total += pKernel[6]*value[6];

			value[7] = pSrc[i+j*nImageWidth+nImageWidth];
			total += pKernel[7]*value[7];

			value[8] = pSrc[i+j*nImageWidth+nImageWidth+1];
			total += pKernel[8]*value[8];

			if(total < 0)	total = 0;
			if(total > 255)	total = 255;

			pDest[i+j*nImageWidth] = (unsigned char)total;
		}
	}
    return true;
}

bool Convolution3x3Instrinsic(unsigned char *pSrc, unsigned char *pDest, unsigned int nImageWidth, unsigned int nImageHeight, unsigned int *ROIPoint, short *pKernel)
{
	unsigned int nStartX = ROIPoint[0];
	unsigned int nStartY = ROIPoint[1];
	unsigned int nEndX = ROIPoint[2];
	unsigned int nEndY = ROIPoint[3];
	
	if(0 == nStartX) nStartX = 1;	//필터링으로 인한 사이즈 에러처리
	if(0 == nStartY) nStartY = 1;	//필터링으로 인한 사이즈 에러처리
	if(nImageWidth == nEndX) nEndX = nImageWidth - 1;
	if(nImageHeight == nEndY) nEndY = nImageHeight - 1;
	
	__m128i Kernel[9];

    int i = 0;

	for( i = 0; i < 9; i++)
		Kernel[i] = _mm_set1_epi16(pKernel[i]);

	__m128i ImageLow[9];
	__m128i ImageHigh[9];
	__m128i Dest;
	__m128i ZeroData = _mm_setzero_si128();

	__m128i ResultHigh;
	__m128i ResultLow;

	unsigned char * iterSrc;
	unsigned char * iterDest;
	unsigned int j = 0;

	for(j = nStartY; j < nEndY; j++)
	{
		for( i = nStartX; i < nEndX; i+=16)
		{
			iterSrc = pSrc+i+ nImageWidth*j;
			iterDest = pDest+i+ nImageWidth*j;

			ResultHigh = _mm_setzero_si128();
			ResultLow = _mm_setzero_si128();

			ImageLow[0] = _mm_loadu_si128((__m128i*)(iterSrc-1-nImageWidth));
			//(x-1,y-1)16 byte 읽기
			ImageLow[1] = _mm_loadu_si128((__m128i*)(iterSrc-nImageWidth));
			//(x,y-1)  16 byte 읽기
			ImageLow[2] = _mm_loadu_si128((__m128i*)(iterSrc+1-nImageWidth));
			//(x+1,y-1)16 byte 읽기
			ImageLow[3] = _mm_loadu_si128((__m128i*)(iterSrc-1));
			//(x-1,y)  16 byte 읽기
			ImageLow[4] = _mm_loadu_si128((__m128i*)(iterSrc));
			//(x,y)    16 byte 읽기
			ImageLow[5] = _mm_loadu_si128((__m128i*)(iterSrc+1));
			//(x+1,y)  16 byte 읽기
			ImageLow[6] = _mm_loadu_si128((__m128i*)(iterSrc-1+nImageWidth));
			//(x-1,y+1)16 byte 읽기
			ImageLow[7] = _mm_loadu_si128((__m128i*)(iterSrc+nImageWidth));
			//(x,y+1)  16 byte 읽기
			ImageLow[8] = _mm_loadu_si128((__m128i*)(iterSrc+1+nImageWidth));
			//(x+1,y+1)16 byte 읽기

			for( int i = 0; i < 9 ; i++)
			{
				ImageHigh[i] = _mm_unpackhi_epi8(ImageLow[i],ZeroData);
				//상위 위치 short형 변환
				ImageLow[i] = _mm_unpacklo_epi8(ImageLow[i],ZeroData);
				//하위 위치 short형 변환

				ImageLow[i] = _mm_mullo_epi16(ImageLow[i],Kernel[i]);
				ImageHigh[i] = _mm_mullo_epi16(ImageHigh[i],Kernel[i]);

				ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh[i]);
				ResultLow = _mm_adds_epi16(ResultLow,ImageLow[i]);
			}

			ResultLow = _mm_packus_epi16(ResultLow,ResultHigh);
			
			_mm_storeu_si128( (__m128i*)iterDest,ResultLow);

		}
	}

    return true;
}

bool Convolution3x3Instrinsic2(unsigned char *pSrc, unsigned char *pDest, unsigned int nImageWidth, unsigned int nImageHeight, unsigned int *ROIPoint, short *pKernel)
{
	unsigned int nStartX = ROIPoint[0];
	unsigned int nStartY = ROIPoint[1];
	unsigned int nEndX = ROIPoint[2];
	unsigned int nEndY = ROIPoint[3];
	
	if(0 == nStartX) nStartX = 1;	//필터링으로 인한 사이즈 에러처리
	if(0 == nStartY) nStartY = 1;	//필터링으로 인한 사이즈 에러처리
	if(nImageWidth == nEndX) nEndX = nImageWidth - 1;
	if(nImageHeight == nEndY) nEndY = nImageHeight - 1;
	
	__m128i Kernel[9];
	
    int i = 0;
    unsigned int j = 0;

    for( i = 0; i < 9; i++)
		Kernel[i] = _mm_set1_epi16(pKernel[i]);
	
	__m128i ImageLow;
	__m128i ImageHigh;
	__m128i Dest;
	__m128i ZeroData = _mm_setzero_si128();
	
	__m128i ResultHigh;
	__m128i ResultLow;
	
	unsigned char * iterSrc;
	unsigned char * iterDest;
	
	for( j = nStartY; j < nEndY; j++)
	{
		for( i = nStartX; i < nEndX; i+=16)
		{
			iterSrc = pSrc+i+ nImageWidth*j;
			iterDest = pDest+i+ nImageWidth*j;
			
			ResultHigh = _mm_setzero_si128();
			ResultLow = _mm_setzero_si128();
			
			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc-1-nImageWidth));
			//(x-1,y-1)16 byte 읽기

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[0]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[0]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc-nImageWidth));
			//(x,y-1)  16 byte 읽기

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[1]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[1]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc+1-nImageWidth));
			//(x+1,y-1)16 byte 읽기

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[2]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[2]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc-1));
			//(x-1,y)  16 byte 읽기
			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[3]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[3]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc));
			//(x,y)    16 byte 읽기

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[4]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[4]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc+1));
			//(x+1,y)  16 byte 읽기

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[5]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[5]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc-1+nImageWidth));
			//(x-1,y+1)16 byte 읽기

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[6]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[6]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc+nImageWidth));
			//(x,y+1)  16 byte 읽기

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[7]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[7]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc+1+nImageWidth));
			//(x+1,y+1)16 byte 읽기

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//상위 위치 short형 변환
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//하위 위치 short형 변환
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[8]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[8]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			
			ResultLow = _mm_packus_epi16(ResultLow,ResultHigh);
			
			_mm_storeu_si128( (__m128i*)iterDest,ResultLow);
			
		}
	}
    return true;
}

int main(int argc, char* argv[])
{

	const unsigned int WIDTH = 256;			//이미지 넓이 300
	const unsigned int HEIGHT = 256;		//이미지 높이 300
	const unsigned int IMAGE_SIZE = WIDTH*HEIGHT+4096;	//이미지 사이즈 90000
	const unsigned int BMP_HEADER_LENGTH = 1064;	//bmp 해더 길이 1064
	
	unsigned char* pSrcA = new unsigned char[IMAGE_SIZE];	//이미지 데이터 버퍼 A
	unsigned char* pSrcB = new unsigned char[IMAGE_SIZE];	//이미지 데이터 버퍼 B
	unsigned char* pResult = new unsigned char[IMAGE_SIZE];	//Result 데이터 버퍼 
	unsigned char* pResult2 = new unsigned char[IMAGE_SIZE];	//Result 데이터 버퍼 
	unsigned char* pResult3 = new unsigned char[IMAGE_SIZE];	//Result 데이터 버퍼 

	CStopWatch StopWatch;
	
	unsigned int ROI[4] = {0,0,WIDTH,HEIGHT};
	short Kernel[9] = {-1,-1,-1,
		-1,9,-1,
		-1,-1,-1};
	
	StopWatch.Start();
	Convolution3x3C(pSrcA,pResult2,WIDTH,HEIGHT,ROI,Kernel);
	StopWatch.End();
	
	printf("C image  Time : %f \n",  StopWatch.GetDurationMilliSecond());
	
	StopWatch.Start();
	Convolution3x3Instrinsic(pSrcA,pResult3,WIDTH,HEIGHT,ROI,Kernel);
	StopWatch.End();
	
	printf("intrinsic image Time : %f \n",  StopWatch.GetDurationMilliSecond());
	
	StopWatch.Start();
	Convolution3x3Instrinsic2(pSrcA,pResult3,WIDTH,HEIGHT,ROI,Kernel);
	StopWatch.End();
	
	printf("intrinsic2 image Time : %f \n",  StopWatch.GetDurationMilliSecond());

	StopWatch.Start();
	Convolution3x3SIMD(pSrcA,pResult,WIDTH,HEIGHT,ROI,Kernel);
	StopWatch.End();
	
	printf("SIMD image Time : %f \n", StopWatch.GetDurationMilliSecond());

	return 0;
}

