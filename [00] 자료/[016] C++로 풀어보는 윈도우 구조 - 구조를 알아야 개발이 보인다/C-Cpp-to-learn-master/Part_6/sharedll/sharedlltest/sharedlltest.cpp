// sharedlltest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> �߰�

using namespace std;

#pragma comment(lib, "..\\Debug\\sharedll.lib")
__declspec(dllimport) int Sharecounter;

int main()
{
	while (true)
	{	
		cout << "Share Count:" << Sharecounter << endl; //������ Sharecounter ���� �����ݴϴ�.
		cout << "Input to number to add, -1 to quit: "; // -1�� �Է��ϸ� ���α׷��� �����մϴ�.
		int number;
		cin >> number; // ���ϱ� �Է� �ޱ�
		if(number < 0) break; // 0���� ������ while���� �����մϴ�.
		Sharecounter += number; // �Է��� ���� Sharecounter�� ���մϴ�.
	}
    return 0;
}

