// ppl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <windows.h> #include <iostream> #include <ppl.h> �߰�

using namespace std;
using namespace concurrency; // ����ó�� �Լ��� �ٷ� ����ϱ� ���� �߰��� ���� �����̽�

#pragma comment(lib, "winmm.lib") // timeGetTime �Լ� ���

void PrimesSerial(); // C3861'identifier': identifier not found ���� ����
void PrimesParallel(); // C3861'identifier': identifier not found ���� ����

int main()
{
	PrimesSerial();
	PrimesParallel();
	system("pause");
    return 0;
}

void PrimesSerial()
{
	DWORD start = timeGetTime();
	for (int i = 2; i<20000000; i++)
	{
		bool prime = true;
		for (int j = 2; j*j <= i; j++)
		{
			if (i % j == 0)
			{
				prime = false;
				break;
			}
		}
	}
	DWORD sum = timeGetTime() - start;
	cout << "PrimesSerial Time: " << sum << endl;
	return;
}

void PrimesParallel()
{
	DWORD start = timeGetTime();

	parallel_for (2, 20000000, [&](int i)
	{
		bool prime = true;
		for (int j = 2; j*j <= i; j++)
		{
			if (i % j == 0)
			{
				prime = false;
				break;
			}
		}
	}); //  For���� ����ó���ϰ��� �ϴ� ������ �ϳ��� ó�� �������� �����ϴ�.
	DWORD sum = timeGetTime() - start;
	cout << "PrimesParallel Time: " << sum << endl;
	return;
}