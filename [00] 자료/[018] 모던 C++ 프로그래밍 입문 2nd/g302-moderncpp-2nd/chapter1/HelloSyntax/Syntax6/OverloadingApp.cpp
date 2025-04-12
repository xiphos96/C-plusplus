#include <iostream>
using std::cout;
using std::endl;

double ave(double n1, double n2)
{
	return ((n1 + n2) / 2.0);
}

double ave(double n1, double n2, double n3)
{
	return ((n1 + n2 + n3) / 3.0);
}

int main()
{
	cout << ave(3.0, 2.9, 2.0) << endl;
	cout << ave(3.5, 4.5) << endl;

	return 0;
}