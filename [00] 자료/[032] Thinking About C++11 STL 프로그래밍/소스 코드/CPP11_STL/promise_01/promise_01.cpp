
#include <iostream>
#include <future>
#include <thread>
#include <vector>


void GetCharItems(std::promise<std::vector<int>>& ItemList)
{
	auto ThreadID = std::this_thread::get_id(); 
	std::cout << "GetCharItems ������ ID: " << ThreadID << std::endl;

	std::vector<int> itemlist;

	for (int i = 1; i <= 5; ++i) 
	{
		itemlist.push_back(i);
	}

	ItemList.set_value(std::move(itemlist)); 
}

int main()
{
	auto ThreadID = std::this_thread::get_id(); 
	std::cout << "���� ������ ID: " << ThreadID << std::endl;

	std::promise<std::vector<int>> ItemList;
	std::future<std::vector<int>> f = ItemList.get_future();

	auto t = std::thread(&GetCharItems, std::ref(ItemList));
	t.detach(); 

	auto result = f.get();

	for(auto ItemCode : result)
	{
		std::cout << "ĳ������ ������: " << ItemCode << std::endl;
	}

}


