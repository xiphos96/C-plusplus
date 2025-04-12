#include "CircleApp.h"
#include "Circle.h"
#include <cmath>

bool firstClick = true;
int tempX, tempY;

CircleApp::CircleApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void CircleApp::mouseDown(int x, int y)
{
	if (firstClick) {
		tempX = x;
		tempY = y;
		firstClick = false;
	}
	else {
		long double distance = sqrt(pow(long double(x - tempX), 2.0)
			+ pow(long double(y - tempY), 2.0));
		int dist = static_cast<int>(distance);
		CirclePtr cPtr(new Circle(tempX, tempY, dist));
		circlePtrVector.push_back(cPtr);
		firstClick = true;
		clearAndUpdate();
	}
}

void CircleApp::paint()
{
	for (CirclePtr cPtr : circlePtrVector)
		cPtr->draw(*this);
}

int mainLAF()
{
	CircleApp theApp(TEXT("CIRCLES"), 750, 500, 150, 150);
	theApp.run();

	return 0;
}