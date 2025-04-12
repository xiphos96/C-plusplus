// sharebyduplicatehandle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"  // #include <Windows.h> #include <iostream> �߰�

using namespace std;

int main()
{

	// ������ ���ؽ� ��ü�� �����մϴ�.
	HANDLE hEvent = CreateEvent(nullptr, FALSE, FALSE, L"duplicatehandle");
	if (hEvent == NULL)
	{
		cout << "error code: " << GetLastError() << endl;
		system("pause");
		return 0;
	}
	// �������� ������ �̸��� ���� ���μ����� ã���ϴ�.
	HWND hNotepad = FindWindow(NULL, L"���� ���� - �޸���");

	// ���⸦ ã�� ���� ��� �޼����� ����� ���μ����� �����մϴ�.
	if (hNotepad == nullptr)
	{
		cout << "Not found Notepad." << endl;
		system("pause");
		return 0;
	}

	DWORD dPid;

	// HWND�� �̿��Ͽ� PID�� �����ɴϴ�.
	GetWindowThreadProcessId(hNotepad, &dPid);

	// ���μ��� ���¿� �����ϸ�, �ڵ� ������ �����մϴ�.
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

