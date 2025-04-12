// processpri.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> �߰�

using namespace std;

int main()
{

	// ���� �켱 ���� Ȯ��
	cout << "Current Process PRI: " << hex << GetPriorityClass(GetCurrentProcess()) << endl; // 16������ ��ȯ�Ͽ� ����� ǥ���մϴ�.

	// ���� �켱 ������ ����
	cout << "Let's Change Process PRI: HIGH_PRIORITY_CLASS" << endl;
	system("pause");
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	cout << "Current Process PRI: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;

	// ���� �켱 ������ ����	
	cout << "Let's Change Process PRI: IDLE_PRIORITY_CLASS" << endl;
	system("pause");
	SetPriorityClass(GetCurrentProcess(), IDLE_PRIORITY_CLASS);
	cout << "Current Process PRI: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;

	system("pause");

	return 0;
}

