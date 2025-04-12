// Line Class
#pragma once
class Application;

class Line
{
public:
	// constructor
	Line(int, int, int, int);
	// operations
	void moveTo(int, int);
	void draw(Application&);
	// data fields
	int startX; int startY;
	int endX; int endY;
};