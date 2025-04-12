// createdesktop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"  // stdafx.h 헤더에 #include <windows.h> #include <iostream>를 추가합니다.

using namespace std;

int main()
{
	cout << "Current Desktop is:" << GetThreadDesktop(GetCurrentThreadId()) << "\n" << endl;

	HDESK hBeforeDesktop = GetThreadDesktop(GetCurrentThreadId()); // 현재 Desktop을 저정합니다.

	HDESK hAfterDesktop = CreateDesktop(L"hidden", NULL, NULL, 0, GENERIC_ALL, NULL); // 새로운 Desktop을 생성합니다.

	cout << "Change Thread Desktop\n" << endl;
	SetThreadDesktop(hAfterDesktop); // 생성한 데스크톱은 현재 프로세스에 설정합니다. 이를 통해 생성한 테스크톱에서 현재 코드가 동작할 수 있습니다.

	cout << "Current Desktop is:" << GetThreadDesktop(GetCurrentThreadId()) << "\n" << endl;
	system("pause");
	cout << "Start Switch Desktop\n" << endl;

	SwitchDesktop(hAfterDesktop);  // 설정한 데스크 톱을 활성화 합니다.

	Sleep(3000);

	SwitchDesktop(hBeforeDesktop); // 다시 기존의 Desktop을 활성화 합니다.
	CloseDesktop(hAfterDesktop);
	system("pause");
	return 0;
}
