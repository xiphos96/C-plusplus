
#include <thread>
#include <iostream>


int main()
{
	std::cout << "�ϵ���� ���ؽ�Ʈ �� : " << std::thread::hardware_concurrency() << std::endl;
	return 0;
}

