// memorymapfile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <windows.h> #include <iostream> 추가

using namespace std;
int main()
{
	HANDLE h_File = CreateFile(L"C:\\Code\\Part_6\\mmf.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, nullptr, OPEN_ALWAYS, 0 , nullptr); // 파일 생성 핸들을 얻습니다.
	HANDLE h_Memfile = CreateFileMapping(h_File, nullptr, PAGE_READWRITE, 0, 1 << 20, L"ShareMMF"); // 메모리 맵 파일을 생성합니다. 그리고 파일 생성 핸들을 넣습니다.
	
	if (h_File != INVALID_HANDLE_VALUE) 
	{
		CloseHandle(h_File); // 파일 핸들을 닫습니다.
	}
	while (true)
	{
		char input;
		cout << "mmf use share memory (i to input message, d to display message, q to exit): ";
		cin >> input;
		if (input == 'i')
		{
			char* c_mPointer = (char*)MapViewOfFile(h_Memfile, FILE_MAP_WRITE, 0, 0, 1 << 16); // 메모리 맵 파일 포인터를 가져옵니다.
			cout << "message input: ";
			cin >> c_mPointer;
			UnmapViewOfFile(c_mPointer); // 가져온 포인터를 해제 합니다.
		}
		else
		{
			if (input == 'q')
			{
				break;
			}
			if (input == 'd')
			{
				char* c_mPointer = (char*)MapViewOfFile(h_Memfile, FILE_MAP_WRITE, 0, 0, 1 << 16); // 메모리 맵 파일 포인터를 가져옵니다.
				cout << "share message: " << c_mPointer << endl; // 포인터의 내용을 확인합니다.
				UnmapViewOfFile(c_mPointer);
			}
		}
	}
    return 0;
}

