// threadpri.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <windows.h> #include <iostream> �߰�

using namespace std;

int main()
{
	// ���� �켱 ���� Ȯ��
	cout << "Current Process Priority: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;
	cout << "Current Thread Priority: " << GetThreadPriority(GetCurrentThread()) << endl;
	
	// ���μ��� �켱 ������ 13 ����, ������� ���� �켱 ������ ����
	cout << "Let's Change Process PRI: HIGH_PRIORITY_CLASS" << endl;
	cout << "Let's Change Thread PRI: THREAD_PRIORITY_HIGHEST" << endl;
	system("pause");
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);
	
	cout << "Current Process Priority: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;
	cout << "Current Thread Priority: " << GetThreadPriority(GetCurrentThread()) << endl;

	// ���μ��� �켱 ������ 24 ����, ������� ���� �켱 ������ ����
	cout << "Let's Change Process PRI: REALTIME_PRIORITY_CLASS" << endl;
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
	system("pause");
	cout << "Current Process Priority: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;
	cout << "Current Thread Priority: " << GetThreadPriority(GetCurrentThread()) << endl;

	// ���μ��� �켱 ������ 4 ����, ������� ���뺸�� ���� �켱 ������ ����
	cout << "Let's Change Process PRI: IDLE_PRIORITY_CLASS" << endl;
	cout << "Let's Change Thread PRI: THREAD_PRIORITY_BELOW_NORMAL" << endl;
	system("pause");
	SetPriorityClass(GetCurrentProcess(), IDLE_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL);

	cout << "Current Process Priority: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;
	cout << "Current Thread Priority: " << GetThreadPriority(GetCurrentThread()) << endl;
	system("pause");
    return 0;
}

