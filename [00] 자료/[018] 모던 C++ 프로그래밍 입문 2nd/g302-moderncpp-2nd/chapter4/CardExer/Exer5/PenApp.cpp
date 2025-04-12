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
// Exer
MyChild::MyChild(const TCHAR* cName, int width, int height, int x, int y)
	: ChildWindow(cName, width, height, x, y)
{};

void MyChild::mouseDown(int x, int y)
{
	childX = x;
	childY = y;
	clearAndUpdate();
}

void MyChild::paint()
{
	circle(childX, childY, 30);
}

int mainLAF()
{
	PenApp theApp(TEXT("PENS"), 500, 500, 150, 150);
	// Exer
	MyChild theChild(TEXT("CHILD"), 200, 200, 700, 500);
	theApp.run();

	return 0;
}