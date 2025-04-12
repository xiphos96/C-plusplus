// ReadByte2float.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char nSrc[20] = {1,2,3,4,5,6,7,8};
	
	float DstPS[8] = {0};

	__asm
	{
		vpmovzxbd xmm1, [nSrc]
		vpmovzxbd xmm2, [nSrc+4]
		vxorps ymm0, ymm0, ymm0
			
		vinsertf128 ymm0,ymm0,xmm1,0 
		vinsertf128 ymm0,ymm0,xmm2,1 

		vcvtdq2ps   ymm0,ymm0
		vmovups DstPS, ymm0
	}

	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstPS[0],DstPS[1],DstPS[2],DstPS[3],
		DstPS[4],DstPS[5],DstPS[6],DstPS[7]);

	return 0;
}

