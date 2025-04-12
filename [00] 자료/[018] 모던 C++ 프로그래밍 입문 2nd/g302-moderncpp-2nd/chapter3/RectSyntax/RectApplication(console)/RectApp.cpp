#include "Rect.h"

int main()
{
	Rect* theRectPtr = nullptr;
	int x = 30, y = 40;
	theRectPtr = new Rect(x, y, x + 70, y + 50);
	cout << *theRectPtr << endl;
	x = 40; y = 50;
	if (theRectPtr->includes(x, y))
		theRectPtr->moveTo(x, y);
	cout << *theRectPtr << endl;

	delete theRectPtr;
	theRectPtr = nullptr;
	return 0;
}