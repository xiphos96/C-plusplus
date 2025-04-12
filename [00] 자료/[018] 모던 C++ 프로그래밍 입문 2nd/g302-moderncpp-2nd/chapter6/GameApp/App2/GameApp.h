//================================================================
// 응용 과제 2
// 실습 과제를 발전시킴
// 데크 파일이 소진되었을 때 빈 데크 파일을 클릭하면
// 디스카드 파일의 카드들이 데크 파일로 재삽입
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
	void paint();
	void init();
	static std::vector<CardPilePtr> allPilePtr;
	static std::array<Bitmap, 53> cardBitmaps;
};