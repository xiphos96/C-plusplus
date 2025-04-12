//================================================================
// 응용 과제 2
// 실습 과제를 발전시킴
// 왼쪽 마우스 버튼에는 임의의 카드들을 생성하고
// 오른쪽 마우스 버튼에는 클릭점을 원점으로 하고
// 반지름이 40인 원들을 그림
// 도형의 개수는 제한 없음
//================================================================
#pragma once
#include "pclaf.h"
#include "Card.h"
#include <vector>

class FigureApp : public Application
{
public:
	FigureApp(const TCHAR*);
	FigureApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void mouseRDown(int, int);
	void paint();
	// data field
	std::vector<FigurePtr> figures;
};