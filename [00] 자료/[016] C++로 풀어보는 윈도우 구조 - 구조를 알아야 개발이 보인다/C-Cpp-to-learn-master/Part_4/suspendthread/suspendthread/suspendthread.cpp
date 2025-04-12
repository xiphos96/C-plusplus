// suspendthread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //#include <windows.h> #include <iostream> �߰�

using namespace std;

void ThreadTest();

int main()
{
	HANDLE thread;
	thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadTest, NULL, CREATE_SUSPENDED, NULL); // �����带 ������ �� �ٷ� ��� ���·� �������ϴ�.

	cout << "Thread Resume start." << endl;
	system("pause");
	ResumeThread(thread); // ������ �����带 �簳�մϴ�.
	system("pause");
	SuspendThread(thread); // ������ �����带 �����·� ��ȯ�մϴ�.
	system("pause");
	return 0;
}

void ThreadTest()
{
	int i = 1;
	cout <<"Thread :" << GetCurrentThreadId() << endl;
	while (true)
	{
		if (i == 1000000) // i�� ���� �ݺ����� ���� 1000000�̸� �ٽ� �����ϵ��� ó��
		{
			cout << i;
			i = 0;
		}
		i++; //

	}
	return;
}


