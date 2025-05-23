//================================================================
// 실습 과제
// 데크 파일과 디스카드 파일 생성
// 데크 파일을 클릭하면 제일 위 카드가 디스카드 파일에 삽입
// 더블클릭하면 데크 파일과 디스카드 파일이
// 소유한 카드들의 숫자 합 출력
//================================================================
#pragma once
#include "pclaf.h"
#include "Pile.h"

// Customized Application
class PileApp : public Application
{
public:
	PileApp(const TCHAR*);
	PileApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	// Exer
	void doubleClick(int, int);
	void paint();
	// data fields, 실습 과제
	DeckPile theDeck{ 100, 100 };
	CardPile theDiscard{ 200, 100 };
};