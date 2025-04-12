#include "HelloWinApp.h"

HelloWinApp::HelloWinApp(const TCHAR* apName,
						int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void HelloWinApp::mouseDown(int x, int y)
{
	clearAndUpdate();
}

void HelloWinApp::paint()
{
	wout << setpos(100, 100) << TEXT("hello world!");
}

int mainLAF()
{
	HelloWinApp theApp(TEXT("HELLO"), 600, 500, 0, 0);
	theApp.run();

	return 0;
}