#include "PileApp.h"

PileApp::PileApp(const TCHAR* apName)
	: Application(apName)
{}

PileApp::PileApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

// Exer
void PileApp::doubleClick(int x, int y)
{
	int sum = theDeck.sumRank();
	wout << setpos(100, 220) << sum;
	sum = theDiscard.sumRank();
	wout << setpos(200, 220) << sum;
}

void PileApp::mouseDown(int x, int y)
{
	if (theDeck.includes(x, y)) {
		CardPtr deckTop = theDeck.topCard();
		theDiscard.addCard(deckTop);
	}
	if (theDiscard.includes(x, y)) {
		CardPtr discardTop = theDiscard.topCard();
		discardTop->flip();
		theDiscard.addCard(discardTop);
	}
	clearAndUpdate();
}

void PileApp::paint()
{
	theDeck.display(*this);
	theDiscard.display(*this);
}

// pclaf program entry point
int mainLAF()
{
	PileApp theApp(TEXT("PILES"));
	// ī�� ���� �� ��ũ ���Ͽ� ����
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 13; j++)
			theApp.theDeck.addCard(std::make_shared<Card>(0, 0, i, j));
	theApp.run();

	return 0;
}