//==================================================================
// 응용 과제 2
// 실습 과제를 발전시킴
// 오른쪽 마우스 클릭에는 빨간 선을 그림
// 선의 끝점에 hello 문자열 출력
//==================================================================
#pragma once
#include "pclaf.h"

class PenApp : public Application
{
public:
	PenApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	// 응용 과제 2
	void mouseRDown(int, int);
	void paint();
	// data fields for pen locations
	int oldx = 0;
	int oldy = 0;
	int newx = 0;
	int newy = 0;
};