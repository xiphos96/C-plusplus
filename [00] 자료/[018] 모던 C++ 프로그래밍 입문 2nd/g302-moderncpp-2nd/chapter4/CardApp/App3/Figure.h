#pragma once
#include "pclaf.h"		// 응용 과제 3
#include <memory>
//class Application;	// 응용 과제 3

// Figure Class
class Figure
{
public:
	Figure(int, int);
	void moveTo(int, int);
	virtual void draw(Application&) = 0;
	// 응용 과제 3
	virtual bool includes(int, int) const = 0;
	// data fields
	int x;
	int y;
	// 응용 과제 3
	Color col = black;
};

// Circle Class
class Circle : public Figure
{
public:
	Circle(int, int, int);
	virtual void draw(Application&);
	// 응용 과제 3
	virtual bool includes(int, int) const;
	// data field
	int radius;
};

// Rectangle Class
class Rect : public Figure
{
public:
	Rect(int, int, int, int);
	bool includes(int, int) const;
	virtual void draw(Application&);
	// data fields
	int width;
	int height;
};

using FigurePtr = std::shared_ptr<Figure>;