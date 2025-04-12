// LoadAndStoreAlign.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <emmintrin.h>

int main(int argc, char* argv[])
{
	__declspec(align(16)) short Source[8] = {1,2,3,4,5,6,7,8};
	__declspec(align(16)) short Dest[8] = {0};
	
	__m128i Temp = _mm_load_si128((__m128i*)Source);
	
	_mm_store_si128((__m128i*)Dest,Temp);
	
	printf("Dest : %d, %d, %d, %d, %d, %d, %d, %d\n"
		,Dest[7],Dest[6],Dest[5],Dest[4],Dest[3],Dest[2],Dest[1],Dest[0]);
	return 0;
}