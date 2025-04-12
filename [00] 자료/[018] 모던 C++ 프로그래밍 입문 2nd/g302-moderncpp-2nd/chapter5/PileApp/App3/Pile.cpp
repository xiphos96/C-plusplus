#include "Pile.h"
#include "pclaf.h"
#include <random>
#include <ctime>
#include <algorithm>

std::mt19937 eng(static_cast<unsigned long>(time(nullptr)));

CardPile::CardPile(int x, int y)
	: upperLeftX(x), upperLeftY(y), count(0)
{}

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

// 응용 과제 3
void CardPile::display(Application& win, int xoffset)
{
	int tx = 0;
	if (count > 0) {
		for (int i = count; i > 0; i--) {
			theCards[i - 1]->faceUp = true;
			theCards[i - 1]->moveTo(upperLeftX + tx, upperLeftY);
			theCards[i - 1]->draw(win);
			tx = tx + xoffset;
		}
	}
}

void CardPile::select()
{}

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