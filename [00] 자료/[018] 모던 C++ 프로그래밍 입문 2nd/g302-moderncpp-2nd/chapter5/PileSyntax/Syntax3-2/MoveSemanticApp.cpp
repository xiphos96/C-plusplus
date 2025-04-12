#include "Pile.h"

CardPile copyPile(CardPile pile)
{
	CardPile tempPile(std::move(pile));
	return tempPile;
}

int main()
{
	CardPile theDiscard{ 200, 100 };
	for (int k = 1; k <= 3; ++k) {
		CardPtr cptr = std::make_shared<Card>(0, 0, 1, k);
		cptr->flip();
		theDiscard.addCard(cptr);
	}
	CardPile cp{ 200, 350 };
	cp = copyPile(theDiscard);
	cout << theDiscard << '\n' << cp << endl;

	return 0;
}