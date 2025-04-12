#include <iostream>
using namespace std;

class Accumulator
{
public:
	Accumulator()
		: counter(0)
	{}

	int operator()(int i)
	{
		return counter += i;
	}

	int counter;
};

int main()
{
	Accumulator a;
	cout << a(10) << endl;
	cout << a(20) << endl;

	return 0;
}