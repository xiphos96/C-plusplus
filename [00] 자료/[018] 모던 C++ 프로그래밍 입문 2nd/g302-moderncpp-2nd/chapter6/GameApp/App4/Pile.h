// PILE CLASSES
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
	virtual bool includes(int, int);
	virtual void display(Application&);
	virtual void select();
	virtual void select(int, int);
	virtual bool canTake(const CardPtr&);
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
	virtual void addCard(const CardPtr&) override;
	virtual void select();
	virtual bool includes(int, int);
};

// SUITPILE CLASS
class SuitPile final : public CardPile
{
public:
	// 생성자 함수
	SuitPile(int, int);
	// 연산
	virtual bool canTake(const CardPtr&);
};

// DISCARDPILE CLASS
class DiscardPile : public CardPile
{
public:
	// 생성자 함수
	DiscardPile(int, int);
	// 연산
	virtual void select();
};

// TABLEPILE CLASS
class TablePile : public CardPile
{
public:
	// 생성자 함수
	TablePile(int, int);
	// 연산
	virtual bool canTake(const CardPtr&);
	virtual void select();
	virtual void select(int, int);
	virtual void display(Application&) final;
};

typedef std::shared_ptr<CardPile> CardPilePtr;