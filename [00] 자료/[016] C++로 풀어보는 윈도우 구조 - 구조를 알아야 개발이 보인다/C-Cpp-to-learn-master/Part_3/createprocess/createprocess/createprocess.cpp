// createprocess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> 추가

using namespace std;

int main()
{
	PROCESS_INFORMATION pi = { 0 }; // lpProcessInformation 에 사용될 구조체 생성
	STARTUPINFO si = { 0 }; // lpStartupInfo 에 사용될 구조체 생성

	wstring command = L"notepad.exe";
	wchar_t *evn = L"createprocess=test\0createprocess2=test";

	CreateProcess(NULL, &command[0], NULL, NULL, FALSE, CREATE_UNICODE_ENVIRONMENT, evn, NULL, &si, &pi); //메모장 프로세스 생성
	
	cout << "Notepad Create Handle ID:" << pi.hProcess << "\n" << endl; // 생성된 핸들 정보를 출력
	
	while (WaitForSingleObject(pi.hThread, 500) == WAIT_TIMEOUT) //pi 구조체의 핸들을 넘겨줍니다.스레드 핸들을 이용할 수 있지만, 오동작이 발생할 수 있습니다.
	{
		cout << "Waiting:" << pi.hThread << " still run.\n" << endl;
	}		

	system("pause");

    return 0;
}

