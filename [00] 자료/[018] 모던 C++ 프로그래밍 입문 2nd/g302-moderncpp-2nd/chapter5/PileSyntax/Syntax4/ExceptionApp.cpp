#include "Pile.h"

int main()
{
	DeckPile theDeck{ 100, 100 };
	CardPile theDiscard{ 200, 100 };
	// 카드 생성 후 데크 파일에 삽입
	try {												// try 블록
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 13; j++) {
				CardPtr cptr = std::make_shared<Card>(0, 0, i, j);
				theDeck.addCard(cptr);
			}
		}
	}
	catch (const std::out_of_range& e) {				// catch 블록
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