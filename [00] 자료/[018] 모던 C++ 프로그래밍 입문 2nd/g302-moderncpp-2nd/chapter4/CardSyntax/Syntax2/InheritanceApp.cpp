#include <iostream>
using std::cout; using std::endl;

class Base
{
public:
	int x;
	int getZ() const
	{ return z; }
protected:
	int w;
private:
	int z = 100;
};

class Derived : public Base
{
public:
	int y;
	void setW(int a)
	{ w = a; }
};

int main()
{
	Derived derivedObject;
	cout << derivedObject.getZ() << endl;

	return 0;
}