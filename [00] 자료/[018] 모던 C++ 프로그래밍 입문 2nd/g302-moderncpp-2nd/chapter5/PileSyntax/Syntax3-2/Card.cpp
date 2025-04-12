#include "Card.h"

Card::Card(int xv, int yv, int s, int r)
	: Rect(xv, yv, xv + CardWidth, yv + CardHeight),
	suit(s), rank(r), faceUp(false)
{}

Card::Card(int s, int r)
	: suit(s), rank(r), faceUp(false)
{}

Card::~Card()
{}

void Card::flip()
{
	if (faceUp)
		faceUp = false;
	else
		faceUp = true;
}

int Card::getSuit() const
{
	return suit;
}

int Card::getRank() const
{
	return rank;
}

bool Card::getFaceUp() const
{
	return faceUp;
}

void Card::setSuit(int k)
{
	suit = k;
}

void Card::setRank(int k)
{
	rank = k;
}

void Card::setFaceUp(bool k)
{
	faceUp = k;
}

// ���� ��� �Լ�
int Card::getCardWidth()
{
	return CardWidth;
}

int Card::getCardHeight()
{
	return CardHeight;
}

// ������ �Լ�
bool operator==(const Card& left, const Card& right)
{
	if (left.suit == right.suit)
		if (left.rank == right.rank)
			return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const Card& c)
{
	os << "��ġ:(" << c.getUpperLeftX() << ", "
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
		os << " �޸�";
	}
	return os;
}