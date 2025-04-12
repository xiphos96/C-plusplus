#include "Pile.h"

int main()
{
	DeckPile theDeck{ 100, 100 };
	CardPile theDiscard{ 200, 100 };
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 13; j++)
			theDeck.addCard(std::make_shared<Card>(0, 0, i, j));
	cout << "after clicking inside theDeck -"
		<< " one card is moved to theDiscard" << endl;
	int x = 120, y = 120;
	if (theDeck.includes(x, y)) {
		CardPtr deckTop = theDeck.topCard();
		theDiscard.addCard(deckTop);
	}
	cout << theDeck << endl;
	cout << theDiscard << endl;
	cout << "after clicking inside theDiscard -"
		<< " top card is flipped" << endl;
	x = 220; y = 120;
	if (theDiscard.includes(x, y)) {
		CardPtr discardTop = theDiscard.topCard();
		discardTop->flip();
		theDiscard.addCard(discardTop);
	}
	cout << theDeck << endl;
	cout << theDiscard << endl;

	return 0;
}