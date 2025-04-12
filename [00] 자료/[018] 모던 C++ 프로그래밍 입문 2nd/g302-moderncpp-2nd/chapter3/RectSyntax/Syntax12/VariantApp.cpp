#include <iostream>
#include <variant>
using std::string;

union Union
{
	char c;
	int i;
	double d;
};

int main()
{
	// C++ union
	Union u;
	u.c = 'a';
	std::cout << u.c << std::endl;
	u.i = 123;
	std::cout << u.i << std::endl;
	u.d = 456.789;
	std::cout << u.d << std::endl;

	// C++17 std::variant - °³¼±µÈ union
	std::variant<int, double, string> myvariant{123};
	std::cout << std::get<0>(myvariant) << std::endl;
	std::cout << std::get<int>(myvariant) << std::endl;
	myvariant = 456.789;
	std::cout << std::get<1>(myvariant) << std::endl;
	std::cout << std::get<double>(myvariant) << std::endl;
	myvariant = "eum";
	std::cout << std::get<2>(myvariant) << std::endl;
	std::cout << std::get<string>(myvariant) << std::endl;

	return 0;
}