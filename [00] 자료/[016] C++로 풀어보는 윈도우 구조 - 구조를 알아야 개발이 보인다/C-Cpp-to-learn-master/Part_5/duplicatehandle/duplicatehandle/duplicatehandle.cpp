// duplicatehandle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	HANDLE event = CreateEvent(nullptr, FALSE, FALSE, nullptr);

	HWND notepad = FindWindow(nullptr, L"notepad");
	DWORD pid;

	GetWindowThreadProcessId(notepad, &pid);

    return 0;
}

