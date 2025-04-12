#include <iostream>

namespace A
{
	void y(void)
	{
		std::cout << "A 모듈의 y 함수" << std::endl;
	}
}

namespace B
{
	void y(void)
	{
		std::cout << "B 모듈의 y 함수" << std::endl;
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