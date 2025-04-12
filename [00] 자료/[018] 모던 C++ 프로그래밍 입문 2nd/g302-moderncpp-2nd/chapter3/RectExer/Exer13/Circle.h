// Circle Class
#pragma once
class Application;

class Circle
{
public:
	// constructor
	Circle(int, int, int);
	// operations
	void moveTo(int, int);
	bool includes(int, int);
	void draw(Application&);
	// data fields
	int centerX; int centerY;
	int radius;
};