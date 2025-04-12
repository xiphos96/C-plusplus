//================================================================
// �ǽ� ����
// ��ũ ���ϰ� ��ī�� ���� ����
// ��ũ ������ Ŭ���ϸ� ���� �� ī�尡 ��ī�� ���Ͽ� ����
//================================================================
#pragma once
#include "pclaf.h"
#include "Pile.h"

// Customized Application
class PileApp : public Application
{
public:
	PileApp(const TCHAR*);
	PileApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// data fields, �ǽ� ����
	DeckPile theDeck{ 100, 100 };
	CardPile theDiscard{ 200, 100 };
};