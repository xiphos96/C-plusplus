// LoadStorePD.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "immintrin.h"

int _tmain(int argc, _TCHAR* argv[])
{
	double SrcUnalign[4] = {1,2,3,4};
	double DstUnalign[4] = {0};
	__m256d AvxData = _mm256_setzero_pd();
	
	AvxData = _mm256_loadu_pd(SrcUnalign);
	_mm256_storeu_pd(DstUnalign,AvxData);

	printf("%.2f, %.2f, %.2f, %.2f\n",
		DstUnalign[0],DstUnalign[1],DstUnalign[2],DstUnalign[3]);

	__declspec(align(32)) double SrcAlign[4] = {4,3,2,1};
	__declspec(align(32)) double DstAlign[4] = {0};
	
	AvxData = _mm256_setzero_pd();
	
	AvxData = _mm256_load_pd(SrcAlign);
	_mm256_store_pd(DstAlign,AvxData);

	printf("%.2f, %.2f, %.2f, %.2f\n",
		DstAlign[0],DstAlign[1],DstAlign[2],DstAlign[3]);

	return 0;
}


