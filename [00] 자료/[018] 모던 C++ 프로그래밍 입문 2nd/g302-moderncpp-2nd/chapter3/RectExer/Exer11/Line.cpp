#include "Line.h"
#include "pclaf.h"

Line::Line(int x1, int y1, int x2, int y2)
	: startX(x1), startY(y1), endX(x2), endY(y2)
{}

void Line::moveTo(int x, int y)
{
	int deltaX = endX - startX;
	int deltaY = endY - startY;
	startX = x;
	startY = y;
	endX = x + deltaX;
	endY = y + deltaY;
}

void Line::draw(Application& theWindow)
{
	theWindow.line(startX, startY, endX, endY);
}