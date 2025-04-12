// createmutex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // stdafx.h�� #include <windows.h> #include <iostream> 

using namespace std;

int main()
{
	char test[256];
	HANDLE mutex = CreateMutex(nullptr, FALSE, L"MutexTEST"); // ���ý��� �����մϴ�. ���� ���ؽ��� �����Ͽ��ٸ� ���ؽ��� �ڽſ��� �Ҵ��մϴ�.
	cout << "press any key to start Process ID :" << GetCurrentProcessId() << endl;
	system("pause");
	cout << "Running..." << endl;

	for (int i = 0; i < 1000; i++ )
	{
		sprintf_s (test, "Write Process :%d\r\n" , GetCurrentProcessId());
		
		WaitForSingleObject(mutex, INFINITE); // ���ؽ� ���� �ñ׳��� �� ������ ����մϴ�.
		HANDLE file = CreateFile(L"C:\\Code\\Part_4\\test.txt", GENERIC_WRITE, FILE_SHARE_READ, 0, OPEN_ALWAYS, 0, 0); // ������ ���� ���� ���� �ڵ��� �����ɴϴ�.

		if (file == INVALID_HANDLE_VALUE) // �ڵ��� �������µ� �����Ͽ��� ��� �����ڵ带 ����ϵ��� �մϴ�.
		{
			cout << "Error code :" << GetLastError() << endl;
			system("pause");
			return 0;
		}

		SetFilePointer(file, GetFileSize(file, NULL), NULL, FILE_BEGIN); // ������ ��� ���� ���� ũ�⸦ Ȯ���մϴ�.
		DWORD bytes;
		WriteFile(file, test, strlen(test), &bytes, NULL); // ���Ͽ� �Է��� ���ڿ� test�� ���ϴ�.
		CloseHandle(file);
		ReleaseMutex(mutex); // �Ҵ��� ���ؽ��� �����մϴ�.
	}

	cout << "Done..." << endl;
	CloseHandle(mutex); // ���ؽ��� �����մϴ�. 
	system("pause");
    return 0;
}

