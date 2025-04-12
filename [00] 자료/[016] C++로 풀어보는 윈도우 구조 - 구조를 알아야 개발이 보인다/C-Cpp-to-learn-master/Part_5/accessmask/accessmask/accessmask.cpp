// accessmask.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> �߰�

using namespace std;

int main()
{

	HWND hCalc = FindWindow(NULL, L"����");
	// ���⸦ ã�� ���� ��� �޼����� ����� ���μ����� �����մϴ�.
	if (hCalc == nullptr)
	{
		cout << "Not found Calc." << endl;
		system("pause");
		return 0;
	}

	DWORD dPid;

	// HWND�� �̿��Ͽ� PID�� �����ɴϴ�.
	GetWindowThreadProcessId(hCalc, &dPid);

	if (HANDLE hProcess = OpenProcess(SYNCHRONIZE, FALSE, dPid))
	{
		// �������̶�� ���� ���μ��� ���� ������ ���� ������ ���ᰡ �����ϰ� ���� �ڵ�� ������ ���ٴ� �޼����� ���� �� �Դϴ�.
		if (TerminateProcess(hProcess, 0))
		{
			cout << "TerminateProcess Success." << endl;
		}
		else
		{
			cout << "Error TerminateProcess code :" << GetLastError() << endl;
		}

		WaitForSingleObject(hProcess, INFINITE);
		cout << "Calc termintaed by self." << endl;
		CloseHandle(hProcess);
	}
	else
	{
		cout << "Error :" << GetLastError() << endl;
	}
	
	system("pause");
	return 0;

}

