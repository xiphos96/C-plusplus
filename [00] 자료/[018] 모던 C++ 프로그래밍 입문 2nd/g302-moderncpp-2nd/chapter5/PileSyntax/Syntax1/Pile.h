// Refined Pile Classes - console version
#pragma once
#include "Card.h"
#include <array>

const int MAX_CARDS = 52;

// Refined CardPile Class - console version
class CardPile
{
public:
	// 생성자 함수, 파라미터는 왼쪽위 꼭짓점
	CardPile(int, int);
	/* Syntax1-1
	// 복사 생성자 함수
	CardPile(const CardPile&);
	// 이동 생성자 함수
	CardPile(CardPile&&);
	*/
	// 소멸자 함수
	virtual ~CardPile();
	// 연산
	virtual CardPtr topCard();
	virtual void addCard(const CardPtr&);
	bool includes(int, int);
//	virtual void display(Application&);				// console version
	virtual void select();
	/* Syntax1-1
	// 복사 배정 연산자
	CardPile& operator=(const CardPile&);
	// 이동 배정 연산자
	CardPile& operator=(CardPile&&);
	*/
	void moveTo(int x, int y);
	// 접근 함수
	int getUpperLeftX() const;
	int getUpperLeftY() const;
	int getCount() const;
	// 변경 함수
	void setUpperLeftX(int);
	void setUpperLeftY(int);
	// console version
	friend std::ostream& operator<<(std::ostream&, const CardPile&);
protected:
	// 멤버 변수
	int upperLeftX;
	int upperLeftY;
	int count;
	std::array<CardPtr, MAX_CARDS> theCards;
};

// Refined DeckPile Class - console version
class DeckPile : public CardPile
{
public:
	// 생성자 함수
	DeckPile(int, int);
	// 연산
	virtual void addCard(const CardPtr&);
};

// console version
extern std::ostream& operator<<(std::ostream&, const CardPile&);
typedef std::shared_ptr<CardPile> CardPilePtr;