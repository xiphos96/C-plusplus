// sharebyname.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //#include <Windows.h> #include <iostream> �߰�

using namespace std;

int main()
{
	HANDLE mutex = CreateMutex(0, FALSE, L"ShareObject"); // ���ؽ��� �ϳ� ����ϴ�.
	if (GetLastError() == ERROR_ALREADY_EXISTS) // GetLastError�� �̿��Ͽ� �̹� ���ؽ��� �ִ� ��� �̹� �����Ѵٰ� �뺸 �մϴ�.
		cout << "already made mutex" << endl;
	cout << "Mutex value: " << mutex << endl;
	cout << "Process ID: " << GetCurrentProcessId() << endl;
	system("pause");

    return 0;
}

