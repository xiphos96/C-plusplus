//================================================================
// 응용 과제 3
// 응용 과제 2를 발전시킴
// 도형을 10개까지 생성 후 도형을 더블 클릭하면
// 선택된 도형이 초록색으로 변함
// std::array 사용
//================================================================
#pragma once
#include "pclaf.h"
#include "Card.h"
#include <array>

const int MAX_FIGURES = 10;

class FigureApp : public Application
{
public:
	FigureApp(const TCHAR*);
	FigureApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void mouseRDown(int, int);
	// 응용 과제 3
	void doubleClick(int, int);
	void paint();
	// data fields, 응용 과제 3
	int numFigures = 0;
	std::array<FigurePtr, MAX_FIGURES> figures;
};