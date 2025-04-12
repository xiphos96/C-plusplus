// 실습 과제를 발전시킴
// ScoreManager 클래스 추가
#pragma once
#include "pclaf.h"
#include "Pile.h"
#include <vector>

// Exer
class ScoreManager {
public:
	ScoreManager(int);
	void plusScore(int);
	void minusScore(int);
	void printScore(Application&);
private:
	int totalScore;
};

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
	// Exer
	static ScoreManager score;
};