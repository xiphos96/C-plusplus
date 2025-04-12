#include "Card.h"

int main()
{
	Card b{ 200, 100, 2, 7 };
	cout << Card::getCardWidth() << endl;
	cout << b.getCardHeight() << endl;

	return 0;
}