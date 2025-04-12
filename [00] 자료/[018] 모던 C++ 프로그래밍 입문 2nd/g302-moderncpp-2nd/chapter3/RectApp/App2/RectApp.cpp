#include "RectApp.h"

RectApp::RectApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void RectApp::mouseDown(int x, int y)
{
	// 응용 과제 2
	if (smartRectangle != nullptr) {
		if (smartRectangle->includes(x, y)) {
			smartRectangle->moveTo(x, y);
		}
	}
	else {
		smartRectangle = std::make_unique<Rect>(x, y, x + 70, y + 50);
//		smartRectangle = std::unique_ptr<Rect>(new Rect(x, y, x + 70, y + 50));
	}
	clearAndUpdate();
}

void RectApp::paint()
{
//	if (smartRectangle.get() != nullptr)
	if(smartRectangle)
		smartRectangle->draw(*this);
}

int mainLAF()
{
	RectApp theApp(TEXT("RECTANGLES"), 750, 500, 150, 150);
	theApp.run();

	return 0;
}