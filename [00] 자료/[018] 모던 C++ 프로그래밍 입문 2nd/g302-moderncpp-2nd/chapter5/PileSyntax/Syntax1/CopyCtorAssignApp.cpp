#include "Pile.h"

int main()
{
	CardPile theDiscard{ 200, 100 };
	for (int k = 1; k <= 3; ++k) {
		CardPtr cptr = std::make_shared<Card>(0, 0, 1, k);
		cptr->flip();
		theDiscard.addCard(cptr);
	}
	// default copy ctor
	CardPile cp = theDiscard;			// CardPile cp(theDiscard);
	cout << theDiscard << '\n' << cp << endl;
	cp.moveTo(600, 500);
	cout << "after cp moves:" << endl;
	cout << theDiscard << '\n' << cp << endl;

	return 0;
}