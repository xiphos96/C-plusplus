// 2장의 실습 과제를 발전시킴
// pclaf의 ChildWindow 활용
#pragma once
#include "pclaf.h"

class PenApp : public Application
{
public:
	PenApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// data fields for pen locations
	int oldx = 0;
	int oldy = 0;
	int newx = 0;
	int newy = 0;
};
// Exer
class MyChild : public ChildWindow
{
public:
	MyChild(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// data fields
	int childX = 50;
	int childY = 50;
};