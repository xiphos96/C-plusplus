#include <iostream>
#include <numbers>

int main()
{
	std::cout << "Pi: " << std::numbers::pi << std::endl;
	std::cout << "e: " << std::numbers::e << std::endl;
	std::cout << "log2(e): " << std::numbers::log2e << std::endl;
	std::cout << "log10(e): " << std::numbers::log10e << std::endl;
	std::cout << "ln(2): " << std::numbers::ln2 << std::endl;
	std::cout << "ln(10): " << std::numbers::ln10 << std::endl;
	std::cout << "sqrt(2): " << std::numbers::sqrt2 << std::endl;
	std::cout << "sqrt(3): " << std::numbers::sqrt3 << std::endl;

	return 0;
}