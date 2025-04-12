#include "Rect.h"

int main()
{
	// default assignment operator
	Rect thisRectangle(30, 30, 100, 80);
	Rect thatRectangle(80, 90, 130, 150);
	cout << "default assignment operator" << endl;
	cout << thisRectangle << endl;
	thisRectangle = thatRectangle;
	cout << thisRectangle << endl;
	// default copy constructor
	Rect myRectangle(thatRectangle);
	cout << "default copy constructor" << endl;
	cout << thatRectangle << endl;
	cout << myRectangle << endl;

	return 0;
}