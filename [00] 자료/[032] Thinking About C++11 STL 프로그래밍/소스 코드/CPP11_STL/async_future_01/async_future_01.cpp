
#include <iostream>
#include <future>
#include <thread>

int GetMoneyFromDB(int CharCd) 
{ 
	auto ThreadID = std::this_thread::get_id(); 
	std::cout << "GetMoneyFromDB. Thread ID: " << ThreadID << std::endl;
	return CharCd; 
}

int main()
{
	auto ThreadID = std::this_thread::get_id(); 
	std::cout << "���� ������ ID: " << ThreadID << std::endl;

	std::cout << "std::async(std::launch::async, GetMoneyFromDB)" << std::endl;
    std::future<int> future1 = std::async(std::launch::async, GetMoneyFromDB, 10);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
	std::cout << "���� �����忡�� 10 msec ���" << std::endl;
    
    auto result1 = future1.get();
    std::cout << "GetMoneyFromDB�� ��ȯ ��" << result1 << std::endl;
  
	
	std::cout << std::endl;
	  
    
	std::cout << "std::async(std::launch::deferred, GetMoneyFromDB)" << std::endl;
    std::future<int> future2 = std::async(std::launch::deferred, GetMoneyFromDB, 20);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "���� �����忡�� 10 msec ���" << std::endl;

    int result2 = future2.get();
    std::cout << "GetMoneyFromDB�� ��ȯ ��" << result2 << std::endl;
  
	return 0;
}

