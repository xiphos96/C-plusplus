// sharebyname.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //#include <Windows.h> #include <iostream> 추가

using namespace std;

int main()
{
	HANDLE mutex = CreateMutex(0, FALSE, L"ShareObject"); // 뮤텍스를 하나 만듭니다.
	if (GetLastError() == ERROR_ALREADY_EXISTS) // GetLastError를 이용하여 이미 뮤텍스가 있는 경우 이미 존재한다고 통보 합니다.
		cout << "already made mutex" << endl;
	cout << "Mutex value: " << mutex << endl;
	cout << "Process ID: " << GetCurrentProcessId() << endl;
	system("pause");

    return 0;
}

