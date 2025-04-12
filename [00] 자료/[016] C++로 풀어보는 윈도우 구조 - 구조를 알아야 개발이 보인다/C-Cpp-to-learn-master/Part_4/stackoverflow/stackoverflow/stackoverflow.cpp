// stackoverflow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> 추가

using namespace std;

void ThreadSpeed();

int main()
{
	int stacksize = 16 << 20; // 둘째 연산자에 지정한 비트 수만큼 첫째 연산자를 비트 단위로 왼쪽으로 이동합니다.

	HANDLE thread = CreateThread(NULL, stacksize, (LPTHREAD_START_ROUTINE)ThreadSpeed, NULL, STACK_SIZE_PARAM_IS_A_RESERVATION, NULL); //스레드를 생성합니다.

	WaitForSingleObject(thread, INFINITE); // thread의 종료 유무를 확인하여 대기하도록 합니다.
    return 0;
}

void ThreadSpeed()
{
	cout << "Create ThreadSpeed Thread Function" << endl;
	system("pause");
	return;
}
