#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>			// for_each
using namespace std;
using namespace std::placeholders;

void modify23(int x, int& y, int& z)
{
	cout << "modify23 input: " << x << ' ' << y << ' ' << z << endl;
	y = y + x;
	z = z + y;
	cout << "modify23 output: " << x << ' ' << y << ' ' << z << endl;
}

int main()
{
	cout << "using bind in algorithms" << endl;
	vector<int> intVector = { 1, 2, 3 };
	for_each(intVector.begin(), intVector.end(), bind(modify23, 1, 2, _1));
	cout << intVector[0] << ' ' << intVector[1] << ' ' << intVector[2] << endl;
	cout << "using lambda in algorithms" << endl;
	intVector[0] = 1; intVector[1] = 2; intVector[2] = 3;
	for_each(intVector.begin(), intVector.end(),
	  [x = 1, y = 2](int& z) mutable {
		cout << "lambda input: " << x << ' ' << y << ' ' << z << endl;
		y = y + x;
		z = z + y;
		cout << "lambda output: " << x << ' ' << y << ' ' << z << endl;
	});
	cout << intVector[0] << ' ' << intVector[1] << ' ' << intVector[2] << endl;

	return 0;
}