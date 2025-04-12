#include "Rect.h"
//#include "pclaf.h"						// console version

Rect::Rect(int a, int b, int c, int d)
	: upperLeftX(a), upperLeftY(b),
	lowerRightX(c), lowerRightY(d)
{}

Rect::Rect()
	: upperLeftX(100), upperLeftY(100),
	lowerRightX(200), lowerRightY(200)
{}

Rect::Rect(int x)
	: upperLeftX(100), upperLeftY(100)
{
	int length = static_cast<int>(sqrt(static_cast<double>(x)));
	lowerRightX = upperLeftX + length;
	lowerRightY = upperLeftY + length;
}

Rect::~Rect()
{}

Rect::operator int()
{
	return area();
}

void Rect::moveTo(int x, int y)
{
	int width = lowerRightX - upperLeftX;
	int height = lowerRightY - upperLeftY;
	upperLeftX = x;
	upperLeftY = y;
	lowerRightX = x + width;
	lowerRightY = y + height;
}
/* console version
void Rect::draw(Application& theWindow)
{
	// first make sure the pen is correct
	theWindow.setPen(blue, solidLine, 1);
	// then draw the rectangle
	int width = lowerRightX - upperLeftX;
	int height = lowerRightY - upperLeftY;
	theWindow.rectangle(upperLeftX, upperLeftY, width, height);
}
*/
bool Rect::includes(const int x, const int y)
{
	if ((upperLeftX < x) && (lowerRightX > x))
		if ((upperLeftY < y) && (lowerRightY > y))
			return true;
	return false;
}

int Rect::area() const
{
	return((lowerRightX - upperLeftX) * (lowerRightY - upperLeftY));
}

bool Rect::operator>(const Rect& right)
{
	if (area() > right.area())
		return true;
	else
		return false;
}

Rect& Rect::operator++()
{
	++lowerRightX;
	++lowerRightY;
	return *this;
}

Rect Rect::operator++(int k)
{
	Rect temp(upperLeftX, upperLeftY, lowerRightX, lowerRightY);
	++(*this);
	return temp;
}

int Rect::getUpperLeftX() const
{
	return upperLeftX;
}

int Rect::getUpperLeftY() const
{
	return upperLeftY;
}

int Rect::getLowerRightX() const
{
	return lowerRightX;
}

int Rect::getLowerRightY() const
{
	return lowerRightY;
}

void Rect::setUpperLeftX(int k)
{
	upperLeftX = k;
}

void Rect::setUpperLeftY(int k)
{
	upperLeftY = k;
}

void Rect::setLowerRightX(int k)
{
	lowerRightX = k;
}

void Rect::setLowerRightY(int k)
{
	lowerRightY = k;
}

// 전역 함수
bool operator<(const Rect& left, const Rect& right)
{
	if (left.area() < right.area())
		return true;
	else
		return false;
}

Rect& operator--(Rect& r)
{
	int lrx = r.getLowerRightX();
	int lry = r.getLowerRightY();
	r.setLowerRightX(--lrx);
	r.setLowerRightY(--lry);
	return r;
}

Rect operator--(Rect& r, int k)
{
	Rect temp(r);		// Rect temp = r;
	--r;
	return temp;
}

// console version
std::ostream& operator<<(std::ostream& os, const Rect& r)
{
	os << "위치:(" << r.getUpperLeftX() << ", "
		<< r.getUpperLeftY() << ")";
	os << " 폭:" << r.getLowerRightX() - r.getUpperLeftX();
	os << " 높이:" << r.getLowerRightY() -r.getUpperLeftY();
	return os;
}