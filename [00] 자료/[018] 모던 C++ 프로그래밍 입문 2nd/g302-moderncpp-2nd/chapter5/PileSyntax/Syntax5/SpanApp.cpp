#include <iostream>
#include <vector>
#include <array>
#include <span>

void printMe(std::span<int> container)
{
	std::cout << "container size: " << container.size() << std::endl;
	for (auto e : container)
		std::cout << e << ' ';
	std::cout << std::endl;
}

int main()
{
	int arr1[]{ 1, 2, 3, 4 };
	printMe(arr1);
	std::array<int, 5> arr2{ 1, 2, 3, 4, 5 };
	printMe(arr2);
	std::vector<int> vec{ 1, 2, 3, 4, 5, 6 };
	printMe(vec);
	std::cout << std::endl;

	std::span<int> span1{ vec };	// std::span span1 = vec;
	printMe(span1);
	std::span<int> span2{ vec.data(), vec.size() };
	printMe(span2);
	std::span<int> span3{ span1.subspan(1, span1.size()-2) };
	printMe(span3);
	span3[0] = 200;
	printMe(vec);

	return 0;
}