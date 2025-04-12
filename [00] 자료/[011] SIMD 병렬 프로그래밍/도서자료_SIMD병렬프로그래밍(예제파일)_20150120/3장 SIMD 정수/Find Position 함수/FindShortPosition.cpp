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
	
	int nLoopCount = (nSize / 8)*16; 		//8배수씩 루프를 진행한다.
	int nRemain = nSize % 8;
	
	short pFindMask[8] = {0};
	unsigned char j= 0;
	for( j= 0; j < 8; j++)
	{
		pFindMask[j] = nFindValue; 	//탐색할 값을 가진 128bit 마스크 생성
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
		movdqu  xmm0, [eax+esi] 	//메모리의 값을 xmm0에 대입
		pcmpeqw xmm0, xmm5		//마스크의 값과 같은 값이 있는지 비교
		pmovmskb ebx, xmm0		//package의 값을 1bit씩 추출한다.
		
		cmp ebx, 0			//같은 값이 있는지 비교
		je NOTFIND			//같은 값이 없으면 루프 실행
		{
			//같은 값이 있으면 package 안을 살펴본다.
			pextrw ebx, xmm0, 0	//0번째 pack 값 추출
			cmp ebx, 0		//값이 있는지 비교
			je NOTFIND0		//값이 없으면 다음 pack으로 이동
			mov edx, 0		//값이 있으면 현재위치를 저장하고 리턴
			jp FINDEND
NOTFIND0:
			pextrw ebx, xmm0, 1	//1번째 pack 값 추출
			cmp ebx, 0		//값이 있는지 비교
			je NOTFIND1		//값이 없으면 다음 pack으로 이동
			mov edx, 1		//값이 있으면 현재위치를 저장하고 리턴
			jp FINDEND
NOTFIND1:
			pextrw ebx, xmm0, 2	//2번째 pack 값 추출
			cmp ebx, 0		//값이 있는지 비교
			je NOTFIND2		//값이 없으면 다음 pack으로 이동
			mov edx, 2		//값이 있으면 현재위치를 저장하고 리턴
			jp FINDEND
NOTFIND2:
			pextrw ebx, xmm0, 3	//3번째 pack 값 추출
			cmp ebx, 0		//값이 있는지 비교
			je NOTFIND3		//값이 없으면 다음 pack으로 이동
			mov edx, 3		//값이 있으면 현재위치를 저장하고 리턴
			jp FINDEND
NOTFIND3:
			pextrw ebx, xmm0, 4	//4번째 pack 값 추출
			cmp ebx, 0		//값이 있는지 비교
			je NOTFIND4		//값이 없으면 다음 pack으로 이동
			mov edx, 4		//값이 있으면 현재위치를 저장하고 리턴
			jp FINDEND
NOTFIND4:
			pextrw ebx, xmm0, 5	//5번째 pack 값 추출
			cmp ebx, 0		//값이 있는지 비교
			je NOTFIND5		//값이 없으면 다음 pack으로 이동
			mov edx, 5		//값이 있으면 현재위치를 저장하고 리턴
			jp FINDEND
NOTFIND5:
			pextrw ebx, xmm0, 6	//6번째 pack 값 추출
			cmp ebx, 0		//값이 있는지 비교
			je NOTFIND6		//값이 없으면 다음 pack으로 이동
			mov edx, 6		//값이 있으면 현재위치를 저장하고 리턴
			jp FINDEND
NOTFIND6:
			pextrw ebx, xmm0, 7	//7번째 pack 값 추출
			cmp ebx, 0		//값이 있는지 비교
			je NOTFIND7		//값이 없으면 다음 pack으로 이동
			mov edx, 7		//값이 있으면 현재위치를 저장하고 리턴
			jp FINDEND
NOTFIND7:
		}
NOTFIND:
		add esi, 16	//찾지 못했으면 다음 16 byte로 이동
		cmp esi, ecx
		jne FINDLOOP	//루프시작점으로 이동

FINDEND:
		mov eax, esi	//값을 찾았음
		shr eax, 1	//short형 크기이므로 2로 나누어 준다.
		add eax, edx	//내부 package길이를 더해준다.
		mov nPosition, eax	//결과값 리턴

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

