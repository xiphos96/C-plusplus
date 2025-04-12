// LoadStore.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	float SrcUnalign[8] = {1,2,3,4,5,6,7,8};
	float DstUnalign[8] = {0};

	__asm
	{
		vmovups ymm0, SrcUnalign
		vmovups DstUnalign, ymm0
	}
	
	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstUnalign[0],DstUnalign[1],DstUnalign[2],DstUnalign[3],
		DstUnalign[4],DstUnalign[5],DstUnalign[6],DstUnalign[7]);

	__declspec(align(32)) float SrcAlign[8] = {8,7,6,5,4,3,2,1};
	__declspec(align(32)) float DstAlign[8] = {0};
	
	__asm
	{
		vmovaps ymm0, SrcAlign
		vmovaps DstAlign, ymm0
	}

	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
		DstAlign[0],DstAlign[1],DstAlign[2],DstAlign[3],
		DstAlign[4],DstAlign[5],DstAlign[6],DstAlign[7]);

	return 0;
}

