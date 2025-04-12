// desktopprocess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> �߰�

using namespace std;

int main()
{
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };

	HDESK currentdesktop = GetThreadDesktop(GetCurrentThreadId()); // ���� Desktop ���� ���
	
	HDESK hiddendesktop = CreateDesktop(L"Hidden", NULL, NULL, 0, GENERIC_ALL, NULL); //���ο� Desktop�� ����ϴ�.

	si.lpDesktop = L"Hidden"; // STARTUPINFO�� ������ Desktop ������ �־��ݴϴ�.
	wstring command = L"cmd.exe"; // �޸��� ������ ���� ���� �־��ݴϴ�.

	CreateProcess(NULL, &command[0], NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	// �ڽ� ���μ����� �����ϰ� ���� ������� Desktop ���� �̵��մϴ�. 
	SetThreadDesktop(hiddendesktop); 
	SwitchDesktop(hiddendesktop);

	while (WaitForSingleObject(pi.hProcess, 500) == WAIT_TIMEOUT) // ������ �޸����� ����Ǵ����� Ȯ���մϴ�.
	{
		cout << "Waiting:" << pi.hProcess << " still run.\n" << endl;
	}

	// �޸����� ����Ǹ� �ٽ� ���� Desktop���� �����մϴ�.
	SetThreadDesktop(currentdesktop);
	SwitchDesktop(currentdesktop);

	system("pause");

    return 0;
}

