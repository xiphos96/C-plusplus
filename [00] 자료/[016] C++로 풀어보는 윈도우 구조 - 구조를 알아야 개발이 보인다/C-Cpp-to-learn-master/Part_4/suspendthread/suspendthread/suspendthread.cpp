// suspendthread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //#include <windows.h> #include <iostream> 추가

using namespace std;

void ThreadTest();

int main()
{
	HANDLE thread;
	thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadTest, NULL, CREATE_SUSPENDED, NULL); // 스레드를 생성할 때 바로 대기 상태로 보내집니다.

	cout << "Thread Resume start." << endl;
	system("pause");
	ResumeThread(thread); // 지정한 스레드를 재개합니다.
	system("pause");
	SuspendThread(thread); // 지정한 스레드를 대기상태로 전환합니다.
	system("pause");
	return 0;
}

void ThreadTest()
{
	int i = 1;
	cout <<"Thread :" << GetCurrentThreadId() << endl;
	while (true)
	{
		if (i == 1000000) // i를 무한 반복으로 값이 1000000이면 다시 시작하도록 처리
		{
			cout << i;
			i = 0;
		}
		i++; //

	}
	return;
}


