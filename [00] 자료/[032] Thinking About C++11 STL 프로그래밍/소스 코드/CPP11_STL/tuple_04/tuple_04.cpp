
#include <tuple>
#include <iostream>
#include <string>

int main()
{
	std::cout << "- ���� �����͸� �����ϴ� tuple �����" << std::endl;
	{
		int nUserIndex = 11;
		std::string UserName = "jacking";
	
		auto refUserItem = std::tie(nUserIndex, UserName);
	
		std::cout << std::get<0>(refUserItem) << std::endl;
		std::cout << std::get<1>(refUserItem) << std::endl;

		std::get<0>(refUserItem) = 12;
		std::get<1>(refUserItem) = "jacking75";

		std::cout << nUserIndex << std::endl;
		std::cout << UserName << std::endl;
	}

	std::cout << "- tuple�� ����� �����͸� �ϰ������� ������ ���" << std::endl;
	{
		std::tuple<int, std::string> UserInfo(1002, "jacking");

		int nUserIndex = 0;
		std::string UserName;

		std::tie(nUserIndex, UserName) = UserInfo;

		std::cout << nUserIndex << std::endl;
		std::cout << UserName << std::endl;
	}

	std::cout << "- �Ϻ� ��Ҹ� �����ϰ� �ϰ������� ������ ���" << std::endl;
	{
		std::tuple<int, std::string, int> UserInfo(1003, "jacking", 22);

		int nUserIndex = 0;
		int nLevel = 0;

		std::tie(nUserIndex, std::ignore, nLevel) = UserInfo;

		std::cout << nUserIndex << std::endl;
		std::cout << nLevel << std::endl;
	}

	return 0;
}



