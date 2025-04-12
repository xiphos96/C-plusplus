#include "Figure.h"
//#include "pclaf.h"			// 응용 과제 3

Figure::Figure(int xv, int yv)
	: x(xv), y(yv)
{}

void Figure::moveTo(int xv, int yv)
{
	x = xv;
	y = yv;
}

Circle::Circle(int xv, int yv, int r)
	: Figure(xv, yv), radius(r)
{}

void Circle::draw(Application& theWindow)
{
//	theWindow.setPen(blue, solidLine, 1);	// 응용 과제 3
	theWindow.circle(x, y, radius);
}

// 응용 과제 3
bool Circle::includes(int a, int b) const
{
	int distance;
	distance = (int)sqrt(pow((long double)(a - x), 2) + pow((long double)(b - y), 2));
	if (distance < radius)
		return true;
	else
		return false;
}

Rect::Rect(int xv, int yv, int wid, int hgt)
	: Figure(xv, yv), width(wid), height(hgt)
{}

void Rect::draw(Application& theWindow)
{
//	theWindow.setPen(blue, solidLine, 1);	// 응용 과제 3
	theWindow.rectangle(x, y, width, height);
}

bool Rect::includes(int xv, int yv) const
{
	if ((x < xv) && (x + width > xv))
		if ((y < yv) && (y + height > yv))
			return true;
	return false;
}