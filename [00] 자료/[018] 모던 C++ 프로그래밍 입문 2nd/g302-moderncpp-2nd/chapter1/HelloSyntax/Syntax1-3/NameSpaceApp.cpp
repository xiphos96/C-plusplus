#include <iostream>

namespace A
{
	void y(void)
	{
		std::cout << "A ����� y �Լ�" << std::endl;
	}
}

namespace B
{
	void y(void)
	{
		std::cout << "B ����� y �Լ�" << std::endl;
	}
}

int foo(int x)
{
	return x;
}

int main()
{
	int result = ::foo(8);          // int result = foo(8);
	std::cout << result << std::endl;
	A::y();
	B::y();

	return 0;
}