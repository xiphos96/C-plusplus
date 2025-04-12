#include "Pile.h"
#include <random>
#include <ctime>
#include <algorithm>

// console version - uses GameApp.cpp file's global var
extern std::vector<CardPilePtr> allPilePtr;
std::mt19937 eng(static_cast<unsigned long>(time(nullptr)));

CardPile::CardPile(int x, int y)
	: upperLeftX(x), upperLeftY(y), count(0)
{}

// 복사 생성자 함수
CardPile::CardPile(const CardPile& cpile)
	: upperLeftX(cpile.upperLeftX), upperLeftY(cpile.upperLeftY), count(cpile.count)
{
	for (int i = 0; i < count; i++) {
		theCards[i] = std::make_shared<Card>(cpile.theCards[i]->getUpperLeftX(),
			cpile.theCards[i]->getUpperLeftY(),
			cpile.theCards[i]->getSuit(),
			cpile.theCards[i]->getRank());
		theCards[i]->setFaceUp(cpile.theCards[i]->getFaceUp());
	}
}

// 이동 생성자 함수
CardPile::CardPile(CardPile&& cpile)
	: upperLeftX(cpile.upperLeftX), upperLeftY(cpile.upperLeftY),
	count(cpile.count), theCards(std::move(cpile.theCards))
{}

// 소멸자 함수
CardPile::~CardPile()
{
	for (int i = 0; i < count; ++i)
		theCards[i].reset();			// theCards[i] = nullptr;
}

// 복사 배정 연산자
CardPile& CardPile::operator=(const CardPile& cpile)
{
	if (this == &cpile)
		return *this;
	upperLeftX = cpile.upperLeftX;
	upperLeftY = cpile.upperLeftY;
	for (int i = 0; i < count; i++)
		theCards[i] = nullptr;
	count = cpile.count;
	for (int i = 0; i < count; i++) {
		theCards[i] = std::make_shared<Card>(cpile.theCards[i]->getUpperLeftX(),
			cpile.theCards[i]->getUpperLeftY(),
			cpile.theCards[i]->getSuit(),
			cpile.theCards[i]->getRank());
		theCards[i]->setFaceUp(cpile.theCards[i]->getFaceUp());
	}
	return *this;
}

// 이동 배정 연산자
CardPile& CardPile::operator=(CardPile&& cpile)
{
	if (this == &cpile)
		return *this;
	upperLeftX = cpile.upperLeftX;
	upperLeftY = cpile.upperLeftY;
	for (int i = 0; i < count; i++)
		theCards[i] = nullptr;
	count = cpile.count;
	theCards = std::move(cpile.theCards);
	return *this;
}

void CardPile::moveTo(int x, int y)
{
	upperLeftX = x;
	upperLeftY = y;
	for (int i = 0; i < count; ++i) {
		theCards[i]->moveTo(x, y);
	}
}

void CardPile::addCard(const CardPtr& newCard)
{
	if (count < MAX_CARDS) {
		theCards[count] = newCard;
		newCard->moveTo(upperLeftX, upperLeftY);
		count = count + 1;
	}
}

CardPtr CardPile::topCard()
{
	if (count > 0) {
		count = count - 1;
		return theCards[count];
	}
	return nullptr;
}

bool CardPile::includes(int x, int y)
{
	for (int k = count; k > 0; k--) {
		if (theCards[k - 1]->includes(x, y)) {
			return true;
		}
	}
	return false;
}

void CardPile::select()
{}

bool CardPile::canTake(const CardPtr& c)		// 6장
{
	return false;
}

// 접근 함수
int CardPile::getUpperLeftX() const
{ return upperLeftX; }

int CardPile::getUpperLeftY() const
{ return upperLeftY; }

int CardPile::getCount() const
{ return count; }

// 변경 함수
void CardPile::setUpperLeftX(int k)
{ upperLeftX = k; }

void CardPile::setUpperLeftY(int k)
{ upperLeftY = k; }

DeckPile::DeckPile(int a, int b)
	: CardPile(a, b)
{}

void DeckPile::addCard(const CardPtr& newCard)
{
	if (count < MAX_CARDS) {
		CardPile::addCard(newCard);
		newCard->moveTo(upperLeftX, upperLeftY);
		auto it = theCards.begin();
		std::advance(it, count);
		std::shuffle(theCards.begin(), it, eng);
	}
}

// 6장
void DeckPile::select()
{
	if (count > 0) {
		CardPtr c = topCard();
		c->flip();
		allPilePtr[1]->addCard(c);		// 6장
	}
}

SuitPile::SuitPile(int x, int y)
	: CardPile(x, y)
{}

bool SuitPile::canTake(const CardPtr& c)
{
	if ((count == 0) && (c->getRank() == 1))
		return true;
	if (count > 0) {
		int s = theCards[count - 1]->getSuit();
		int r = theCards[count - 1]->getRank();
		if ((s == c->getSuit()) && ((c->getRank() - r) == 1))
			return true;
	}
	return false;
}

DiscardPile::DiscardPile(int x, int y)
	: CardPile(x, y)
{}

void DiscardPile::select()
{
	if (count > 0) {
		CardPtr c = topCard();
		int i;
		for (i = 2; i <= 12; i++) {
			if (allPilePtr[i]->canTake(c)) {	// 6장
				allPilePtr[i]->addCard(c);		// 6장
				break;
			}
		}
		if (i == 13)
			addCard(c);
	}
}

TablePile::TablePile(int x, int y)
	: CardPile(x, y)
{}

bool TablePile::canTake(const CardPtr& c)
{
	if ((count == 0) && (c->getRank() == 13))
		return true;
	if (count > 0) {
		if (theCards[count - 1]->getFaceUp()) {
			int s = theCards[count - 1]->getSuit();
			int r = theCards[count - 1]->getRank();
			if ((r - c->getRank()) == 1) {
				switch (c->getSuit()) {
				case 1:
				case 4: if (s == 2 || s == 3) return true;
						else return false;
				case 2:
				case 3: if (s == 1 || s == 4) return true;
						else return false;
				}
			}
		}
	}
	return false;
}
/* console version
void TablePile::display(Application& win)
{
	int ty = 0;
	if (count > 0) {
		for (int i = 0; i < count; i++) {
			theCards[i]->moveTo(upperLeftX, upperLeftY + ty);
			theCards[i]->draw(win);
			ty = ty + 35;
		}
	}
	else {
		win.setPen(green);
		win.rectangle(upperLeftX, upperLeftY,
			Card::CardWidth, Card::CardHeight);
	}
}
*/
void TablePile::select()
{
	if (count > 0) {
		if (!theCards[count - 1]->getFaceUp()) {
			theCards[count - 1]->flip();
		}
		else {
			for (int i = 2; i <= 12; i++) {
				if (allPilePtr[i]->canTake(theCards[count - 1])) {	// 6장
					allPilePtr[i]->addCard(topCard());				// 6장
					break;
				}
			}
		}
	}
}

// console version
std::ostream& operator<<(std::ostream& os, const CardPile& cp)
{
	for (int i = 0; i < cp.count; ++i)
		os << *(cp.theCards[i]) << endl;
	return os;
}