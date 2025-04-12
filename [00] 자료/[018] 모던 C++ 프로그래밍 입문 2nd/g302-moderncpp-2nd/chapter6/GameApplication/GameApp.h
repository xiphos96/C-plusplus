//================================================================
// 실습 과제
// Solitaire 카드 게임 기본 버전
//================================================================
#pragma once
#include "pclaf.h"
#include "Pile.h"
#include <vector>

// Customized Application
class GameApp : public Application
{
public:
	GameApp(const TCHAR*);
	GameApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	void init();
	// static 멤버의 선언, 실습 과제
	static std::vector<CardPilePtr> allPilePtr;
	// 카드 비트맵 배열, 실습 과제
	static std::array<Bitmap, 53> cardBitmaps;
};