// openprocess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" c

using namespace std;

int main(int argc, char *argv[])
{
	wchar_t i[2] = L"1";
	INT pid = (INT)i; //인자값 string을 int로 변환합니다.

	HANDLE hproc = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);

	cout << "Process HANDLE: " << hproc << endl;
	cout << "We will kill this Porcess"<< endl;	

	TerminateProcess(hproc, 0); // 가져온 핸들을 이용하여 프로세스를 종료합니다.

	system("pause");
    return 0;
}

