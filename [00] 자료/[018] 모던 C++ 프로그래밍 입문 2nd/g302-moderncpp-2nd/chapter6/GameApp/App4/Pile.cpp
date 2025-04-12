#include "Pile.h"
// GameApp의 allPilePtr을 사용하기 위해 포함
// 헤더 파일의 순환 include를 피하기 위해 Pile.cpp에 포함
#include "GameApp.h"	
#include <stack>
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

void CardPile::select()
{}

void CardPile::select(int x, int y)
{}

bool CardPile::canTake(const CardPtr& c)
{
	return false;
}

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

bool DeckPile::includes(int x, int y)
{
	if (count == 0) {
		if ((upperLeftX < x) && (x < (upperLeftX + Card::CardWidth))) {
			if ((upperLeftY < y) && (y < (upperLeftY + Card::CardHeight)))
				return true;
		}
		return false;
	}
	else {
		return(CardPile::includes(x, y));
	}
}

void DeckPile::select()
{
	if (count > 0) {
		CardPtr c = topCard();
		c->flip();
		GameApp::allPilePtr[1]->addCard(c);
	}
	else {
		int cardCount = GameApp::allPilePtr[1]->count;
		for (int i = 0; i < cardCount; ++i) {
			CardPtr c = GameApp::allPilePtr[1]->topCard();
			c->flip();
			addCard(c);
		}
	}
}

SuitPile::SuitPile(int x, int y)
	: CardPile(x, y)
{}

bool SuitPile::canTake(const CardPtr& c)
{
	if ((count == 0) && (c->rank == 1))
		return true;
	if (count > 0) {
		int s = theCards[count - 1]->suit;
		int r = theCards[count - 1]->rank;
		if ((s == c->suit) && ((c->rank - r) == 1))
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
			if (GameApp::allPilePtr[i]->canTake(c)) {
				GameApp::allPilePtr[i]->addCard(c);
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
	if ((count == 0) && (c->rank == 13))
		return true;
	if (count > 0) {
		if (theCards[count - 1]->faceUp) {
			int s = theCards[count - 1]->suit;
			int r = theCards[count - 1]->rank;
			if ((r - c->rank) == 1) {
				switch (c->suit) {
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

void TablePile::select()
{
	if (count > 0) {
		if (!theCards[count - 1]->faceUp) {
			theCards[count - 1]->flip();
		}
		else {
			for (int i = 2; i <= 12; i++) {
				if (GameApp::allPilePtr[i]->canTake(theCards[count - 1])) {
					GameApp::allPilePtr[i]->addCard(topCard());
					break;
				}
			}
		}
	}
}

void TablePile::select(int x, int y)
{
	for (int k = count; k > 0; k--) {
		if (theCards[k - 1]->includes(x, y) && theCards[k - 1]->faceUp) {
			for (int i = 6; i <= 12; i++) {
				if (GameApp::allPilePtr[i]->canTake(theCards[k - 1])) {
					std::stack<CardPtr> cardStack;		// 빈 스택 생성
					int cnt = count;
					for (int j = cnt; j > k - 1; j--)
						cardStack.push(topCard());
					for (int m = cnt; m > k - 1; m--) {
						CardPtr c = cardStack.top();
						cardStack.pop();
						GameApp::allPilePtr[i]->addCard(c);
					}
					break;
				}
			}
			break;
		}
	}
}