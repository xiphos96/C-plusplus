// image.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StopWatch.h"

int ImageSum(const unsigned char *ImageA, const unsigned char *ImageB, unsigned char *ResultImage, const unsigned char nFrame, const int nImageSize)
{
	if( nFrame == 0 || nFrame == 8)
		return -1;	// 0�����Ӱ� 8�������� A,B �̹����� ����ϸ� �ǹǷ� ������� �ʴ´�.
	const unsigned char* pImageA = ImageA;
	const unsigned char* pImageB = ImageB;
	unsigned char* pResult = ResultImage;
	unsigned short RatioA[8] = {0};
	unsigned short RatioB[8] = {0};
	unsigned char Ratioindex = 0;
	for( Ratioindex = 0; Ratioindex < 8; Ratioindex++)
		RatioA[Ratioindex] = nFrame;		//8���� �ѹ��� ����� A ����ġ ����ũ ����
	
	for( Ratioindex = 0; Ratioindex < 8; Ratioindex++)
		RatioB[Ratioindex] = 8 - nFrame;	//8���� �ѹ��� ����� B ����ġ ����ũ ����
	
	unsigned int nLoopCount = (nImageSize/16)*16;
	unsigned int nRemain = nImageSize - nLoopCount;

	__asm
	{
		pushad
			
			mov eax, pImageA	//eax = pImageA
			mov ebx, pImageB	//ebx = pImageB
			mov edi, pResult	//edi = pResult
			mov esi, 0			//esi = 0; �ҽ� �ε���
			mov ecx, nLoopCount	//ecx = nLoopCount; Loop limit
			
			pxor xmm4,xmm4		//xmm4 = 0; temp ����
			movdqu xmm5, RatioA	//xxm5 = RatioA; xmm5�� A����ġ ����ũ ��������
			movdqu xmm6, RatioB //xmm6 = RatioB; xmm6�� B����ġ ����ũ ��������
			
SIMDLOOP:
			movdqu xmm0, [eax+esi]
			movdqu xmm1, xmm0
			
			movdqu xmm2, [ebx+esi]
			movdqu xmm3, xmm2
			
			punpcklbw xmm0, xmm4
			punpcklbw xmm2, xmm4

			pmullw xmm0, xmm5
			pmullw xmm2, xmm6
			
			pavgw xmm0, xmm2
			
			psrlw xmm0, 2
			
			punpckhbw xmm1, xmm4
			punpckhbw xmm3, xmm4
			
			pmullw xmm1, xmm5
			pmullw xmm3, xmm6
			
			pavgw xmm1, xmm3
			
			psrlw xmm1, 2
			
			packuswb xmm0,xmm1
			
			movdqu [edi+esi], xmm0
			
			add esi, 16
			cmp esi, nLoopCount
			jne SIMDLOOP
			
			popad
			
	}
	
	if( nRemain != 0)
	{
		for(int i = nImageSize- nRemain; i < nImageSize; i++)
		{
			pResult[i] = (pImageA[i] + pImageB[i])/8;
		}
		
	}
	
	return 1;
}

int ImageSumC(const unsigned char *ImageA, const unsigned char *ImageB,unsigned char *ResultImage, const unsigned char nFrame, const int nImageSize)
{
	if( nFrame == 0 || nFrame == 8)
		return -1;	// 0�����Ӱ� 8�������� A,B �̹����� ����ϸ� �ǹǷ� ������� �ʴ´�.
	
	unsigned short	RatioA = nFrame;		//8���� �ѹ��� ����� A ����ġ ����ũ ����
	unsigned short	RatioB = 8 - nFrame;	//8���� �ѹ��� ����� B ����ġ ����ũ ����
	unsigned short	AValue = 0;
	unsigned short	BValue = 0;
	
	for( int nIndex = 0; nIndex < nImageSize; nIndex++)
	{
		AValue = ImageA[nIndex];
		BValue = ImageB[nIndex];
		ResultImage[nIndex] =unsigned char(( RatioA*AValue + RatioB*BValue ) / 8);
	}
	
	return 1;
}


int main(int argc, char* argv[])
{

	CStopWatch StopWatch;
	unsigned char* pData1 = new unsigned char [1024*1024];
	unsigned char* pData2 = new unsigned char [1024*1024];
	unsigned char* pData3 = new unsigned char [1024*1024];

	StopWatch.Start();
	ImageSumC(pData1,pData2,pData3,1,1024*1024);
	StopWatch.End();
	
	printf("C Time : %f \n", StopWatch.GetDurationMilliSecond());

	
	StopWatch.Start();
	ImageSum(pData1,pData2,pData3,1,1024*1024);
	StopWatch.End();
	
	printf("SIMD Time : %f \n", StopWatch.GetDurationMilliSecond());
	
	delete[] pData1;
	delete[] pData2;
	delete[] pData3;

	return 0;
}

