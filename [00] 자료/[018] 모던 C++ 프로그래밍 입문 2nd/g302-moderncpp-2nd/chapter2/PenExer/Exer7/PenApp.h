// �ǽ� ������ ������Ŵ
// ���콺 Ŭ�� ������ Ŭ������ point.txt ���Ͽ� ����
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