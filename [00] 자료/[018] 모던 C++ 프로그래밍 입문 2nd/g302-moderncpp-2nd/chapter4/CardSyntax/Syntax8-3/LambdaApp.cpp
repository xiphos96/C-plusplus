#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// generalized lambda capture
	cout << "generalized lambda capture" << endl;
	int x = 4;
	auto lambda1 = [&r = x, x = x + 1, value = 2]() -> int {
		r += value;
		return x + value;
	};
	cout << "lambda1 returns " << lambda1() << endl;
	cout << "x is " << x << endl;
	// generic lambda
	cout << "generic lambda" << endl;
	auto lambda2 = [](auto a) { return a; };
	int three = lambda2(3);
	cout << "lambda2 returns " << three << endl;
	char const* hello = lambda2("hello");
	cout << "lambda2 returns " << hello << endl;

	return 0;
}