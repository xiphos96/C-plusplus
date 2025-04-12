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
	/* Syntax1-1
	// ���� ������ �Լ�
	CardPile(const CardPile&);
	// �̵� ������ �Լ�
	CardPile(CardPile&&);
	*/
	// �Ҹ��� �Լ�
	virtual ~CardPile();
	// ����
	virtual CardPtr topCard();
	virtual void addCard(const CardPtr&);
	bool includes(int, int);
//	virtual void display(Application&);				// console version
	virtual void select();
	/* Syntax1-1
	// ���� ���� ������
	CardPile& operator=(const CardPile&);
	// �̵� ���� ������
	CardPile& operator=(CardPile&&);
	*/
	void moveTo(int x, int y);
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
};

// console version
extern std::ostream& operator<<(std::ostream&, const CardPile&);
typedef std::shared_ptr<CardPile> CardPilePtr;