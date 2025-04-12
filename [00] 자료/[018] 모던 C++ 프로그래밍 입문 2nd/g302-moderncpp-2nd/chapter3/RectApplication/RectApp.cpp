#include "RectApp.h"
#include "Rect.h"

RectApp::RectApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void RectApp::mouseDown(int x, int y)
{
	if (theRectPtr != nullptr) {
		if (theRectPtr->includes(x, y)) {
			// move the rectangle
			theRectPtr->moveTo(x, y);
		}
	}
	else {
		theRectPtr = new Rect(x, y, x + 70, y + 50);
	}
	// then update the screen
	clearAndUpdate();
}

void RectApp::paint()
{
	if (this->theRectPtr != nullptr)
		theRectPtr->draw(*this);
}

// pclaf program entry point
int mainLAF()
{
	RectApp theApp(TEXT("RECTANGLES"), 750, 500, 150, 150);
	theApp.run();

	delete theApp.theRectPtr;
	theApp.theRectPtr = nullptr;
	return 0;
}