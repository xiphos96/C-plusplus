#include "PenApp.h"

PenApp::PenApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void PenApp::mouseDown(int x, int y)
{
	newx = x;
	newy = y;
	// Exer
	outStream.open("point.txt", std::ios::app);
	outStream << "x:" << newx << " y:" << newy << std::endl;
	outStream.close();
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
	PenApp theApp(TEXT("PENS"), 500, 500, 150, 150);
	theApp.run();

	return 0;
}