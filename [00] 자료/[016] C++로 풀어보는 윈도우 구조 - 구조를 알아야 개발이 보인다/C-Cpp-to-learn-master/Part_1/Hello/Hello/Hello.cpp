// Hello.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // stdio.h, tchar.h
#include <iostream> // c++ ǥ�� ����� ���̺귯��, std::cout�� ����

using namespace std;
/*
targetver.h
	SDKDDKVer.h
*/


bool main(int argc, char *argv[])
{
	printf("Hello, world\n"); // C ��� 

	cout << "C/C++" << endl; // C++ ���
	if (argc > 1)
	{
		for (int i = 0; argc > i; i++)
		{
			printf("C input count: %s Input value: %d \n", argv[i], i);
			cout << "C++ input count: " << i << " input value: " << argv[i] << "\n" << endl;
		}
	}
    return true;
}

