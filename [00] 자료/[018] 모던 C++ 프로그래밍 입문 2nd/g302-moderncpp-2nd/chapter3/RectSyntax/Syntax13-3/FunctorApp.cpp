#include "Rect.h"
#include <iostream>
using namespace std;

class AreaAccumulator
{
public:
	AreaAccumulator()
		: totalArea(0), count(0)
	{}

	int operator()(const Rect& r)
	{
		++count;
		return totalArea += r.area();
	}
	// data fields
	int totalArea;
	int count;
};

int main()
{
	AreaAccumulator aa;
	Rect aRectangle(30, 40, 70, 80);
	Rect bRectangle(100, 90, 130, 150);
	Rect cRectangle(50, 60, 100, 110);
	cout << "area of " << aa.count << " rects is "
			<< aa(aRectangle) << endl;
	cout << "area of " << aa.count << " rects is "
			<< aa(bRectangle) << endl;
	cout << "area of " << aa.count << " rects is "
			<< aa(aRectangle) << endl;

	return 0;
}