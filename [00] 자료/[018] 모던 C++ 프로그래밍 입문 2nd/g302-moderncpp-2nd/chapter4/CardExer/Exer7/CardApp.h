// �ǽ� ������ ������Ŵ
// �� ���� ī�带 �����ؼ� �׸�
// ī�带 Ŭ���ϸ� ī�尡 �����⸦ �ݺ�
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