
#include <iostream>
#include <chrono>
#include <thread>
 
int main()
{
	std::cout << "sleep_for �׽�Ʈ ����" << std::endl;
	
	std::chrono::seconds dura( 3 );
	std::chrono::system_clock::time_point StartTime = std::chrono::system_clock::now();

	std::this_thread::sleep_for( dura ); 
	
	std::chrono::system_clock::time_point EndTime = std::chrono::system_clock::now();
	std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(EndTime - StartTime);
	
	std::cout << "��� �ð�(��)" << sec.count() << std::endl;

		
	std::cout << "sleep_until �׽�Ʈ ����" << std::endl;

	StartTime = std::chrono::system_clock::now();
	std::chrono::seconds dura_sec( 5 );
	
	std::this_thread::sleep_until( StartTime + dura_sec ); 
	
	EndTime = std::chrono::system_clock::now();
	sec = std::chrono::duration_cast<std::chrono::seconds>(EndTime - StartTime);
	
	std::cout << "��� �ð�(��)" << sec.count() << std::endl;

	return 0;
}

