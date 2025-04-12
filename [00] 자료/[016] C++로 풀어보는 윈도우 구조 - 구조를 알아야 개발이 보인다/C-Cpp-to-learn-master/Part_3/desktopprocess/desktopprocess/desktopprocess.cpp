// desktopprocess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> 추가

using namespace std;

int main()
{
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };

	HDESK currentdesktop = GetThreadDesktop(GetCurrentThreadId()); // 현재 Desktop 정보 기억
	
	HDESK hiddendesktop = CreateDesktop(L"Hidden", NULL, NULL, 0, GENERIC_ALL, NULL); //새로운 Desktop을 만듭니다.

	si.lpDesktop = L"Hidden"; // STARTUPINFO의 시작할 Desktop 정보를 넣어줍니다.
	wstring command = L"cmd.exe"; // 메모장 실행을 위한 값을 넣어줍니다.

	CreateProcess(NULL, &command[0], NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	// 자식 프로세스를 생성하고 새로 만들어지 Desktop 으로 이동합니다. 
	SetThreadDesktop(hiddendesktop); 
	SwitchDesktop(hiddendesktop);

	while (WaitForSingleObject(pi.hProcess, 500) == WAIT_TIMEOUT) // 생성된 메모장이 종료되는지를 확인합니다.
	{
		cout << "Waiting:" << pi.hProcess << " still run.\n" << endl;
	}

	// 메모장이 종료되면 다시 기존 Desktop으로 복귀합니다.
	SetThreadDesktop(currentdesktop);
	SwitchDesktop(currentdesktop);

	system("pause");

    return 0;
}

