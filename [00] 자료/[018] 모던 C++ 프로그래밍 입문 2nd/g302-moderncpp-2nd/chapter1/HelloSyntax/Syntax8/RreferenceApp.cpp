#include <iostream>

void increment(int& value)
{
	std::cout << "������ ���۷����� ����" << std::endl;
	++value;
}

void increment(int&& value)
{
	std::cout << "������ ���۷����� ����" << std::endl;
	++value;
}

int main()
{
	int a = 10, b = 20;
	increment(a);
	std::cout << a << std::endl;
	increment(a + b);
	increment(3);

	return 0;
}