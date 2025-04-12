#include "Pile.h"

int main()
{
	DeckPile theDeck{ 100, 100 };
	CardPile theDiscard{ 200, 100 };
	// ī�� ���� �� ��ũ ���Ͽ� ����
	try {												// try ���
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 13; j++) {
				CardPtr cptr = std::make_shared<Card>(0, 0, i, j);
				theDeck.addCard(cptr);
			}
		}
	}
	catch (const std::out_of_range& e) {				// catch ���
		cout << e.what() << endl;
	}
	catch (const std::bad_alloc& e) {
		cout << e.what() << endl;
	}
	catch (const std::exception& e) {	
		cout << e.what() << endl;
	}
	cout << theDeck << endl;

	return 0;
}