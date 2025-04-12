// sharebyduplicatehandle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"  // #include <Windows.h> #include <iostream> 추가

using namespace std;

int main()
{

	// 공유할 뮤텍스 개체를 생성합니다.
	HANDLE hEvent = CreateEvent(nullptr, FALSE, FALSE, L"duplicatehandle");
	if (hEvent == NULL)
	{
		cout << "error code: " << GetLastError() << endl;
		system("pause");
		return 0;
	}
	// 실행중인 계산기라는 이름을 가진 프로세스를 찾습니다.
	HWND hNotepad = FindWindow(NULL, L"제목 없음 - 메모장");

	// 계산기를 찾지 못한 경우 메세지를 출력후 프로세스를 종료합니다.
	if (hNotepad == nullptr)
	{
		cout << "Not found Notepad." << endl;
		system("pause");
		return 0;
	}

	DWORD dPid;

	// HWND를 이용하여 PID를 가져옵니다.
	GetWindowThreadProcessId(hNotepad, &dPid);

	// 프로세스 오픈에 성공하면, 핸들 복제를 시작합니다.
	if (HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dPid))
	{
		HANDLE hTarget;
		if(DuplicateHandle(GetCurrentProcess(), hEvent, hProcess, &hTarget, 0, FALSE, DUPLICATE_SAME_ACCESS))
		{
			
			cout << "Success duplicate handle." << endl;
		}
		else
		{ 
			cout << GetLastError() << endl;
		}
		CloseHandle(hProcess);
		system("pause");
	}

	CloseHandle(hEvent);

	return 0;
}

