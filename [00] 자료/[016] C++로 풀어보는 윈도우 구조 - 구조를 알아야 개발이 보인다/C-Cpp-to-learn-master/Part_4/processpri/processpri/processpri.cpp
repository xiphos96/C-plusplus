// processpri.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> 추가

using namespace std;

int main()
{

	// 현재 우선 순위 확인
	cout << "Current Process PRI: " << hex << GetPriorityClass(GetCurrentProcess()) << endl; // 16진수로 변환하여 결과를 표시합니다.

	// 높은 우선 순위로 변경
	cout << "Let's Change Process PRI: HIGH_PRIORITY_CLASS" << endl;
	system("pause");
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	cout << "Current Process PRI: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;

	// 낮은 우선 순위로 변경	
	cout << "Let's Change Process PRI: IDLE_PRIORITY_CLASS" << endl;
	system("pause");
	SetPriorityClass(GetCurrentProcess(), IDLE_PRIORITY_CLASS);
	cout << "Current Process PRI: " << hex << GetPriorityClass(GetCurrentProcess()) << endl;

	system("pause");

	return 0;
}

