
#include <iostream>
#include <string>


int main()
{
	std::string ID1 = "jacking";
	auto hash1 = std::hash<std::string>()(ID1);
	std::cout << "jacking�� �ؽ� ��: " << hash1 << std::endl;

	std::string ID2 = "jacking75";
	auto hash2 = std::hash<std::string>()(ID2);
	std::cout << "jacking75�� �ؽ� ��: " << hash2 << std::endl;

	return 0;
}

