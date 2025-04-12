// sharebyineritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //#include <Windows.h> #include <iostream> 추가

using namespace std;

int main()
{
	SECURITY_ATTRIBUTES sa = { sizeof(sa) };
	sa.bInheritHandle = TRUE;

	HANDLE hevent = CreateEvent(&sa, TRUE, FALSE, L"Shareineritance"); // 현재 프로세스에 공유할 수 있도록 권한을 부여하여 객체를 생성합니다.

	// 프로세스 생성을 위한 초기화 작업
	PROCESS_INFORMATION pi;
	STARTUPINFO si = { sizeof(si) };
	WCHAR process[128] = L"shareclient.exe";
	// 프로세스 생성이 성공하면 자식 프로세스만 남고 부모 프로세스는 종료됩니다.
	if (CreateProcess(nullptr, process, nullptr, nullptr, TRUE, CREATE_NEW_CONSOLE, nullptr, nullptr, &si, &pi))
	{
		cout << "Success create process" << endl;
	}	
	CloseHandle(hevent);
    return 0;
}

