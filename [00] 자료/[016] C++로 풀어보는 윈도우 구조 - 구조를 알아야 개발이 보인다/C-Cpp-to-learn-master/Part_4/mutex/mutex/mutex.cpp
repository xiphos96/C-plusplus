// mutex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // stdafx.h�� #include <windows.h> #include <iostream> #include <mutex> �߰�

using namespace std;

void ThreadLock();

std::mutex m; // ���ؽ� ��ü ����

int i = 0; // �����Ǵ� ��ü

int main()
{
	HANDLE thread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadLock, NULL, 0, NULL); // ���� ��ü i �� �����ϴ� ������ 1
	HANDLE thread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadLock, NULL, 0, NULL); // ���� ��ü i �� �����ϴ� ������ 2
	HANDLE thread3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadLock, NULL, 0, NULL); // ���� ��ü i �� �����ϴ� ������ 3
	HANDLE thread4 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadLock, NULL, 0, NULL); // ���� ��ü i �� �����ϴ� ������ 4

	system("pause");

	return 0;
}

void ThreadLock()
{
	while (i < 10)
	{	
		m.lock(); // ���ؽ��� �̿��� ����ϰ��� �ϴ� ��ü�� lock ��ŵ�ϴ�.
			cout << GetCurrentThreadId() <<" Thread :"  << i << endl;
			i++;
		m.unlock(); // ��ü ����� �Ϸ�Ǿ��ٸ� unlock�� ���� �ٸ� �����忡�� ������ �� �ֵ��� �մϴ�.
	}
	return;
}


