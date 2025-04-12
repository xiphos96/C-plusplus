#include "PenApp.h"

PenApp::PenApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void PenApp::mouseDown(int x, int y)
{
	newx = x;
	newy = y;
	clearAndUpdate();
}

void PenApp::paint()
{
	line(oldx, oldy, newx, newy);
	oldx = newx;
	oldy = newy;
}

int mainLAF()
{
	// 응용 과제 3
	PenApp thisApp(TEXT("이 윈도우"), 500, 500, 100, 100);
	PenApp thatApp(TEXT("저 윈도우"), 500, 500, 600, 100);
	thisApp.run();
	thatApp.run();

	return 0;
}