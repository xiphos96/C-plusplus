// 4-2-3.cpp

#include "4-2-2.h"	// 헤더 파일 포함

int a;			// 전역 변수 정의
static int b = 3;		// 정적 변수 정의
int f() { return ++a;  }
int g() { return ++b; }