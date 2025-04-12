// createthread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> 추가

using namespace std;

void ThreadSpeed(); // 식별자 선언

#pragma comment(lib, "winmm.lib") 
#pragma comment(linker, "/STACK:16777216,16777216")

const int sumcount = 100;

struct ThreadSUM {
	int count = 0;
};

int main()
{
	bool cont = true; // while 문을 실행할지 정지할 지 결정
	int maxthread = 1;
	int whilecount = 1;
	ThreadSUM data[sumcount]; //ThreadSUM 구조체를 이용한 

	while (cont == true)
	{

		HANDLE thread[sumcount]; // 여러 개의 핸들을 하나로 관리하기 위해 배열구조로 선언합니다.
		DWORD start = timeGetTime();  //시작하는 시간을 기록합니다.

		for (int numthread = 0; maxthread > numthread; numthread++) //스레드 생성 갯수를 1씩 올려가면서 생성하도록 구성합니다.
		{
			int stacksize = 16 << 20; // 둘째 연산자에 지정한 비트 수 만큼 첫째 연산자를 비트 단위로 왼쪽으로 이동합니다.
			cout << "Stack size: " << stacksize << endl;

			thread[numthread] = CreateThread(NULL, stacksize, (LPTHREAD_START_ROUTINE)ThreadSpeed, NULL, STACK_SIZE_PARAM_IS_A_RESERVATION, NULL); //스레드를 생성합니다.


		}
		WaitForMultipleObjects(maxthread, thread, true, INFINITE); // 여러개의 객체의 종료를 기다립니다.

		DWORD sum = timeGetTime() - start; // 작업을 맞쳤을때의 시간을 계산하여 차이를 구합니다.
		CloseHandle(thread);


		if (sum > 0) // 만약 0 보다 오래 걸렸다면, 지연되는 것으로 판단하여 결과를 보여줍니다.
		{
			cout << "Create Thread Done: " << maxthread << endl;
			cout << "Current Create Time: " << sum << endl;

			for (int i = 0; sumcount > i; i++)
			{
				if (i == maxthread)
				{
					data[i].count = data[i].count + 1;
				}
			}
			maxthread = 1; // 지연되었다면 다시 처음부터 진행합니다.
		}
		else // 그렇지 않은 경우 최대 생성 개수를 증가하여 다시 생성하도록 합니다.
		{
			maxthread++;
		}

		maxthread++;
		if (whilecount == sumcount) //whilecount가 sumcount 만큼 실행할 수 있도록 합니다.
		{
			cont = false; // while 문 종료
		}
		else
		{
			whilecount++;
		}
	}
	system("pause");
	for (int i = 0; sumcount > i; i++)
	{
		if (data[i].count != 0) // 저장이 되지 않은 데이터는 표시하지 않도록 합니다.
		{
			cout << "Create Thread: " << i << endl;
			cout << "Result Count: " << data[i].count << endl;
		}
	}
	system("pause");
	return 0;
}

void ThreadSpeed()
{
	cout << "Create ThreadSpeed Func" << endl;

	system("pause");
	return;
}
