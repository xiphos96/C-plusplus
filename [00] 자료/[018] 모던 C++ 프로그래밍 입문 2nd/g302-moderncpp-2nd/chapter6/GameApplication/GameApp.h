//================================================================
// �ǽ� ����
// Solitaire ī�� ���� �⺻ ����
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
	// static ����� ����, �ǽ� ����
	static std::vector<CardPilePtr> allPilePtr;
	// ī�� ��Ʈ�� �迭, �ǽ� ����
	static std::array<Bitmap, 53> cardBitmaps;
};