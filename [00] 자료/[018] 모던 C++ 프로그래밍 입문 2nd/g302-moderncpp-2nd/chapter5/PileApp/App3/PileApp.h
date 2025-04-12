//================================================================
// 응용 과제 3
// 실습 과제를 발전시킴
// 오른쪽 마우스 버튼으로 디스카드 파일 접고 펼치기
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
	// 응용 과제 3
	void mouseRDown(int, int);
	void paint();
	// data fields
	DeckPile theDeck{ 100, 100 };
	CardPile theDiscard{ 200, 100 };
};