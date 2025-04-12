#include "PileApp.h"

PileApp::PileApp(const TCHAR* apName)
	: Application(apName)
{}

PileApp::PileApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

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

// 응용 과제 3
void PileApp::mouseRDown(int x, int y)
{
	if (theDiscard.includes(x, y)) {
		if (theDiscard.wideDisplay) {
			theDiscard.wideDisplay = false;
			for (int i = 0; i < theDiscard.count; ++i)
				theDiscard.theCards[i]->moveTo(theDiscard.upperLeftX,
											theDiscard.upperLeftY);
		}
		else {
			theDiscard.wideDisplay = true;
		}
	}
	clearAndUpdate();
}

void PileApp::paint()
{
	theDeck.display(*this);
	if (theDiscard.wideDisplay)
		theDiscard.display(*this, Card::CardWidth);
	else
		theDiscard.display(*this);
}

int mainLAF()
{
	PileApp theApp(TEXT("PILES"));
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 13; j++)
			theApp.theDeck.addCard(std::make_shared<Card>(0, 0, i, j));
	theApp.run();

	return 0;
}