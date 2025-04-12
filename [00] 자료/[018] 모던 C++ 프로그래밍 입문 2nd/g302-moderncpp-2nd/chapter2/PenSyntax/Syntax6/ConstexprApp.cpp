#include <iostream>

constexpr size_t getArraySize(int k)
{
	return k == 0 ? 10 : k;
}

int main()
{
	int myArray[1 + getArraySize(0)];
	int count = 0;
	for (size_t i = 0; i < 1 + getArraySize(0); ++i) {
		myArray[i] = i;
		count = count + 1;
	}
	std::cout << "array size: " << count << std::endl;

	return 0;
}