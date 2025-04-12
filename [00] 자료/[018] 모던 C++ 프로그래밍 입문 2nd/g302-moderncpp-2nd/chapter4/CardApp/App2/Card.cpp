#include "Card.h"
#include "pclaf.h"

Card::Card(int xv, int yv, int s, int r)
	: Rect(xv, yv, CardWidth, CardHeight),
	suit(s), rank(r), faceUp(true)
{}

void Card::draw(Application& win)
{
	Rect::draw(win);
	if (faceUp) {
		// first print out the suit
		if (suit == 1 || suit == 4)
			win.setTextColor(brightRed);
		win.wout << setpos(x + 5, y + 5);					// 응용 과제 2
		if (suit == 1) win.wout << TEXT("heart");
		else if (suit == 2) win.wout << TEXT("club");
		else if (suit == 3) win.wout << TEXT("spade");
		else if (suit == 4) win.wout << TEXT("diamond");
		// then print out the rank
		win.wout << setpos(x + 5, y + 20);					// 응용 과제 2
		if (rank == 1) win.wout << TEXT("ace");
		else if (rank == 11) win.wout << TEXT("jack");
		else if (rank == 12) win.wout << TEXT("queen");
		else if (rank == 13) win.wout << TEXT("king");
		else win.wout << rank;
		if (suit == 1 || suit == 4)
			win.setTextColor(black);
	}
	else {
		win.wout << setpos(x + 30, y + 38);					// 응용 과제 2
		win.wout << TEXT("Back");
		win.line(x, y, x + CardWidth, y + CardHeight);		// 응용 과제 2
		win.line(x + CardWidth, y, x, y + CardHeight);		// 응용 과제 2
	}
}

void Card::flip()
{
	if (faceUp)
		faceUp = false;
	else
		faceUp = true;
}