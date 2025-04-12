#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	void virtual display(int i)
	{
		cout << "in A: " << i << endl;
	}
};

class B
{
public:
	void virtual display(double d)
	{
		cout << "in B: " << d << endl;
	}
};

class C : public B, public A
{
public:
	void virtual display(int i)
	{
		A::display(i);
	}

	void virtual display(double d)
	{
		B::display(d);
	}
};

int main()
{
	C c;
	c.display(13);
	c.display(3.14);

	return 0;
}