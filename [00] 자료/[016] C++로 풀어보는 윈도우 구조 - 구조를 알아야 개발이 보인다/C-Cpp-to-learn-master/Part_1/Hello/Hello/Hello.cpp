// Hello.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // stdio.h, tchar.h
#include <iostream> // c++ 표준 입출력 라이브러리, std::cout을 제공

using namespace std;
/*
targetver.h
	SDKDDKVer.h
*/


bool main(int argc, char *argv[])
{
	printf("Hello, world\n"); // C 언어 

	cout << "C/C++" << endl; // C++ 언어
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

