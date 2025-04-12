// mutex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // stdafx.h에 #include <windows.h> #include <iostream> #include <mutex> 추가

using namespace std;

void ThreadLock();

std::mutex m; // 뮤텍스 객체 선언

int i = 0; // 공유되는 객체

int main()
{
	HANDLE thread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadLock, NULL, 0, NULL); // 공유 객체 i 에 접근하는 스레드 1
	HANDLE thread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadLock, NULL, 0, NULL); // 공유 객체 i 에 접근하는 스레드 2
	HANDLE thread3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadLock, NULL, 0, NULL); // 공유 객체 i 에 접근하는 스레드 3
	HANDLE thread4 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadLock, NULL, 0, NULL); // 공유 객체 i 에 접근하는 스레드 4

	system("pause");

	return 0;
}

void ThreadLock()
{
	while (i < 10)
	{	
		m.lock(); // 뮤텍스를 이용해 사용하고자 하는 객체를 lock 시킵니다.
			cout << GetCurrentThreadId() <<" Thread :"  << i << endl;
			i++;
		m.unlock(); // 객체 사용이 완료되었다면 unlock을 통해 다른 스레드에서 접근할 수 있도록 합니다.
	}
	return;
}


