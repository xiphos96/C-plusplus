//================================================================
// �ǽ� ����
// �� ���� �簢���� �� ���� ī�带 �����ؼ� �׸�
// ù ��° ī�带 Ŭ���ϸ� ī�尡 �����⸦ �ݺ�
//================================================================
#pragma once
#include "pclaf.h"
#include "Card.h"

// Customized Application
class CardApp : public Application
{
public:
	CardApp(const TCHAR*);
	CardApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// data fields
	Rect a{ 50, 100, 150, 200 };
	Card b{ 200, 100, 2, 7 };
	std::shared_ptr<Rect> c = std::make_shared<Card>(300, 100, 3, 5);
//	std::unique_ptr<Rect> c = std::make_unique<Card>(300, 100, 3, 5);
};