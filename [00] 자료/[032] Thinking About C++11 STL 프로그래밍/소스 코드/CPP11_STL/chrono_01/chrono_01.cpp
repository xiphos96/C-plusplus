
#include <chrono>
#include <iostream>
#include <cmath>


void Test()
{
	for ( long i = 0; i < 10000000; ++i )
	{
		std::sqrt( 123.456L );
	}
}

 

int main()
{
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

	Test();
	
	std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;

	std::cout << "Test() �Լ��� �����ϴ� �ɸ� �ð�(��) : " << sec.count() << " seconds" << std::endl;

	return 0;
}


