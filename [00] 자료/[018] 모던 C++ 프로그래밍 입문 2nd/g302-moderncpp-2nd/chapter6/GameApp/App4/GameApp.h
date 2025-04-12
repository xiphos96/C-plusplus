//================================================================
// 응용 과제 4
// 응용 과제 3을 발전시킴
// 게임에 이기면 애니메이션
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
	void mouseRDown(int, int);
	void paint();
	void init();
	static std::vector<CardPilePtr> allPilePtr;
	static std::array<Bitmap, 53> cardBitmaps;
	// 응용 과제 4
	bool winGame = false;
};