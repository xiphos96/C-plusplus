// Refined Pile Classes - console version
#pragma once
#include "Card.h"
#include <array>

const int MAX_CARDS = 52;

// Refined CardPile Class - console version
class CardPile
{
public:
	// ������ �Լ�, �Ķ���ʹ� ������ ������
	CardPile(int, int);
	// ���� ������ �Լ�
	CardPile(const CardPile&);
	// �̵� ������ �Լ�
	CardPile(CardPile&&);
	// �Ҹ��� �Լ�
	virtual ~CardPile();
	// ����
	virtual CardPtr topCard();
	virtual void addCard(const CardPtr&);
	bool includes(int, int);
	virtual void select();
	// ���� ���� ������
	CardPile& operator=(const CardPile&);
	// �̵� ���� ������
	CardPile& operator=(CardPile&&);
	void moveTo(int x, int y);
	virtual bool canTake(const CardPtr&);		// 6��
	// ���� �Լ�
	int getUpperLeftX() const;
	int getUpperLeftY() const;
	int getCount() const;
	// ���� �Լ�
	void setUpperLeftX(int);
	void setUpperLeftY(int);
	// console version
	friend std::ostream& operator<<(std::ostream&, const CardPile&);
protected:
	// ��� ����
	int upperLeftX;
	int upperLeftY;
	int count;
	std::array<CardPtr, MAX_CARDS> theCards;
};

// Refined DeckPile Class - console version
class DeckPile : public CardPile
{
public:
	// ������ �Լ�
	DeckPile(int, int);
	// ����
	virtual void addCard(const CardPtr&);
	virtual void select();				// 6��
};

// 6��
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
//	virtual void display(Application&) final;	// console version
};

// console version
extern std::ostream& operator<<(std::ostream&, const CardPile&);
typedef std::shared_ptr<CardPile> CardPilePtr;