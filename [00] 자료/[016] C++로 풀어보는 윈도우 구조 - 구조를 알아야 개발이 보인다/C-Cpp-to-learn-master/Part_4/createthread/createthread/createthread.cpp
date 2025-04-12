// createthread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <Windows.h> #include <iostream> �߰�

using namespace std;

void ThreadSpeed(); // �ĺ��� ����

#pragma comment(lib, "winmm.lib") 
#pragma comment(linker, "/STACK:16777216,16777216")

const int sumcount = 100;

struct ThreadSUM {
	int count = 0;
};

int main()
{
	bool cont = true; // while ���� �������� ������ �� ����
	int maxthread = 1;
	int whilecount = 1;
	ThreadSUM data[sumcount]; //ThreadSUM ����ü�� �̿��� 

	while (cont == true)
	{

		HANDLE thread[sumcount]; // ���� ���� �ڵ��� �ϳ��� �����ϱ� ���� �迭������ �����մϴ�.
		DWORD start = timeGetTime();  //�����ϴ� �ð��� ����մϴ�.

		for (int numthread = 0; maxthread > numthread; numthread++) //������ ���� ������ 1�� �÷����鼭 �����ϵ��� �����մϴ�.
		{
			int stacksize = 16 << 20; // ��° �����ڿ� ������ ��Ʈ �� ��ŭ ù° �����ڸ� ��Ʈ ������ �������� �̵��մϴ�.
			cout << "Stack size: " << stacksize << endl;

			thread[numthread] = CreateThread(NULL, stacksize, (LPTHREAD_START_ROUTINE)ThreadSpeed, NULL, STACK_SIZE_PARAM_IS_A_RESERVATION, NULL); //�����带 �����մϴ�.


		}
		WaitForMultipleObjects(maxthread, thread, true, INFINITE); // �������� ��ü�� ���Ḧ ��ٸ��ϴ�.

		DWORD sum = timeGetTime() - start; // �۾��� ���������� �ð��� ����Ͽ� ���̸� ���մϴ�.
		CloseHandle(thread);


		if (sum > 0) // ���� 0 ���� ���� �ɷȴٸ�, �����Ǵ� ������ �Ǵ��Ͽ� ����� �����ݴϴ�.
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
			maxthread = 1; // �����Ǿ��ٸ� �ٽ� ó������ �����մϴ�.
		}
		else // �׷��� ���� ��� �ִ� ���� ������ �����Ͽ� �ٽ� �����ϵ��� �մϴ�.
		{
			maxthread++;
		}

		maxthread++;
		if (whilecount == sumcount) //whilecount�� sumcount ��ŭ ������ �� �ֵ��� �մϴ�.
		{
			cont = false; // while �� ����
		}
		else
		{
			whilecount++;
		}
	}
	system("pause");
	for (int i = 0; sumcount > i; i++)
	{
		if (data[i].count != 0) // ������ ���� ���� �����ʹ� ǥ������ �ʵ��� �մϴ�.
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
