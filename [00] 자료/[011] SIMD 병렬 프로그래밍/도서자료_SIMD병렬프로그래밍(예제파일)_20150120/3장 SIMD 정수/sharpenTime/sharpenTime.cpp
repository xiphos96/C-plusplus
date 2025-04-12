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

	if(0 == nStartX) nStartX = 1;	//���͸����� ���� ������ ����ó��
	if(0 == nStartY) nStartY = 1;	//���͸����� ���� ������ ����ó��
	if(nImageWidth == nEndX) nEndX = nImageWidth - 1;
	if(nImageHeight == nEndY) nEndY = nImageHeight - 1;

	short Mask0[8],Mask1[8],Mask2[8],Mask3[8];			//short�� 8�� kernel ����
	short Mask4[8],Mask5[8],Mask6[8],Mask7[8],Mask8[8];	//short�� 8�� kernel ����

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
	int HLoopCount = nProcessLength/16;		//16���� ���� ���� ���� ī��Ʈ
	unsigned int VLoopCount = nEndY - nStartY;	//���� ���� ���� ī��Ʈ
	unsigned int nRemain = nProcessLength%16;	//16���� ����� ������ �κ� ó��
	unsigned int nNextStartLength = nImageWidth - nProcessLength+16;	//������ ó��
	unsigned char * pStartSrc = pSrc+nStartX+nStartY*nImageWidth;		//���μ��� ���ۺ� ó��
	unsigned char * pDestSrc = pDest+nStartX+nStartY*nImageWidth;		//dest ���� ���ۺ� ����Ʈ
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
		//0�� ��ġ		
		pxor xmm7,xmm7				//���� short�� �� �����
		pxor xmm6,xmm6				//���� short�� �� �����

		sub eax, edi
		movdqu xmm5, Mask0			//kernel [m-1][n-1]
		movdqu xmm0,[eax-1]			//src[m-1][n-1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ

		pmullw xmm0, xmm5			//Kernel[m-1][n-1]*src[m-1][n-1]
		pmullw xmm1, xmm5			//Kernel[m-1][n-1]*src[m-1][n-1]

		paddsw xmm7,xmm0			//���� 8 short ��갪 �Է�
		paddsw xmm6,xmm1			//���� 8 short ��갪 �Է�

		//1�� ��ġ
		movdqu xmm5, Mask1			//Kernel[m][n-1]
		movdqu xmm0,[eax]			//src[m][n-1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ
		
		pmullw xmm0, xmm5			//Kernel[m][n-1]*src[m][n-1]
		pmullw xmm1, xmm5			//Kernel[m][n-1]*src[m][n-1]
		
		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��

		//2�� ��ġ
		movdqu xmm5, Mask2			//Kernel[m+1][n-1]
		movdqu xmm0,[eax+1]			//src[m+1][n-1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ
		
		pmullw xmm0, xmm5			//Kernel[m+1][n-1]*src[m+1][n-1]
		pmullw xmm1, xmm5			//Kernel[m+1][n-1]*src[m+1][n-1]
		
		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��
		

		//3�� ��ġ
		add eax, edi
		movdqu xmm5, Mask3			//Kernel[m-1][n]
		movdqu xmm0,[eax-1]			//src[m-1][n]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ

		pmullw xmm0, xmm5			//Kernel[m-1][n]*src[m+1][n]
		pmullw xmm1, xmm5			//Kernel[m-1][n]*src[m+1][n]

		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��

		//4�� ��ġ
		movdqu xmm5, Mask4			//Kernel[m][n]
		movdqu xmm0,[eax]			//src[m][n]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ

		pmullw xmm0, xmm5			//Kernel[m][n]*src[m][n]
		pmullw xmm1, xmm5			//Kernel[m][n]*src[m][n]

		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��
		
		//5�� ��ġ
		movdqu xmm5, Mask5			//Kernel[m+1][n]
		movdqu xmm0,[eax+1]			//src[m+1][n]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ

		pmullw xmm0, xmm5			//Kernel[m+1][n]*src[m+1][n]
		pmullw xmm1, xmm5			//Kernel[m+1][n]*src[m+1][n]

		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��

		//6�� ��ġ
		add eax, edi
		movdqu xmm5, Mask6			//Kernel[m-1][n+1
		movdqu xmm0,[eax-1]			//src[m-1][n+1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ

		pmullw xmm0, xmm5			//Kernel[m-1][n+1]*src[m-1][n+1]
		pmullw xmm1, xmm5			//Kernel[m-1][n+1]*src[m-1][n+1]
		
		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��
		
		//7�� ��ġ
		movdqu xmm5, Mask8			//Kernel[m][n+1]
		movdqu xmm0,[eax]			//src[m][n+1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ

		pmullw xmm0, xmm5			//Kernel[m][n+1]*src[m][n+1]
		pmullw xmm1, xmm5			//Kernel[m][n+1]*src[m][n+1]

		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��
		
		//8�� ��ġ
		movdqu xmm5, xmm3			//Kernel[m+1][n+1]
		movdqu xmm0,[eax+1]			//src[m+1][n+1]
		movdqu xmm1, xmm0
		
		punpcklbw xmm0,xmm4			//����8byte-> short�� ��ȯ
		punpckhbw xmm1,xmm4			//����8byte-> short�� ��ȯ
		
		pmullw xmm0, xmm5			//Kernel[m+1][n+1]*src[m+1][n+1]
		pmullw xmm1, xmm5			//Kernel[m+1][n+1]*src[m+1][n+1]
		
		paddsw xmm7,xmm0			//���� 8 short ��갪 ��
		paddsw xmm6,xmm1			//���� 8 short ��갪 ��
		
		packuswb xmm7,xmm6			//����8 short�� + ���� 8 short�� -> 16byte�� ��ȯ
		movdqu [edx], xmm7

		sub eax, edi
		dec ecx
		cmp ecx,0
		jg ADD16
		je ADDREMAIN
		jl HLOOPEND
ADD16:		//���� ���ι��� 16byte ���� ó�� �ݺ�
		add eax,16
		add edx,16
		jmp HLOOP
ADDREMAIN:	//������ 16���� ó���� ������ �κ� ó��
		add eax,nRemain
		add edx,nRemain
		jmp HLOOP
HLOOPEND:		//���� ���� ���� ����
		add eax,esi
		add edx,esi
		mov ecx, HLoopCount

		dec ebx
		cmp ebx,0
		jz LOOPEND
		jmp VLOOP	//���� ���� ���� ���� ����
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
	
	if(0 == nStartX) nStartX = 1;	//���͸����� ���� ������ ����ó��
	if(0 == nStartY) nStartY = 1;	//���͸����� ���� ������ ����ó��
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
			//(x-1,y-1)16 byte �б�
			ImageLow[1] = _mm_loadu_si128((__m128i*)(iterSrc-nImageWidth));
			//(x,y-1)  16 byte �б�
			ImageLow[2] = _mm_loadu_si128((__m128i*)(iterSrc+1-nImageWidth));
			//(x+1,y-1)16 byte �б�
			ImageLow[3] = _mm_loadu_si128((__m128i*)(iterSrc-1));
			//(x-1,y)  16 byte �б�
			ImageLow[4] = _mm_loadu_si128((__m128i*)(iterSrc));
			//(x,y)    16 byte �б�
			ImageLow[5] = _mm_loadu_si128((__m128i*)(iterSrc+1));
			//(x+1,y)  16 byte �б�
			ImageLow[6] = _mm_loadu_si128((__m128i*)(iterSrc-1+nImageWidth));
			//(x-1,y+1)16 byte �б�
			ImageLow[7] = _mm_loadu_si128((__m128i*)(iterSrc+nImageWidth));
			//(x,y+1)  16 byte �б�
			ImageLow[8] = _mm_loadu_si128((__m128i*)(iterSrc+1+nImageWidth));
			//(x+1,y+1)16 byte �б�

			for( int i = 0; i < 9 ; i++)
			{
				ImageHigh[i] = _mm_unpackhi_epi8(ImageLow[i],ZeroData);
				//���� ��ġ short�� ��ȯ
				ImageLow[i] = _mm_unpacklo_epi8(ImageLow[i],ZeroData);
				//���� ��ġ short�� ��ȯ

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
	
	if(0 == nStartX) nStartX = 1;	//���͸����� ���� ������ ����ó��
	if(0 == nStartY) nStartY = 1;	//���͸����� ���� ������ ����ó��
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
			//(x-1,y-1)16 byte �б�

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[0]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[0]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc-nImageWidth));
			//(x,y-1)  16 byte �б�

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[1]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[1]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc+1-nImageWidth));
			//(x+1,y-1)16 byte �б�

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[2]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[2]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc-1));
			//(x-1,y)  16 byte �б�
			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[3]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[3]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc));
			//(x,y)    16 byte �б�

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[4]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[4]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc+1));
			//(x+1,y)  16 byte �б�

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[5]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[5]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc-1+nImageWidth));
			//(x-1,y+1)16 byte �б�

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[6]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[6]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc+nImageWidth));
			//(x,y+1)  16 byte �б�

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			
			ImageLow = _mm_mullo_epi16(ImageLow,Kernel[7]);
			ImageHigh = _mm_mullo_epi16(ImageHigh,Kernel[7]);
			
			ResultHigh = _mm_adds_epi16(ResultHigh,ImageHigh);
			ResultLow = _mm_adds_epi16(ResultLow,ImageLow);

			ImageLow = _mm_loadu_si128((__m128i*)(iterSrc+1+nImageWidth));
			//(x+1,y+1)16 byte �б�

			ImageHigh = _mm_unpackhi_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			ImageLow = _mm_unpacklo_epi8(ImageLow,ZeroData);
			//���� ��ġ short�� ��ȯ
			
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

	const unsigned int WIDTH = 256;			//�̹��� ���� 300
	const unsigned int HEIGHT = 256;		//�̹��� ���� 300
	const unsigned int IMAGE_SIZE = WIDTH*HEIGHT+4096;	//�̹��� ������ 90000
	const unsigned int BMP_HEADER_LENGTH = 1064;	//bmp �ش� ���� 1064
	
	unsigned char* pSrcA = new unsigned char[IMAGE_SIZE];	//�̹��� ������ ���� A
	unsigned char* pSrcB = new unsigned char[IMAGE_SIZE];	//�̹��� ������ ���� B
	unsigned char* pResult = new unsigned char[IMAGE_SIZE];	//Result ������ ���� 
	unsigned char* pResult2 = new unsigned char[IMAGE_SIZE];	//Result ������ ���� 
	unsigned char* pResult3 = new unsigned char[IMAGE_SIZE];	//Result ������ ���� 

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

