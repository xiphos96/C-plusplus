#include <iostream>
using std::cout;
using std::endl;

// Base Class Figure
class Figure
{
public:
	Figure(int xv, int yv)
		: x(xv), y(yv)
	{};
protected:
	int x;
	int y;
};

// Base Class PaintCost
class PaintCost
{
public:
	int getCost(int area)
	{
		return area * 10;
	}
};

// Derived Class Rect
class Rect : public Figure, public PaintCost
{
public:
	Rect(int xv, int yv, int wid, int hgt)
		: Figure(xv, yv), width(wid), height(hgt)
	{}
	int area()
	{
		return width * height;
	}
private:
	int width;
	int height;
};

int main()
{
	Rect r(100, 100, 150, 160);
	// the area of the rectangle
	cout << "total area: " << r.area() << endl;
	// the total cost of painting
	cout << "total paint cost: " << r.getCost(r.area()) << endl;

	return 0;
}