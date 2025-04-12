// PILE CLASS
#pragma once
#include "Card.h"
#include <array>

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
	std::array<CardPtr, MAX_CARDS> theCards;
};

// DECKPILE CLASS
class DeckPile : public CardPile
{
public:
	// 생성자 함수
	DeckPile(int, int);
	// 연산
	virtual void addCard(const CardPtr&);		// 랜덤 삽입을 위해 재정의
};

typedef std::shared_ptr<CardPile> CardPilePtr;