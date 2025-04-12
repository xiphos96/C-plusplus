// memorymapfile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // #include <windows.h> #include <iostream> �߰�

using namespace std;
int main()
{
	HANDLE h_File = CreateFile(L"C:\\Code\\Part_6\\mmf.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, nullptr, OPEN_ALWAYS, 0 , nullptr); // ���� ���� �ڵ��� ����ϴ�.
	HANDLE h_Memfile = CreateFileMapping(h_File, nullptr, PAGE_READWRITE, 0, 1 << 20, L"ShareMMF"); // �޸� �� ������ �����մϴ�. �׸��� ���� ���� �ڵ��� �ֽ��ϴ�.
	
	if (h_File != INVALID_HANDLE_VALUE) 
	{
		CloseHandle(h_File); // ���� �ڵ��� �ݽ��ϴ�.
	}
	while (true)
	{
		char input;
		cout << "mmf use share memory (i to input message, d to display message, q to exit): ";
		cin >> input;
		if (input == 'i')
		{
			char* c_mPointer = (char*)MapViewOfFile(h_Memfile, FILE_MAP_WRITE, 0, 0, 1 << 16); // �޸� �� ���� �����͸� �����ɴϴ�.
			cout << "message input: ";
			cin >> c_mPointer;
			UnmapViewOfFile(c_mPointer); // ������ �����͸� ���� �մϴ�.
		}
		else
		{
			if (input == 'q')
			{
				break;
			}
			if (input == 'd')
			{
				char* c_mPointer = (char*)MapViewOfFile(h_Memfile, FILE_MAP_WRITE, 0, 0, 1 << 16); // �޸� �� ���� �����͸� �����ɴϴ�.
				cout << "share message: " << c_mPointer << endl; // �������� ������ Ȯ���մϴ�.
				UnmapViewOfFile(c_mPointer);
			}
		}
	}
    return 0;
}

