// 실습 과제를 발전시킴
// 두 개의 카드를 생성해서 그림
// 카드를 클릭하면 카드가 뒤집기를 반복
#pragma once
#include "Card.h"

class CardApp : public Application
{
public:
	CardApp(const TCHAR*);
	CardApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// data fields
//	CRect a{ 50, 100, 150, 200 };	// Exer: no draw in CRect class
	Card b{ 200, 100, 2, 7 };
	std::shared_ptr<Card> c = std::make_shared<Card>(300, 100, 1, 5);
};