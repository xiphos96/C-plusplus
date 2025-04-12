// MemcopyTest.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <memory.h>
#include "StopWatch.h"

void MemcpySIMD(char* pSrc, char *pDest, int Size)
{
	int loopSize = Size / 128;
	
	__asm
	{
		pushad
		mov ecx, loopSize
		mov eax, pSrc
		mov edx, pDest
		mov esi, 0
		
MEMLP:
		//			prefetchnta [eax+256]
		movdqa xmm0, [eax+esi]
		movdqa xmm1, [eax+esi+16]
		movdqa xmm2, [eax+esi+32]
		movdqa xmm3, [eax+esi+48]
		movdqa xmm4, [eax+esi+64]
		movdqa xmm5, [eax+esi+80]
		movdqa xmm6, [eax+esi+96]
		movdqa xmm7, [eax+esi+112]
		
		
		movdqa [edx+esi], xmm0
		movdqa [edx+esi+16], xmm1
		movdqa [edx+esi+32], xmm2
		movdqa [edx+esi+48], xmm3
		movdqa [edx+esi+64], xmm4
		movdqa [edx+esi+80], xmm5
		movdqa [edx+esi+96], xmm6
		movdqa [edx+esi+112], xmm7
		
		//add eax, 128
		add esi, 128
		dec ecx
		jnz MEMLP
		sfence
		popad
		
	}
}


void MemcpySIMD2(char* pSrc, char *pDest, int Size)
{
	int loopSize = Size / 128;
	
	__asm
	{
		pushad
		mov ecx, loopSize
		mov eax, pSrc
		mov edx, pDest
			
MEMLP:
		movdqa xmm0, [eax]
		movdqa xmm1, [eax+16]
		movdqa xmm2, [eax+32]
		movdqa xmm3, [eax+48]
		movdqa xmm4, [eax+64]
		movdqa xmm5, [eax+80]
		movdqa xmm6, [eax+96]
		movdqa xmm7, [eax+112]
			
		movdqa [edx], xmm0
		movdqa [edx+16], xmm1
		movdqa [edx+32], xmm2
		movdqa [edx+48], xmm3
		movdqa [edx+64], xmm4
		movdqa [edx+80], xmm5
		movdqa [edx+96], xmm6
		movdqa [edx+112], xmm7
			
		add eax, 128
		add edx, 128
		dec ecx
		jnz MEMLP
			
		popad
		
	}
}


void MemcpySIMD3(char* pSrc, char *pDest, int Size)
{
	int loopSize = Size / 128;
	
	__asm
	{
		pushad
		mov ecx, loopSize
		mov eax, pSrc
		mov edx, pDest
		
MEMLP:
//		prefetchnta [eax+256]
		movdqa xmm0, [eax]
		movdqa xmm1, [eax+16]
		movdqa xmm2, [eax+32]
		movdqa xmm3, [eax+48]
		movdqa xmm4, [eax+64]
		movdqa xmm5, [eax+80]
		movdqa xmm6, [eax+96]
		movdqa xmm7, [eax+112]
		
		
		movntdq  [edx], xmm0
		movntdq  [edx+16], xmm1
		movntdq  [edx+32], xmm2
		movntdq  [edx+48], xmm3
		movntdq  [edx+64], xmm4
		movntdq  [edx+80], xmm5
		movntdq  [edx+96], xmm6
		movntdq  [edx+112], xmm7
		
		add eax, 128
		add edx, 128
		dec ecx
		jnz MEMLP
		sfence
		popad
		
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
    const int BuffSize = 100000000;
	char* pChar = new char[BuffSize];
	char* pChar2 = new char[BuffSize];
	
	for(int i = 0; i < BuffSize; i ++)
	{
		pChar[i] = 5;
	}
	
	CStopWatch StopWatch;

	StopWatch.Start();
	MemcpySIMD(pChar,pChar2,BuffSize);
	StopWatch.End();
	printf("movdqa : %f\n",StopWatch.GetDurationMilliSecond());

	StopWatch.Start();
	MemcpySIMD2(pChar,pChar2,BuffSize);
	StopWatch.End();
	printf("movdqa : %f\n",StopWatch.GetDurationMilliSecond());

	StopWatch.Start();
	MemcpySIMD3(pChar,pChar2,BuffSize);
	StopWatch.End();
	printf("movnts : %f\n",StopWatch.GetDurationMilliSecond());

    StopWatch.Start();
    memcpy(pChar,pChar2,BuffSize);
	StopWatch.End();
	printf("memcpy : %f\n",StopWatch.GetDurationMilliSecond());
	delete[] pChar;

	return 0;
}

