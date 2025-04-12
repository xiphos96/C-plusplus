//================================================================
// 응용 과제 3을 발전시킴
// 실행 중 마우스를 더블클릭하면 디스 카드 파일의
// 카드들의 숫자에 따라 카드들을 오름차순으로 정렬
// std::sort, lambda
//================================================================
#pragma once
#include "pclaf.h"
#include "Pile.h"

class PileApp : public Application
{
public:
	PileApp(const TCHAR*);
	PileApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void mouseRDown(int, int);
	// Exer
	void doubleClick(int, int);
	void paint();
	// data fields
	DeckPile theDeck{ 100, 100 };
	CardPile theDiscard{ 200, 100 };
};