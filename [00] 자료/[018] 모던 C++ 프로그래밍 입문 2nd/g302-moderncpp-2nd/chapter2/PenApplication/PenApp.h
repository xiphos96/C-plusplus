//==================================================================
// 실습 과제
// pclaf를 이용해서 마우스 클릭으로 윈도우에 선을 그림
//==================================================================
#pragma once
#include "pclaf.h"

// Customized Application
class PenApp : public Application
{
public:
	PenApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// 펜 위치를 위한 데이터 필드
	int oldx = 0;
	int oldy = 0;
	int newx = 0;
	int newy = 0;
};