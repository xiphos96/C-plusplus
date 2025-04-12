#include "PenApp.h"

// Exer: global variable
auto firstClick = true;

PenApp::PenApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}
// Exer
void PenApp::mouseDown(int x, int y)
{
	if (firstClick) {
		startPoint.x = x;
		startPoint.y = y;
		firstClick = false;
	}
	else {
		endPoint.x = x;
		endPoint.y = y;
		firstClick = true;
		clearAndUpdate();
	}
}

void PenApp::paint()
{
	line(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
}

int mainLAF()
{
	PenApp theApp(TEXT("PENS"), 500, 500, 150, 150);
	theApp.run();

	return 0;
}