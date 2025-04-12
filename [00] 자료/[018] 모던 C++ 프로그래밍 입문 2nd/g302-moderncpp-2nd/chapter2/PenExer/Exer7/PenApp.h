// 실습 과제를 발전시킴
// 마우스 클릭 때마다 클릭점을 point.txt 파일에 저장
#pragma once
#include "pclaf.h"
#include <fstream>			// Exer

class PenApp : public Application
{
public:
	PenApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// data fields
	int oldx = 0;
	int oldy = 0;
	int newx = 0;
	int newy = 0;
	// Exer
	std::ofstream outStream;
};