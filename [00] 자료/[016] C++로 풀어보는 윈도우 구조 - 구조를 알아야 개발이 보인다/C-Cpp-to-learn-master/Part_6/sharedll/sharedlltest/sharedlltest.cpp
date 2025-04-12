// sharedlltest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> 추가

using namespace std;

#pragma comment(lib, "..\\Debug\\sharedll.lib")
__declspec(dllimport) int Sharecounter;

int main()
{
	while (true)
	{	
		cout << "Share Count:" << Sharecounter << endl; //현재의 Sharecounter 값을 보여줍니다.
		cout << "Input to number to add, -1 to quit: "; // -1을 입력하면 프로그램을 종료합니다.
		int number;
		cin >> number; // 더하기 입력 받기
		if(number < 0) break; // 0보다 작으면 while문을 종료합니다.
		Sharecounter += number; // 입력한 값을 Sharecounter에 더합니다.
	}
    return 0;
}

