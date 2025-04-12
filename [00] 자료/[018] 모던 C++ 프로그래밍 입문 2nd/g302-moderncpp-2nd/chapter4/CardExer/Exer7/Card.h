// Card Class
#pragma once
#include "pclaf.h"		// Exer: pclaf.h 이곳으로 이동
#include <atltypes.h>	// Exer: CRect
#include <memory>

class Card : public CRect
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

typedef std::shared_ptr<Card> CardPtr;