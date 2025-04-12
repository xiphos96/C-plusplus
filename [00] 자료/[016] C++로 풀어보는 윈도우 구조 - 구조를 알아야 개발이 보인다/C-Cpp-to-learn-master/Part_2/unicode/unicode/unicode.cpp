// unicode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{

	HANDLE hFile = CreateFile(_T("C:\\unicode.txt"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, 0);
	CloseHandle(hFile);

    return 0;
}
