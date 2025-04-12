// FindShortPosition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "memory.h"
#include "StopWatch.h"
#include <algorithm>

int FindPositionSTL(const short *pShortArray, const short nFindValue, const int nSize)
{
	const short * pPosition = std::find(pShortArray, pShortArray+nSize, nFindValue);
	return pPosition-pShortArray;
}

int FindPositionC(const short *pShortArray, const short nFindValue, const int nSize)
{
    int i = 0;
	for( i = 0; i< nSize ; i++)
	{
		if(pShortArray[i] == nFindValue)
			return i;
	}
	return i;
}

int FindPositionSIMD(const short *pShortArray, const short nFindValue, const int nSize)
{
	const short* pShort = pShortArray;
	
	int nLoopCount = (nSize / 8)*16; 		//8����� ������ �����Ѵ�.
	int nRemain = nSize % 8;
	
	short pFindMask[8] = {0};
	unsigned char j= 0;
	for( j= 0; j < 8; j++)
	{
		pFindMask[j] = nFindValue; 	//Ž���� ���� ���� 128bit ����ũ ����
	}
	
	int nFindCount = 0;
	int nPosition = 0;
	
	__asm
	{
		pushad
		mov eax, pShort
		mov edx, 0
		mov esi, 0
		mov ecx, nLoopCount
		
		movdqu  xmm5, pFindMask	//xmm5 = mask;
			
FINDLOOP:
		movdqu  xmm0, [eax+esi] 	//�޸��� ���� xmm0�� ����
		pcmpeqw xmm0, xmm5		//����ũ�� ���� ���� ���� �ִ��� ��
		pmovmskb ebx, xmm0		//package�� ���� 1bit�� �����Ѵ�.
		
		cmp ebx, 0			//���� ���� �ִ��� ��
		je NOTFIND			//���� ���� ������ ���� ����
		{
			//���� ���� ������ package ���� ���캻��.
			pextrw ebx, xmm0, 0	//0��° pack �� ����
			cmp ebx, 0		//���� �ִ��� ��
			je NOTFIND0		//���� ������ ���� pack���� �̵�
			mov edx, 0		//���� ������ ������ġ�� �����ϰ� ����
			jp FINDEND
NOTFIND0:
			pextrw ebx, xmm0, 1	//1��° pack �� ����
			cmp ebx, 0		//���� �ִ��� ��
			je NOTFIND1		//���� ������ ���� pack���� �̵�
			mov edx, 1		//���� ������ ������ġ�� �����ϰ� ����
			jp FINDEND
NOTFIND1:
			pextrw ebx, xmm0, 2	//2��° pack �� ����
			cmp ebx, 0		//���� �ִ��� ��
			je NOTFIND2		//���� ������ ���� pack���� �̵�
			mov edx, 2		//���� ������ ������ġ�� �����ϰ� ����
			jp FINDEND
NOTFIND2:
			pextrw ebx, xmm0, 3	//3��° pack �� ����
			cmp ebx, 0		//���� �ִ��� ��
			je NOTFIND3		//���� ������ ���� pack���� �̵�
			mov edx, 3		//���� ������ ������ġ�� �����ϰ� ����
			jp FINDEND
NOTFIND3:
			pextrw ebx, xmm0, 4	//4��° pack �� ����
			cmp ebx, 0		//���� �ִ��� ��
			je NOTFIND4		//���� ������ ���� pack���� �̵�
			mov edx, 4		//���� ������ ������ġ�� �����ϰ� ����
			jp FINDEND
NOTFIND4:
			pextrw ebx, xmm0, 5	//5��° pack �� ����
			cmp ebx, 0		//���� �ִ��� ��
			je NOTFIND5		//���� ������ ���� pack���� �̵�
			mov edx, 5		//���� ������ ������ġ�� �����ϰ� ����
			jp FINDEND
NOTFIND5:
			pextrw ebx, xmm0, 6	//6��° pack �� ����
			cmp ebx, 0		//���� �ִ��� ��
			je NOTFIND6		//���� ������ ���� pack���� �̵�
			mov edx, 6		//���� ������ ������ġ�� �����ϰ� ����
			jp FINDEND
NOTFIND6:
			pextrw ebx, xmm0, 7	//7��° pack �� ����
			cmp ebx, 0		//���� �ִ��� ��
			je NOTFIND7		//���� ������ ���� pack���� �̵�
			mov edx, 7		//���� ������ ������ġ�� �����ϰ� ����
			jp FINDEND
NOTFIND7:
		}
NOTFIND:
		add esi, 16	//ã�� �������� ���� 16 byte�� �̵�
		cmp esi, ecx
		jne FINDLOOP	//�������������� �̵�

FINDEND:
		mov eax, esi	//���� ã����
		shr eax, 1	//short�� ũ���̹Ƿ� 2�� ������ �ش�.
		add eax, edx	//���� package���̸� �����ش�.
		mov nPosition, eax	//����� ����

		popad
		
	}
	
	if( nRemain != 0 && nPosition == 0)
	{
		for( int i = nSize-nRemain; i< nSize; i++)
		{
			if(pShortArray[i] == nFindValue )
				return i;
		}
	}
		
	return nPosition;
}


int main(int argc, char* argv[])
{
	CStopWatch StopWatch;
	const int MAX_SIZE = 100000000;
	
	short* pShortArray = new short[MAX_SIZE];
	memset( pShortArray, 0x00, MAX_SIZE*sizeof(short));

	pShortArray[9000004] = 100;

	int nResult = 0;
		
	StopWatch.Start();
	nResult = FindPositionC(pShortArray,100,MAX_SIZE);
	StopWatch.End();
	
	printf("C Find Count : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());
		
	StopWatch.Start();
	nResult = FindPositionSTL(pShortArray,100,MAX_SIZE);
	StopWatch.End();
	
	printf("STL Find Count : %d, Time : %f \n", nResult,StopWatch.GetDurationMilliSecond());

	StopWatch.Start();
	nResult = FindPositionSIMD(pShortArray,100,MAX_SIZE);
	StopWatch.End();
	
	printf("SIMD Find Count : %d, Time : %f \n", nResult, StopWatch.GetDurationMilliSecond());
	delete[] pShortArray;

	return 0;
}

