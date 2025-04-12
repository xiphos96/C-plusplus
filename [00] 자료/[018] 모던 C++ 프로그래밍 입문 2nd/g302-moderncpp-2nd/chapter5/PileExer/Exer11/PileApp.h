//================================================================
// ���� ���� 3�� ������Ŵ
// ���� �� ���콺�� ����Ŭ���ϸ� �� ī�� ������
// ī����� ���ڿ� ���� ī����� ������������ ����
// std::sort, lambda
//================================================================
#pragma once
#include "pclaf.h"
#include "Pile.h"

class PileApp : public Application
{
public:
	PileApp(const TCHAR*);
	PileApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void mouseRDown(int, int);
	// Exer
	void doubleClick(int, int);
	void paint();
	// data fields
	DeckPile theDeck{ 100, 100 };
	CardPile theDiscard{ 200, 100 };
};