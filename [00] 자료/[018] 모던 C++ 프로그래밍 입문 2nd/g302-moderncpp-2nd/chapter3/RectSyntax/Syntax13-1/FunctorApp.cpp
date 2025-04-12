#include <iostream>
using namespace std;

class Functor
{
public:
	void operator()(int k) const
	{
		cout << "Functor: passed parameter = " << k << endl;
	}
};

int main()
{
	Functor func;
	func(3);

	return 0;
}