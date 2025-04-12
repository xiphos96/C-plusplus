#include "Pile.h"
#include <vector>

std::vector<CardPilePtr> allPilePtr;		// 6장 - global var

void init() {
	// 파일 객체 포인터들을 allPilePtr 벡터에 저장
	allPilePtr.push_back(std::make_shared<DeckPile>(50, 50));
	allPilePtr.push_back(std::make_shared<DiscardPile>(140, 50));
	allPilePtr.push_back(std::make_shared<SuitPile>(290, 50));
	allPilePtr.push_back(std::make_shared<SuitPile>(370, 50));
	allPilePtr.push_back(std::make_shared<SuitPile>(450, 50));
	allPilePtr.push_back(std::make_shared<SuitPile>(530, 50));
	allPilePtr.push_back(std::make_shared<TablePile>(50, 180));
	allPilePtr.push_back(std::make_shared<TablePile>(130, 180));
	allPilePtr.push_back(std::make_shared<TablePile>(210, 180));
	allPilePtr.push_back(std::make_shared<TablePile>(290, 180));
	allPilePtr.push_back(std::make_shared<TablePile>(370, 180));
	allPilePtr.push_back(std::make_shared<TablePile>(450, 180));
	allPilePtr.push_back(std::make_shared<TablePile>(530, 180));
}

int main()
{
	init();
	// 카드 생성 후 데크 파일에 삽입
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 13; j++)
			allPilePtr[0]->addCard(std::make_shared<Card>(0, 0, i, j));
	// 테이블 파일의 초기화
	for (int m = 1; m <= 7; m++)
		for (int n = 1; n <= m; n++)
			allPilePtr[m + 5]->addCard(allPilePtr[0]->topCard());
	// 테이블 파일의 제일 위 카드를 앞면인 상태로
	for (int p = 6; p <= 12; p++)
		allPilePtr[p]->select();
	// display table piles
	for (int i = 6; i < 13; ++i)
		cout << *(allPilePtr[i]) << endl;
	// select each table pile
	for (int p = 6; p <= 12; p++)
		allPilePtr[p]->select();
	// display table piles again
	cout << "after selecting each table pile-----" << endl;
	for (int i = 6; i < 13; ++i)
		cout << *(allPilePtr[i]) << endl;

	return 0;
}