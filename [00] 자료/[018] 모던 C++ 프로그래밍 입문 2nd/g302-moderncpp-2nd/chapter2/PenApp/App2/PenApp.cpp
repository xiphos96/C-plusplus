#include "PenApp.h"

PenApp::PenApp(const TCHAR* apName,
			   int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void PenApp::mouseDown(int x, int y)
{
	newx = x;
	newy = y;
	// 응용 과제 2
	setPen(blue);
	clearAndUpdate();
}

// 응용 과제 2
void PenApp::mouseRDown(int x, int y)
{
	// set location to move to
	newx = x;
	newy = y;
	setPen(brightRed);
	// then update the screen
	clearAndUpdate();
}

void PenApp::paint()
{
	line(oldx, oldy, newx, newy);
	// 응용 과제 2
	wout << setpos(newx, newy) << TEXT("hello");
	oldx = newx;
	oldy = newy;
}

int mainLAF()
{
	PenApp theApp(TEXT("PENS"), 600, 500, 150, 150);
	theApp.run();

	return 0;
}