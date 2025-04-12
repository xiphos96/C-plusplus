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
	if (numFigures < MAX_FIGURES) {		// 응용 과제 3
		figures[numFigures] = std::make_shared<Card>(x, y,
								distSuit(eng), distRank(eng));
		++numFigures;
		clearAndUpdate();
	}
}

void FigureApp::mouseRDown(int x, int y)
{
	if (numFigures < MAX_FIGURES) {		// 응용 과제 3
		figures[numFigures] = std::make_shared<Circle>(x, y, 40);
		++numFigures;
		clearAndUpdate();
	}
}
// 응용 과제 3
void FigureApp::doubleClick(int x, int y)
{
	if (numFigures == MAX_FIGURES) {
		for (int i = MAX_FIGURES-1; i >= 0; --i) {
			if (figures[i]->includes(x, y)) {
				figures[i]->col = green;
				break;
			}
		}
	}
	clearAndUpdate();
}

void FigureApp::paint()
{
	for (int i = 0; i < numFigures; ++i) {
		if (figures[i]->col == green) {
			setPen(green, solidLine, 3);
			figures[i]->draw(*this);
			setPen(black);
		}
		else {
			figures[i]->draw(*this);
		}
	}
}

int mainLAF()
{
	FigureApp theApp(TEXT("FIGURES"));
	theApp.run();

	return 0;
}