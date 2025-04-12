// PILE CLASSES
#pragma once
#include "Card.h"
#include <list>				// 응용 과제 2

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
	// 멤버 변수
	int upperLeftX;
	int upperLeftY;
	int count;
	std::list<CardPtr> theCards;	// 응용 과제 2
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