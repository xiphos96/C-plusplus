#include "PenApp.h"

PenApp::PenApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void PenApp::mouseDown(int x, int y)
{
	// set location to move to
	newx = x;
	newy = y;
	// then update the screen
	clearAndUpdate();
}

void PenApp::paint()
{
	// draw a line
	line(oldx, oldy, newx, newy);
	// update old locations
	oldx = newx;
	oldy = newy;
}

// pclaf program entry point
int mainLAF()
{
	PenApp theApp(TEXT("PENS"), 500, 500, 150, 150);
	theApp.run();

	return 0;
}