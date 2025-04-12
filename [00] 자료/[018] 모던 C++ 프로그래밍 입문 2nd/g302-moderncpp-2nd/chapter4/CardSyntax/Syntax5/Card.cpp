#include "Card.h"
//#include "pclaf.h"							// console version

Card::Card(int xv, int yv, int s, int r)
	: Rect(xv, yv, xv + CardWidth, yv + CardHeight),
	suit(s), rank(r), faceUp(false)
{}

Card::Card(int s, int r)
	: suit(s), rank(r), faceUp(false)
{}

Card::~Card()
{}
/* console version
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
*/
void Card::flip()
{
	if (faceUp)
		faceUp = false;
	else
		faceUp = true;
}

int Card::getSuit() const
{ return suit; }

int Card::getRank() const
{ return rank; }

bool Card::getFaceUp() const
{ return faceUp; }

void Card::setSuit(int k)
{ suit = k; }

void Card::setRank(int k)
{ rank = k; }

void Card::setFaceUp(bool k)
{ faceUp = k; }

// Á¤Àû ¸â¹ö ÇÔ¼ö
int Card::getCardWidth()
{ return CardWidth; }

int Card::getCardHeight()
{ return CardHeight; }

// ÇÁ·»µå ÇÔ¼ö
bool operator==(const Card& left, const Card& right)
{
	if (left.suit == right.suit)
		if (left.rank == right.rank)
			return true;
	return false;
}

// console version
std::ostream& operator<<(std::ostream& os, const Card& c)
{
	os << "À§Ä¡:(" << c.getUpperLeftX() << ", "
		<< c.getUpperLeftY() << ")";
	if (c.faceUp) {
		if (c.suit == 1) os << " heart ";
		else if (c.suit == 2) os << " club ";
		else if (c.suit == 3) os << " spade ";
		else if (c.suit == 4) os << " diamond ";
		if (c.rank == 1) os << "ace";
		else if (c.rank == 11) os << "jack";
		else if (c.rank == 12) os << "queen";
		else if (c.rank == 13) os << "king";
		else os << c.rank;
	}
	else {
		os << " µÞ¸é";
	}
	return os;
}