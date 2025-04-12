// accessmask.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> 추가

using namespace std;

int main()
{

	HWND hCalc = FindWindow(NULL, L"계산기");
	// 계산기를 찾지 못한 경우 메세지를 출력후 프로세스를 종료합니다.
	if (hCalc == nullptr)
	{
		cout << "Not found Calc." << endl;
		system("pause");
		return 0;
	}

	DWORD dPid;

	// HWND를 이용하여 PID를 가져옵니다.
	GetWindowThreadProcessId(hCalc, &dPid);

	if (HANDLE hProcess = OpenProcess(SYNCHRONIZE, FALSE, dPid))
	{
		// 정상적이라면 현재 프로세스 종료 권한이 없기 때문에 종료가 실패하고 에러 코드는 권한이 없다는 메세지가 나올 것 입니다.
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

