#include "CardApp.h"

CardApp::CardApp(const TCHAR* apName)
	: Application(apName)
{}

CardApp::CardApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void CardApp::mouseDown(int x, int y)
{
	if (b.PtInRect(CPoint(x, y)))	// Exer: PtInRect instead of includes
		b.flip();
	if (c->PtInRect(CPoint(x, y)))
		c->flip();
	clearAndUpdate();
}

void CardApp::paint()
{
	b.draw(*this);
	c->draw(*this);
}

int mainLAF()
{
	CardApp theApp(TEXT("CARDS"));
	theApp.run();

	return 0;
}