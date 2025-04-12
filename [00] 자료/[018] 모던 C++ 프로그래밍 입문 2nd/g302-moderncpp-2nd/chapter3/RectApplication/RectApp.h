//====================================================================
// 실습 과제
// 마우스 클릭점을 왼쪽 위 꼭짓점, 폭 70, 높이 50인 청색 사각형을 그림
// 생성된 사각형 내에서 클릭하면 그 점으로 사각형이 이동
//====================================================================
#pragma once
#include "pclaf.h"
class Rect;

// Customized Application
class RectApp : public Application
{
public:
	RectApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// data field
	Rect* theRectPtr = nullptr;
};