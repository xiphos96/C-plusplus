// stackoverflow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> �߰�

using namespace std;

void ThreadSpeed();

int main()
{
	int stacksize = 16 << 20; // ��° �����ڿ� ������ ��Ʈ ����ŭ ù° �����ڸ� ��Ʈ ������ �������� �̵��մϴ�.

	HANDLE thread = CreateThread(NULL, stacksize, (LPTHREAD_START_ROUTINE)ThreadSpeed, NULL, STACK_SIZE_PARAM_IS_A_RESERVATION, NULL); //�����带 �����մϴ�.

	WaitForSingleObject(thread, INFINITE); // thread�� ���� ������ Ȯ���Ͽ� ����ϵ��� �մϴ�.
    return 0;
}

void ThreadSpeed()
{
	cout << "Create ThreadSpeed Thread Function" << endl;
	system("pause");
	return;
}
