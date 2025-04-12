#pragma once
#include "pclaf.h"
#include "Card.h"

class CardApp : public Application
{
public:
	// 생성자는 한 개만
	CardApp(const TCHAR*, Rect&, Card&, std::shared_ptr<Rect>&);
	void mouseDown(int, int);
	void paint();
	// data fields
	Rect& aRef;
	Card& bRef;
	std::shared_ptr<Rect>& cRef;
};