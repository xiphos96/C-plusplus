//=================================================================
// ���� ���� 3
// �ǽ� ������ ������Ŵ
// �� ���� ������ ����
//=================================================================
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