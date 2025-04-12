#include "Card.h"

Card::Card(int xv, int yv, int s, int r)
	: CRect(xv, yv, xv + CardWidth, yv + CardHeight),
	suit(s), rank(r), faceUp(false)
{}

void Card::draw(Application& win)
{
	// Exer: draw the outer Rect
	int width = right - left;
	int height = bottom - top;
	win.rectangle(left, top, width, height);
	// Exer: change to left, top, right, bottom
	if (faceUp) {
		// first print out the suit
		if (suit == 1 || suit == 4) win.setTextColor(brightRed);
		win.wout << setpos(left + 5, top + 5);
		if (suit == 1) win.wout << TEXT("heart");
		else if (suit == 2) win.wout << TEXT("club");
		else if (suit == 3) win.wout << TEXT("spade");
		else if (suit == 4) win.wout << TEXT("diamond");
		// then print out the rank
		win.wout << setpos(left + 5, top + 20);
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
		win.wout << setpos(left + 30, top + 38);
		win.wout << TEXT("Back");
		win.line(left, top,
			left + CardWidth, top + CardHeight);
		win.line(left + CardWidth, top,
			left, top + CardHeight);
	}
}

void Card::flip()
{
	if (faceUp)
		faceUp = false;
	else
		faceUp = true;
}