// openprocess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" c

using namespace std;

int main(int argc, char *argv[])
{
	wchar_t i[2] = L"1";
	INT pid = (INT)i; //���ڰ� string�� int�� ��ȯ�մϴ�.

	HANDLE hproc = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);

	cout << "Process HANDLE: " << hproc << endl;
	cout << "We will kill this Porcess"<< endl;	

	TerminateProcess(hproc, 0); // ������ �ڵ��� �̿��Ͽ� ���μ����� �����մϴ�.

	system("pause");
    return 0;
}

