//================================================================
// 실습 과제
// 한 개의 사각형과 두 개의 카드를 생성해서 그림
// 첫 번째 카드를 클릭하면 카드가 뒤집기를 반복
//================================================================
#pragma once
#include "pclaf.h"
#include <memory>

//==========
class Rect
{
public:
	// constructor
	Rect(int, int, int, int);
	// operations
	void moveTo(int, int);
	bool includes(int, int);
	virtual void draw(Application&);
	// data fields
	int upperLeftX;
	int upperLeftY;
	int lowerRightX;
	int lowerRightY;
};

//==========
class Card : public Rect
{
public:
	// constructor
	Card(int, int, int, int);
	// operations
	virtual void draw(Application&);
	void flip();
	// static data fields
	static const int CardWidth = 75;
	static const int CardHeight = 100;
	// data fields
	int suit;
	int rank;
	bool faceUp;
};

typedef std::shared_ptr<Card> CardPtr;

//==========
// Customized Application
class CardApp : public Application
{
public:
	CardApp(const TCHAR*);
	CardApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// data fields
	Rect a{ 50, 100, 150, 200 };
	Card b{ 200, 100, 2, 7 };
	std::shared_ptr<Rect> c = std::make_shared<Card>(300, 100, 3, 5);
//	std::unique_ptr<Rect> c = std::make_unique<Card>(300, 100, 3, 5);
};