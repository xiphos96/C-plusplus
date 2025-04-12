// createdesktop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"  // stdafx.h ����� #include <windows.h> #include <iostream>�� �߰��մϴ�.

using namespace std;

int main()
{
	cout << "Current Desktop is:" << GetThreadDesktop(GetCurrentThreadId()) << "\n" << endl;

	HDESK hBeforeDesktop = GetThreadDesktop(GetCurrentThreadId()); // ���� Desktop�� �����մϴ�.

	HDESK hAfterDesktop = CreateDesktop(L"hidden", NULL, NULL, 0, GENERIC_ALL, NULL); // ���ο� Desktop�� �����մϴ�.

	cout << "Change Thread Desktop\n" << endl;
	SetThreadDesktop(hAfterDesktop); // ������ ����ũ���� ���� ���μ����� �����մϴ�. �̸� ���� ������ �׽�ũ�鿡�� ���� �ڵ尡 ������ �� �ֽ��ϴ�.

	cout << "Current Desktop is:" << GetThreadDesktop(GetCurrentThreadId()) << "\n" << endl;
	system("pause");
	cout << "Start Switch Desktop\n" << endl;

	SwitchDesktop(hAfterDesktop);  // ������ ����ũ ���� Ȱ��ȭ �մϴ�.

	Sleep(3000);

	SwitchDesktop(hBeforeDesktop); // �ٽ� ������ Desktop�� Ȱ��ȭ �մϴ�.
	CloseDesktop(hAfterDesktop);
	system("pause");
	return 0;
}
