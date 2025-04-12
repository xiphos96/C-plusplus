#include "Rect.h"
#include <vector>
#include <iostream>
using std::vector;
using std::cout; using std::endl;

int main()
{
	Rect aRect(30, 40, 70, 70);
	Rect bRect{ 100, 90, 130, 150 };
	vector<Rect> rectVector{
		{ 20, 30, 50, 50 },{ 100, 100, 150, 150 }
	};
	for (const Rect& r : rectVector)
		cout << "the area: " << r.area() << endl;

	return 0;
}