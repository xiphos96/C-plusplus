#include "Rect.h"
#include <initializer_list>
#include <vector>
#include <iostream>
using std::vector; using std::initializer_list;
using std::cout; using std::endl;

int totalArea(std::initializer_list<Rect> lst)
{
	int total = 0;
	for (auto it = lst.begin(); it != lst.end(); ++it)
		total = total + (*it).area();
	return total;
}

int main()
{
	cout << "total area: " <<
		totalArea({ Rect(30, 40, 70, 70), Rect(100, 90, 130, 150) }) << endl;
	cout << "total area: " <<
		totalArea({ Rect(30, 40, 70, 70), Rect(100, 90, 130, 150),
			Rect(20, 30, 50, 50), Rect(100, 100, 150, 150) }) << endl;

	return 0;
}