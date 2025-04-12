// threadpri.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <windows.h> #include <iostream> 추가

using namespace std;

int main()
{
	// 현재 우선 순위 확인
	cout << "Current Process Priority: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;
	cout << "Current Thread Priority: " << GetThreadPriority(GetCurrentThread()) << endl;
	
	// 프로세스 우선 순위를 13 변경, 스레드는 높은 우선 순위로 변경
	cout << "Let's Change Process PRI: HIGH_PRIORITY_CLASS" << endl;
	cout << "Let's Change Thread PRI: THREAD_PRIORITY_HIGHEST" << endl;
	system("pause");
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);
	
	cout << "Current Process Priority: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;
	cout << "Current Thread Priority: " << GetThreadPriority(GetCurrentThread()) << endl;

	// 프로세스 우선 순위를 24 변경, 스레드는 높은 우선 순위로 유지
	cout << "Let's Change Process PRI: REALTIME_PRIORITY_CLASS" << endl;
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
	system("pause");
	cout << "Current Process Priority: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;
	cout << "Current Thread Priority: " << GetThreadPriority(GetCurrentThread()) << endl;

	// 프로세스 우선 순위를 4 변경, 스레드는 보통보다 낮은 우선 순위로 변경
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

