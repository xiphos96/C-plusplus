// �ǽ� ������ ������Ŵ
// ���콺 ������ ��ư�� �� �� Ŭ������ ���̺� ���� �̵�
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