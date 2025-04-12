//================================================================
// 응용 과제 3
// 응용 과제 2를 발전시킴
// 테이블 파일 간 카드 그룹의 이동을 지원
//================================================================
#pragma once
#include "pclaf.h"
#include "Pile.h"
#include <vector>

class GameApp : public Application
{
public:
	GameApp(const TCHAR*);
	GameApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	// 응용 과제 3
	void mouseRDown(int, int);
	void paint();
	void init();
	static std::vector<CardPilePtr> allPilePtr;
	static std::array<Bitmap, 53> cardBitmaps;
};