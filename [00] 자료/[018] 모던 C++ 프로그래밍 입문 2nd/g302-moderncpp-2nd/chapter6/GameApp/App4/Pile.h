// PILE CLASSES
#pragma once
#include "Card.h"
#include <array>

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
	virtual bool includes(int, int);
	virtual void display(Application&);
	virtual void select();
	virtual void select(int, int);
	virtual bool canTake(const CardPtr&);
	// ��� ����
	int upperLeftX;
	int upperLeftY;
	int count;
	std::array<CardPtr, MAX_CARDS> theCards;
};

// DECKPILE CLASS
class DeckPile : public CardPile
{
public:
	// ������ �Լ�
	DeckPile(int, int);
	// ����
	virtual void addCard(const CardPtr&) override;
	virtual void select();
	virtual bool includes(int, int);
};

// SUITPILE CLASS
class SuitPile final : public CardPile
{
public:
	// ������ �Լ�
	SuitPile(int, int);
	// ����
	virtual bool canTake(const CardPtr&);
};

// DISCARDPILE CLASS
class DiscardPile : public CardPile
{
public:
	// ������ �Լ�
	DiscardPile(int, int);
	// ����
	virtual void select();
};

// TABLEPILE CLASS
class TablePile : public CardPile
{
public:
	// ������ �Լ�
	TablePile(int, int);
	// ����
	virtual bool canTake(const CardPtr&);
	virtual void select();
	virtual void select(int, int);
	virtual void display(Application&) final;
};

typedef std::shared_ptr<CardPile> CardPilePtr;