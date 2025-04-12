#include "ReferenceMemberApp.h"

CardApp::CardApp(const TCHAR* apName, Rect& rect,
				Card& card, std::shared_ptr<Rect>& ptr)
	: Application(apName), aRef(rect), bRef(card), cRef(ptr)
{}

void CardApp::mouseDown(int x, int y)
{
	if (bRef.includes(x, y))
		bRef.flip();
	if (cRef->includes(x, y)) {
		CardPtr k = std::static_pointer_cast<Card>(cRef);
		k->flip();
	}
	clearAndUpdate();
}

void CardApp::paint()
{
	aRef.draw(*this);
	bRef.draw(*this);
	cRef->draw(*this);
}

int mainLAF()
{
	Rect a{ 50, 100, 150, 200 };
	Card b{ 200, 100, 2, 7 };
	std::shared_ptr<Rect> c = std::make_shared<Card>(300, 100, 3, 5);
	CardApp theApp(TEXT("CARDS"), a, b, c);
	theApp.run();

	return 0;
}