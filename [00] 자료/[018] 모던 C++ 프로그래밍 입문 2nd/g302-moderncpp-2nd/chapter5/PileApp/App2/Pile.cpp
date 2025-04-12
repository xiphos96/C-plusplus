#include "Pile.h"
#include "pclaf.h"
#include <random>
#include <ctime>

std::mt19937 eng(static_cast<unsigned long>(time(nullptr)));

CardPile::CardPile(int x, int y)
	: upperLeftX(x), upperLeftY(y), count(0)
{}

void CardPile::addCard(const CardPtr& newCard)
{
	if (count < MAX_CARDS) {
		theCards.push_front(newCard);
		newCard->moveTo(upperLeftX, upperLeftY);
		count = count + 1;
	}
}

CardPtr CardPile::topCard()
{
	if (count > 0) {
		count = count - 1;
		CardPtr cptr = theCards.front();
		theCards.pop_front();
		return cptr;
	}
	return nullptr;
}

bool CardPile::includes(int x, int y)
{
	for (std::list<CardPtr>::reverse_iterator it = theCards.rbegin();
		it != theCards.rend(); ++it) {
		if ((*it)->includes(x, y)) {
			return true;
		}
	}
	return false;
}

void CardPile::display(Application& win)
{
	if (count > 0) {
		theCards.front()->draw(win);
	}
	else {
		win.setPen(green);
		win.rectangle(upperLeftX, upperLeftY,
			Card::CardWidth, Card::CardHeight);
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
		std::uniform_int_distribution<int> dist(0, count);
		int n = dist(eng);
		if (n == 0)  // add to front
			CardPile::addCard(newCard);
		else {		// add in list, move the card
			std::list<CardPtr>::iterator it = theCards.begin();
			for (int i = 0; i < n; ++i)
				++it;
			theCards.insert(it, newCard);
			newCard->moveTo(upperLeftX, upperLeftY);
			count = count + 1;
		}
	}
}