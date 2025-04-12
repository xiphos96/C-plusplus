// createprocess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> �߰�

using namespace std;

int main()
{
	PROCESS_INFORMATION pi = { 0 }; // lpProcessInformation �� ���� ����ü ����
	STARTUPINFO si = { 0 }; // lpStartupInfo �� ���� ����ü ����

	wstring command = L"notepad.exe";
	wchar_t *evn = L"createprocess=test\0createprocess2=test";

	CreateProcess(NULL, &command[0], NULL, NULL, FALSE, CREATE_UNICODE_ENVIRONMENT, evn, NULL, &si, &pi); //�޸��� ���μ��� ����
	
	cout << "Notepad Create Handle ID:" << pi.hProcess << "\n" << endl; // ������ �ڵ� ������ ���
	
	while (WaitForSingleObject(pi.hThread, 500) == WAIT_TIMEOUT) //pi ����ü�� �ڵ��� �Ѱ��ݴϴ�.������ �ڵ��� �̿��� �� ������, �������� �߻��� �� �ֽ��ϴ�.
	{
		cout << "Waiting:" << pi.hThread << " still run.\n" << endl;
	}		

	system("pause");

    return 0;
}

