
#include <iostream>
#include <string>


int main()
{
	std::string s1("HeroCompany");
	std::cout << "s1: " << s1 << std::endl;


	std::cout << "s1�� ����° ��ġ�� ����: " << s1[2] << std::endl;

	std::cout << "s1�� ����° ��ġ�� ����: " << s1.at(2) << std::endl;

	std::cout << "s1�� ù��° ��ġ�� ����: " << s1.front() << std::endl;

	std::cout << "s1�� ������ ��ġ�� ����: " << s1.back() << std::endl;



	// C��� ������ ���ڿ� ���
	const char* pC1 = s1.c_str();
	const char* pC2 = s1.data();
	
	std::cout << "pC1: " << pC1 << std::endl;
	std::cout << "pC2: " << pC2 << std::endl;

	return 0;
}





