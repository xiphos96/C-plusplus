// Card Class
#pragma once
#include "Figure.h"

class Card : public Rect
{
public:
	Card(int, int, int, int);
	virtual void draw(Application&);
	void flip();
	static const int CardWidth = 75;
	static const int CardHeight = 100;
	// data fields
	int suit;
	int rank;
	bool faceUp;
};

using CardPtr = std::shared_ptr<Card>;