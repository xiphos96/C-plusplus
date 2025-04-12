
#include <tuple>
#include <iostream>
#include <string>

struct ITEM
{
	int nID;
};

int main()
{
	ITEM item;
	item.nID = 10001;

	std::tuple<int, std::string, ITEM> UserItem = std::make_tuple(1, "jacking", item);

	auto nCount = std::tuple_size<decltype(UserItem)>::value;
	
	std::cout << "tuple UserItem�� ��� ��: " << nCount << std::endl;

	return 0;
}

