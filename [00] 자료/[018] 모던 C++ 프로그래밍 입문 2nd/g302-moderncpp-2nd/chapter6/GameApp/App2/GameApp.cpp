#include "GameApp.h"

// 다른 파일(Pile.cpp)에서 접근할 수 있도록 static 멤버의 정의(빈 벡터 생성)
std::vector<CardPilePtr> GameApp::allPilePtr;
// 다른 파일(Card.cpp)에서 접근할 수 있도록 static 멤버의 정의(빈 배열 생성)
std::array<Bitmap, 53> GameApp::cardBitmaps;

void GameApp::init() {
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
	// 카드 비트맵 로딩
	for (int i = 0; i < 53; ++i)
		cardBitmaps[i] = loadBitmap(i + 1);
}

GameApp::GameApp(const TCHAR* apName)
	: Application(apName)
{
	init();
}

GameApp::GameApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{
	init();
}

void GameApp::mouseDown(int x, int y)
{
	for (auto it = allPilePtr.begin(); it != allPilePtr.end(); ++it) {
		if ((*it)->includes(x, y)) {
			(*it)->select();
			break;
		}
	}
	clearAndUpdate();
}

void GameApp::paint()
{
	for (auto it = allPilePtr.begin(); it != allPilePtr.end(); ++it)
		(*it)->display(*this);
}

int mainLAF()
{
	GameApp theApp(TEXT("Game"), 700, 700, 150, 30);
	// 카드 생성 후 데크 파일에 삽입
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 13; j++)
			GameApp::allPilePtr[0]->addCard(std::make_shared<Card>(0, 0, i, j));
	// 테이블 파일의 초기화
	for (int m = 1; m <= 7; m++)
		for (int n = 1; n <= m; n++)
			GameApp::allPilePtr[m + 5]->addCard(GameApp::allPilePtr[0]->topCard());
	// 테이블 파일의 제일 위 카드를 앞면인 상태로
	for (int p = 6; p <= 12; p++)
		GameApp::allPilePtr[p]->select();
	theApp.run();

	return 0;
}