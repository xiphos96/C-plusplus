#include "Pile.h"
//#include "pclaf.h"						// console version
#include <random>
#include <ctime>
#include <algorithm>

std::mt19937 eng(static_cast<unsigned long>(time(nullptr)));

CardPile::CardPile(int x, int y)
	: upperLeftX(x), upperLeftY(y), count(0)
{}

// ���� ������ �Լ�
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

// �̵� ������ �Լ�
CardPile::CardPile(CardPile&& cpile)
	: upperLeftX(cpile.upperLeftX), upperLeftY(cpile.upperLeftY),
	count(cpile.count), theCards(std::move(cpile.theCards))
{}

// �Ҹ��� �Լ�
CardPile::~CardPile()
{
	for (int i = 0; i < count; ++i)
		theCards[i].reset();				// theCards[i] = nullptr;
}

// ���� ���� ������
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

// �̵� ���� ������
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
/* console version
void CardPile::display(Application& win)
{
	if (count > 0) {
		theCards[count - 1]->draw(win);
	}
	else {
		win.setPen(green);
		win.rectangle(upperLeftX, upperLeftY,
			Card::CardWidth, Card::CardHeight);
	}
}
*/
void CardPile::select()
{}

// ���� �Լ�
int CardPile::getUpperLeftX() const
{ return upperLeftX; }

int CardPile::getUpperLeftY() const
{ return upperLeftY; }

int CardPile::getCount() const
{ return count; }

// ���� �Լ�
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

// console version
std::ostream& operator<<(std::ostream& os, const CardPile& cp)
{
	for (int i = 0; i < cp.count; ++i)
		os << *(cp.theCards[i]) << endl;
	return os;
}