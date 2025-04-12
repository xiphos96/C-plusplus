#include "LineApp.h"
#include "Line.h"

bool firstClick = true;
int tempX, tempY;

LineApp::LineApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void LineApp::mouseDown(int x, int y)
{
	if (firstClick) {
		tempX = x;
		tempY = y;
		firstClick = false;
	}
	else {
		Line ln(tempX, tempY, x, y);	
		lineVector.push_back(ln);
		firstClick = true;
		clearAndUpdate();
	}
}

void LineApp::paint()
{
	for (Line ln : lineVector)
		ln.draw(*this);
}

int mainLAF()
{
	LineApp theApp(TEXT("LINES"), 750, 500, 150, 150);
	theApp.run();

	return 0;
}