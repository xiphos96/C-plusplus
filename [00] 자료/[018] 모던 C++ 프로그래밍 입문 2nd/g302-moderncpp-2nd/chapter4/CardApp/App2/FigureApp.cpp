#include "FigureApp.h"
#include <random>
#include <ctime>

std::mt19937 eng(static_cast<unsigned long>(time(nullptr)));
std::uniform_int_distribution<int> distSuit(1, 4);
std::uniform_int_distribution<int> distRank(1, 13);

FigureApp::FigureApp(const TCHAR* apName)
	: Application(apName)
{}

FigureApp::FigureApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void FigureApp::mouseDown(int x, int y)
{
	figures.push_back(std::make_shared<Card>(x, y,
				distSuit(eng), distRank(eng)));
	clearAndUpdate();
}

void FigureApp::mouseRDown(int x, int y)
{
	figures.push_back(std::make_shared<Circle>(x, y, 40));
	clearAndUpdate();
}

void FigureApp::paint()
{
	for (auto f : figures)
		f->draw(*this);
}

int mainLAF()
{
	FigureApp theApp(TEXT("FIGURES"));
	theApp.run();

	return 0;
}