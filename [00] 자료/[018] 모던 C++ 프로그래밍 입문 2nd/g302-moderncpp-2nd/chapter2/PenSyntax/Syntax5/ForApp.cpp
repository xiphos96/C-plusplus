#include <iostream>
#include <string>

int main()
{
	int arr[5] = { 0, 1, 2, 3, 4 };
	std::cout << "�Ϲ� for��" << std::endl;
	for (auto i = 0; i < 5; ++i)
		std::cout << arr[i];
	std::cout << std::endl;
	std::cout << "���� ��� for��" << std::endl;
	for (auto i : arr)
		std::cout << i;
	std::cout << std::endl;
	std::string strArr[3] = { "eum", "doo", "hun" };
	for (auto s : strArr)
		std::cout << s;
	std::cout << std::endl;

	return 0;
}