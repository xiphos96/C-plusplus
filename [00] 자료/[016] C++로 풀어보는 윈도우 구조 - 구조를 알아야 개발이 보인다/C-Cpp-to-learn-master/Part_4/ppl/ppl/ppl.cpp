// ppl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <windows.h> #include <iostream> #include <ppl.h> 추가

using namespace std;
using namespace concurrency; // 병렬처리 함수를 바로 사용하기 위해 추가한 네임 스페이스

#pragma comment(lib, "winmm.lib") // timeGetTime 함수 사용

void PrimesSerial(); // C3861'identifier': identifier not found 오류 방지
void PrimesParallel(); // C3861'identifier': identifier not found 오류 방지

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
	}); //  For문을 병렬처리하고자 하는 구문을 하나의 처리 문장으로 묶습니다.
	DWORD sum = timeGetTime() - start;
	cout << "PrimesParallel Time: " << sum << endl;
	return;
}