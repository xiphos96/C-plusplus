// sharebyineritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //#include <Windows.h> #include <iostream> �߰�

using namespace std;

int main()
{
	SECURITY_ATTRIBUTES sa = { sizeof(sa) };
	sa.bInheritHandle = TRUE;

	HANDLE hevent = CreateEvent(&sa, TRUE, FALSE, L"Shareineritance"); // ���� ���μ����� ������ �� �ֵ��� ������ �ο��Ͽ� ��ü�� �����մϴ�.

	// ���μ��� ������ ���� �ʱ�ȭ �۾�
	PROCESS_INFORMATION pi;
	STARTUPINFO si = { sizeof(si) };
	WCHAR process[128] = L"shareclient.exe";
	// ���μ��� ������ �����ϸ� �ڽ� ���μ����� ���� �θ� ���μ����� ����˴ϴ�.
	if (CreateProcess(nullptr, process, nullptr, nullptr, TRUE, CREATE_NEW_CONSOLE, nullptr, nullptr, &si, &pi))
	{
		cout << "Success create process" << endl;
	}	
	CloseHandle(hevent);
    return 0;
}

