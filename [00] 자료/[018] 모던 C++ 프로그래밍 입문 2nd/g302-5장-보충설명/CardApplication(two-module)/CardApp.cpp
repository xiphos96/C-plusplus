#include "CardApp.h"

//==========
Rect::Rect(int a, int b, int c, int d)
	: upperLeftX(a), upperLeftY(b),
	lowerRightX(c), lowerRightY(d)
{}

void Rect::moveTo(int x, int y)
{
	int width = lowerRightX - upperLeftX;
	int height = lowerRightY - upperLeftY;
	upperLeftX = x;
	upperLeftY = y;
	lowerRightX = x + width;
	lowerRightY = y + height;
}

void Rect::draw(Application& theWindow)
{
	// first make sure the pen is correct
	theWindow.setPen(blue, solidLine, 1);
	//	then draw the rectangle
	int width = lowerRightX - upperLeftX;
	int height = lowerRightY - upperLeftY;
	theWindow.rectangle(upperLeftX, upperLeftY, width, height);
}

bool Rect::includes(int x, int y)
{
	if ((upperLeftX < x) && (lowerRightX > x))
		if ((upperLeftY < y) && (lowerRightY > y))
			return true;
	return false;
}

//==========
Card::Card(int xv, int yv, int s, int r)
	: Rect(xv, yv, xv + CardWidth, yv + CardHeight),
	suit(s), rank(r), faceUp(false)
{}

void Card::draw(Application& win)
{
	//draw the outer Rect
	Rect::draw(win);
	// then draw the inner contents
	if (faceUp) {
		// first print out the suit
		if (suit == 1 || suit == 4) win.setTextColor(brightRed);
		win.wout << setpos(upperLeftX + 5, upperLeftY + 5);
		if (suit == 1) win.wout << TEXT("heart");
		else if (suit == 2) win.wout << TEXT("club");
		else if (suit == 3) win.wout << TEXT("spade");
		else if (suit == 4) win.wout << TEXT("diamond");
		// then print out the rank
		win.wout << setpos(upperLeftX + 5, upperLeftY + 20);
		if (rank == 1) win.wout << TEXT("ace");
		else if (rank == 11) win.wout << TEXT("jack");
		else if (rank == 12) win.wout << TEXT("queen");
		else if (rank == 13) win.wout << TEXT("king");
		else win.wout << rank;
		if (suit == 1 || suit == 4)
			win.setTextColor(black);
	}
	else {
		// face down, draw back
		win.wout << setpos(upperLeftX + 30, upperLeftY + 38);
		win.wout << TEXT("Back");
		win.line(upperLeftX, upperLeftY,
			upperLeftX + CardWidth, upperLeftY + CardHeight);
		win.line(upperLeftX + CardWidth, upperLeftY,
			upperLeftX, upperLeftY + CardHeight);
	}
}

void Card::flip()
{
	if (faceUp)
		faceUp = false;
	else
		faceUp = true;
}

//==========
CardApp::CardApp(const TCHAR* apName)
	: Application(apName)
{}

CardApp::CardApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void CardApp::mouseDown(int x, int y)
{
	if (b.includes(x, y))
		b.flip();
	/*
	if (c->includes(x, y)) {
		CardPtr k = std::static_pointer_cast<Card>(c);
		k->flip();
	}
	*/
	clearAndUpdate();
}

void CardApp::paint()
{
	a.draw(*this);
	b.draw(*this);
	c->draw(*this);
	/*
	CardPtr k = std::static_pointer_cast<Card>(c);
	k->draw(*this);
	*/
}

//==========
// pclaf program entry point
int mainLAF()
{
	CardApp theApp(TEXT("CARDS"));
	theApp.run();

	return 0;
}