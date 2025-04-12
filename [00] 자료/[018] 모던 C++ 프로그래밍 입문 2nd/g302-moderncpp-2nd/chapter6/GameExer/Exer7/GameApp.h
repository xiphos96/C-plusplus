// 실습 과제를 발전시킴
// 마우스 오른쪽 버튼의 두 번 클릭으로 테이블 파일 이동
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
	// Exer
	void mouseRDown(int, int);
	void paint();
	void init();
	static std::vector<CardPilePtr> allPilePtr;
	static std::array<Bitmap, 53> cardBitmaps;
};