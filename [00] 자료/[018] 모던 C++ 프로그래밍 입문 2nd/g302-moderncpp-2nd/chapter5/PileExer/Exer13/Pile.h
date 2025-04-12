// PILE CLASSES
#pragma once
#include "Card.h"
#include <list>

const int MAX_CARDS = 52;

// CARDPILE CLASS
class CardPile
{
public:
	// 생성자 함수, 파라미터는 왼쪽위 꼭짓점
	CardPile(int, int);
	// 연산
	virtual CardPtr topCard();
	virtual void addCard(const CardPtr&);
	bool includes(int, int);
	virtual void display(Application&);
	virtual void select();
	virtual void display(Application&, int);
	// Exer
	int sumRank();
	// 멤버 변수
	int upperLeftX;
	int upperLeftY;
	int count;
	std::list<CardPtr> theCards;
	bool wideDisplay = false;
};

// DECKPILE CLASS
class DeckPile : public CardPile
{
public:
	// 생성자 함수
	DeckPile(int, int);
	// 연산
	virtual void addCard(const CardPtr&);
};

typedef std::shared_ptr<CardPile> CardPilePtr;