// createmutex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // stdafx.h에 #include <windows.h> #include <iostream> 

using namespace std;

int main()
{
	char test[256];
	HANDLE mutex = CreateMutex(nullptr, FALSE, L"MutexTEST"); // 뮤택스를 생성합니다. 만약 뮤텍스를 생성하였다면 뮤텍스를 자신에게 할당합니다.
	cout << "press any key to start Process ID :" << GetCurrentProcessId() << endl;
	system("pause");
	cout << "Running..." << endl;

	for (int i = 0; i < 1000; i++ )
	{
		sprintf_s (test, "Write Process :%d\r\n" , GetCurrentProcessId());
		
		WaitForSingleObject(mutex, INFINITE); // 뮤텍스 해제 시그널이 올 때까지 대기합니다.
		HANDLE file = CreateFile(L"C:\\Code\\Part_4\\test.txt", GENERIC_WRITE, FILE_SHARE_READ, 0, OPEN_ALWAYS, 0, 0); // 파일을 쓰기 위해 파일 핸들을 가져옵니다.

		if (file == INVALID_HANDLE_VALUE) // 핸들을 가져오는데 실패하였을 경우 오류코드를 출력하도록 합니다.
		{
			cout << "Error code :" << GetLastError() << endl;
			system("pause");
			return 0;
		}

		SetFilePointer(file, GetFileSize(file, NULL), NULL, FILE_BEGIN); // 파일을 열어서 현재 사용된 크기를 확인합니다.
		DWORD bytes;
		WriteFile(file, test, strlen(test), &bytes, NULL); // 파일에 입력한 문자열 test를 씁니다.
		CloseHandle(file);
		ReleaseMutex(mutex); // 할당한 뮤텍스를 해제합니다.
	}

	cout << "Done..." << endl;
	CloseHandle(mutex); // 뮤텍스를 해제합니다. 
	system("pause");
    return 0;
}

