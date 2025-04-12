#include "Circle.h"
#include "pclaf.h"
#include <cmath>

Circle::Circle(int x, int y, int r)
	: centerX(x), centerY(y), radius(r)
{}

void Circle::moveTo(int x, int y)
{
	centerX = x;
	centerY = y;
}

void Circle::draw(Application& theWindow)
{
	theWindow.circle(centerX, centerY, radius);
}

bool Circle::includes(int x, int y)
{
	long double distance = sqrt(pow(long double(x - centerX), 2.0)
		+ pow(long double(y - centerY), 2.0));
	int dist = static_cast<int>(distance);
	if (dist < radius)
		return true;
	else
		return false;
}