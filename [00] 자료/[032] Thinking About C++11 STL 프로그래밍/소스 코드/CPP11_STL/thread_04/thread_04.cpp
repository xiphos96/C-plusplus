
#include <thread>
#include <iostream>
#include <mutex>

int main()
{
	// ����ȭ ��ü. ������ �ڼ��� �����ϰڴ�.
	std::mutex mtx_lock;

	int nThreadRunCount1 = 0;
	std::thread Thread1;
	Thread1 = std::thread( [&] () 
		  {
			  ::_sleep(100); // 0.01�� ���
			  for( int i = 0; i < 5; ++i )
			  {
				  ++nThreadRunCount1;
			      mtx_lock.lock();
				  std::cout << "Thread1 ID : " << Thread1.get_id() << std::endl;
				  mtx_lock.unlock();
			   }
			} );
	

	int nThreadRunCount2 = 0;
	std::thread Thread2;
	Thread2 = std::thread( [&] () 
		  {
			  ::_sleep(100); // 0.01�� ���
			   for( int i = 0; i < 5; ++i )
			   {
				   ++nThreadRunCount2;
									   
				   mtx_lock.lock();
				   std::cout << "Thread2 ID : " << Thread2.get_id() << std::endl;
				   mtx_lock.unlock();
				}
		 } );
	
	
	// Thread1�� Thread2�� ������ ID�� ����� �Ҵ� ���� �� swap�ϱ� ���ؼ� �Ͻ� ���
	while( nThreadRunCount1 < 3 && nThreadRunCount2 < 3 )
	{
	}

	mtx_lock.lock();
	std::cout << "swap 1,2" << std::endl;
	mtx_lock.unlock();

	Thread1.swap( Thread2 );
	
	Thread1.join();
	Thread2.join();

	return 0;
}


