#include <iostream>
using std::cout; using std::endl;

class Base
{
protected:
	int x;
private:
	int y;
};

class Derived : public Base
{
public:
	void setX(int a)
	{ x = a; }
	int getX() const
	{ return x; }
private:
	int z;
};

int main()
{
	Derived derivedObject;
	derivedObject.setX(3);
	cout << derivedObject.getX() << endl;

	return 0;
}