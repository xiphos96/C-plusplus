// squreroot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StopWatch.h"
#include "math.h"
#include "FLOAT.H"

struct _Point
{
	float x;
	float y;
};

float MinLenght(_Point* pRect1, _Point* pRect2)
{
	float MinValue = FLT_MAX;
	float xValue = 0;
	float yValue = 0;
	float Sum = 0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			xValue = pRect1[i].x - pRect2[j].x ;
			yValue = pRect1[i].y - pRect2[j].y ;

			xValue = xValue*xValue;
			yValue = yValue*yValue;

			Sum = xValue + yValue;

			if( MinValue > Sum)
				MinValue = Sum;
			
		}
	}

	return sqrt(MinValue);
};

	
float MinLenghtSIMD(_Point* pRect1, _Point* pRect2)
{
	float Result[4];
	__asm
	{
		pushad
		mov eax, pRect1
		mov ebx, pRect2
		
		movups xmm0, [eax]		//1번째 사각형 좌표 로드
		movups xmm3, xmm0

		movups xmm5, [ebx]		//2번째 사각형 좌표 로드
		movups xmm6, [ebx+16]	//2번째 사각형 좌표 로드

		movups xmm1, xmm0
		
		unpcklpd  xmm0, xmm1	//R1.x1,R1.y1, R1.x1, R1,y1으로 생성
		movups xmm1, xmm0		//재사용을 위해 xmm1에 복사.
		
		subps xmm0, xmm5		//R1.x1-R2.x1, R1.y1-R2.y1, R1.x1-R2.x2, R1.y1-R2.y2
		mulps xmm0, xmm0		//x*x, y*y
		haddps xmm0, xmm0		//x*x+y*y
		
		movups xmm7,xmm0		//결과 저장
		
		subps xmm1, xmm6		//R1.x1-R2.x3, R1.y1-R2.y3, R1.x1-R2.x4, R1.y1-R2.y4
		mulps xmm1, xmm1		//x*x, y*y
		haddps xmm1, xmm1		//x*x+y*y

		minps xmm7, xmm1		//최소값 저장

		movups xmm0, xmm3
		
		movups xmm1, xmm0

		unpckhpd  xmm0, xmm1 	//R1.x2,R1.y2, R1.x2, R1,y2으로 생성
		
		movups xmm1, xmm0		//xmm1에 복사
		
		subps xmm0, xmm5		//R1.x2-R2.x1, R1.y2-R2.y1, R1.x2-R2.x2, R1.y2-R2.y2
		mulps xmm0, xmm0		//x*x, y*y
		haddps xmm0, xmm0		//x*x+y*y
		
		minps xmm7,xmm0
				
		subps xmm1, xmm6		//R1.x2-R2.x3, R1.y2-R2.y3, R1.x2-R1.x4, R1.y2-R1.y4
		mulps xmm1, xmm1		//x*x, y*y
		haddps xmm1, xmm1		//x*x+y*y
		
		minps xmm7, xmm1
		
		movups xmm0, [eax+16]		//P1.x3,P1.y3,P1.x4,P1.y4
		movups xmm3, xmm0

		movups xmm1, xmm0
		
		unpcklpd  xmm0, xmm1
		
		movups xmm1, xmm0
		
		subps xmm0, xmm5
		mulps xmm0, xmm0		//x*x, y*y
		haddps xmm0, xmm0		//x*x+y*y
		
		minps xmm7,xmm0
				
		subps xmm1, xmm6
		mulps xmm1, xmm1		//x*x, y*y
		haddps xmm1, xmm1		//x*x+y*y
		
		minps xmm7, xmm1
		
		movups xmm0, xmm3
		
		movups xmm1, xmm0
		
		unpckhpd  xmm0, xmm1
		
		movups xmm1, xmm0
		
		subps xmm0, xmm5
		mulps xmm0, xmm0		//x*x, y*y
		haddps xmm0, xmm0		//x*x+y*y
		
		minps xmm7,xmm0
		
		subps xmm1, xmm6
		mulps xmm1, xmm1		//x*x, y*y
		haddps xmm1, xmm1		//x*x+y*y
		
		minps xmm7, xmm1
		
		movups xmm6, xmm7
		psrldq xmm6, 4

		minps xmm7,xmm6

		sqrtps xmm7,xmm7		//최소값에 루트 계산
		
		movups Result, xmm7
		
		popad
		
	}
	
	return Result[0];
};

int main(int argc, char* argv[])
{
	_Point RectPoint[4];
	RectPoint[0].x = 5.5;	RectPoint[0].y = 6.5;
	RectPoint[1].x = 5.5;	RectPoint[1].y = 16.5;
	RectPoint[2].x = 8.5;	RectPoint[2].y = 9.5;
	RectPoint[3].x = 11.5;	RectPoint[3].y = 15.5;	
	
	_Point RectPoint2[4];
	RectPoint2[0].x = 15.5;	RectPoint2[0].y = 26.5;
	RectPoint2[1].x = 22.5;	RectPoint2[1].y = 6.5;
	RectPoint2[2].x = 18.5;	RectPoint2[2].y = 19.5;
	RectPoint2[3].x = 1.5;	RectPoint2[3].y = 15.5;

	CStopWatch StopWatch;

	float Result;
	int i = 0;
	StopWatch.Start();
	Result = MinLenghtSIMD(RectPoint, RectPoint2);
	StopWatch.End();
	printf("SIMD Calc %f, %f \n",Result,StopWatch.GetDurationMilliSecond());

	StopWatch.Start();	
	Result = MinLenght(RectPoint, RectPoint2);
	StopWatch.End();
	
	printf("C Calc %f, %f \n",Result,StopWatch.GetDurationMilliSecond());


	return 0;
}

