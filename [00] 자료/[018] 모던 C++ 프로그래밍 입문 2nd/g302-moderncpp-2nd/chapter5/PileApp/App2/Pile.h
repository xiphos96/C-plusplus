// PILE CLASSES
#pragma once
#include "Card.h"
#include <list>				// ���� ���� 2

const int MAX_CARDS = 52;

// CARDPILE CLASS
class CardPile
{
public:
	// ������ �Լ�, �Ķ���ʹ� ������ ������
	CardPile(int, int);
	// ����
	virtual CardPtr topCard();
	virtual void addCard(const CardPtr&);
	bool includes(int, int);
	virtual void display(Application&);
	virtual void select();
	// ��� ����
	int upperLeftX;
	int upperLeftY;
	int count;
	std::list<CardPtr> theCards;	// ���� ���� 2
};

// DECKPILE CLASS
class DeckPile : public CardPile
{
public:
	// ������ �Լ�
	DeckPile(int, int);
	// ����
	virtual void addCard(const CardPtr&);
};

typedef std::shared_ptr<CardPile> CardPilePtr;